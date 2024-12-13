#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Despacho {
    int numero;
    float valor;
    int tiempo;
    struct Cliente *cliente;
};

struct Cliente {
    int idCliente;
    char *nombre;
    char *direccion;
    char *pais;
};

struct NodoCliente { /* Arbol Binario de Busqueda */
    struct Cliente *cliente;
    struct NodoCliente *izq, *der;
};

struct Producto {
    int id;
    char *nombre;
    char *categoria;
    int pLibre;
    int maxPedidos;
    struct Despacho **despachos;
};

struct NodoProducto { /* Lista simplemente Enlazada c/ Nodo Fantasma */
    struct Producto *producto;
    struct NodoProducto *sig;
};

struct Fabrica {
    int id;
    char *encargado;
    char *direccion;
    char *especialidad;
    struct NodoProducto *productos;
};

struct NodoFabrica { /* Lista Circular c/ Nodo Fantasma */
    struct Fabrica *fabrica;
    struct NodoFabrica *sig;
};

struct FabricaDeSanta {
    struct NodoCliente *clientes;
    struct NodoFabrica *fabricas;
};

// Faltan verificaciones de si es null o no

int encontrarClienteFabrica(struct Fabrica *fabrica, int idCliente) {
    struct NodoProducto *act = fabrica->productos;
    int i;
    
    while (act != NULL) {
        for (i = 0; i < act->producto->maxPedidos; i++) {
            if (act->producto->despachos[i]->cliente->idCliente == idCliente) {
                return 1;
            }
        }
        act = act->sig;
    }
    return 0;
}

int buscarEnFabricas(int idCliente, struct FabricaDeSanta *jojojo) {
    struct NodoFabrica *act = jojojo->fabricas->sig;
    int cont = 0;

    do {
        if (encontrarClienteFabrica(act->fabrica, idCliente)) {
            cont++;
        }
        act = act->sig;
    } while (act != jojojo->fabricas);
    return cont;
}

void recorrerArbol(struct NodoCliente *act, struct FabricaDeSanta *jojojo, struct Cliente **grinch, int *mas) {
    int num;
    if (act != NULL) {
        recorrerArbol(act->izq, jojojo, grinch, mas);
        num = buscarEnFabricas(act->cliente->idCliente, jojojo);
        if (num > *mas) {
            *mas = num;
            *grinch = act->cliente;
        }
        recorrerArbol(act->der, jojojo, grinch, mas);
    }
}

struct Cliente *buscarAGrinch(struct FabricaDeSanta *jojojo) {
    if (jojojo == NULL || jojojo->clientes == NULL) {
        return NULL;
    }

    struct NodoCliente *act = jojojo->clientes;
    struct Cliente *grinch = NULL;
    int mas = 0;

    recorrerArbol(act, jojojo, &grinch, &mas);

    return grinch;
}

float calcularPromedioPedidos(struct FabricaDeSanta *jojojo) {
    if (jojojo == NULL || jojojo->clientes == NULL) {
        return 0;
    }

    struct NodoFabrica *act = jojojo->fabricas->sig;
    struct NodoProducto *productoActual;
    float valorTotal = 0;

    int contFabricas = 0;
    float valorFabrica;

    do {
        valorFabrica = 0;
        productoActual = act->fabrica->productos->sig;

        while(productoActual != NULL) {
            for (int i = 0; i < productoActual->producto->maxPedidos; i++) {
                valorFabrica += productoActual->producto->despachos[i]->valor;
            }
            productoActual = productoActual->sig;
        }

        valorTotal += valorFabrica;
        contFabricas++;
        act = act->sig;
    } while (act != jojojo->fabricas);

    if (contFabricas == 0) {
        return 0;
    }

    return valorTotal / contFabricas;
}

int contarFabricasCriticas(struct FabricaDeSanta *jojojo, float promedio, int idGrinch) {
    struct NodoFabrica *act = jojojo->fabricas->sig;
    struct NodoProducto *productoActual;
    float valorFabrica;
    int grinchesPidieron;

    int contFabricasCriticas = 0;

    do {
        valorFabrica = 0;
        grinchesPidieron = 0;
        productoActual = act->fabrica->productos->sig;

        while(productoActual != NULL) {
            for (int i = 0; i < productoActual->producto->maxPedidos; i++) {
                if (productoActual->producto->despachos[i]->cliente->idCliente == idGrinch) {
                    grinchesPidieron = 1;
                }
                valorFabrica += productoActual->producto->despachos[i]->valor;
            }
            productoActual = productoActual->sig;
        }

        if (valorFabrica > promedio && grinchesPidieron) {
            contFabricasCriticas++;
        }

        act = act->sig;
    } while (act != jojojo->fabricas);

    return contFabricasCriticas;
}

struct Fabrica **identificarFabricasCriticas(struct FabricaDeSanta *jojojo) {
    if (!jojojo || !jojojo->fabricas) return NULL;

    struct Cliente *grinch = buscarAGrinch(jojojo);
    if (!grinch) return NULL;

    float promedio = calcularPromedioPedidos(jojojo);

    int contFabricasCriticas = contarFabricasCriticas(jojojo, promedio, grinch->idCliente);
    if (contFabricasCriticas == 0) return NULL;

    struct Fabrica **fabricasCriticas = malloc(sizeof(struct Fabrica *) * contFabricasCriticas);

    struct NodoFabrica *act = jojojo->fabricas->sig;
    int pLibre = 0;

    do {
        float valorFabrica = 0;
        int grinchPidio = 0;

        struct NodoProducto *productoActual = act->fabrica->productos->sig;
        while(productoActual != NULL) {
            struct Producto *producto = productoActual->producto;
            for (int i = 0; i < producto->maxPedidos; i++) {
                if (producto->despachos[i]->cliente->idCliente == grinch->idCliente) {
                    grinchPidio = 1;
                }
                valorFabrica += producto->despachos[i]->valor;
            }
            productoActual = productoActual->sig;
        }

        if (valorFabrica > promedio && grinchPidio) {
            fabricasCriticas[pLibre] = act->fabrica;
        }
    } while (act != jojojo->fabricas);

    return fabricasCriticas;

}