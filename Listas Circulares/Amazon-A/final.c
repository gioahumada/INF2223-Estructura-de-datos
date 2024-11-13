#include <stdio.h>

struct Usuario {
    int id;
    char *nombre;
    struct NodoProducto *carrito;
    char **boletas;
};

struct NodoUsuarios { /* Lista circular Doblemente Enlazada */
    struct Usuario *usuario;
    struct NodoUsuarios *ant, *sig;
};

struct Producto {
    int id;
    char *nombre;
    float precio;
};

struct NodoProductos { /* Lista doblemente Enlazada */
    struct Producto *producto;
    struct NodoProductos *ant, *sig;
};

struct Amazonas {
    struct NodoUsuarios *usuarios;
    struct NodoProductos *productos;
};

struct Usuario *usuarioCarritoMasGrande(struct Amazonas *amazonas) {
    struct Usuario *usuarioMax = NULL;
    struct NodoUsuarios *rec;
    struct NodoProductos *recPro;
    int maxItems = 0, items;
    
    if (amazonas == NULL || amazonas->usuarios == NULL) {
        return NULL;
    }

    rec = amazonas->usuarios;
    do {
        items = 0;
        recPro = rec->usuario->carrito;
        while(recPro != NULL) {
            items++;
            recPro = recPro->sig;
        }
        if (items > maxItems) {
            maxItems = items;
            usuarioMax = rec->usuario;
        }

        rec = rec->sig;
        
    } while (rec != amazonas->usuarios);

    return usuarioMax;
}

float promedioPrecioProductos(struct Amazonas *amazonas) {
    struct NodoProductos *rec;
    float promedio = 0;
    int cantidad = 0;

    if (amazonas == NULL || amazonas->productos == NULL) {
        return 0;
    }

    rec = amazonas->productos;
    while (rec != NULL){
        promedio += rec->producto->precio;
        cantidad++;
        rec = rec->sig;
    }

    return promedio / cantidad;
}

/* Ejercicio propuesto */

void recorrerBoletas(struct Amazonas *amazonas) {
    struct NodoUsuarios *rec;
    int i;

    if (amazonas == NULL || amazonas->usuarios == NULL) {
        return;
    }

    rec = amazonas->usuarios;
    do {
        if (rec->usuario->nombre != NULL) {
            printf("Usuario: %s\n", rec->usuario->nombre);
        } else {
            printf("Usuario sin nombre.\n");
        }

        if (rec->usuario->boletas != NULL) {
            for (i = 0; rec->usuario->boletas[i] != NULL; i++) {
                printf("Boleta: %s\n", rec->usuario->boletas[i]);
            }
        } else {
            printf("El usuario no tiene boletas registradas.\n");
        }

        rec = rec->sig;

    } while (rec != amazonas->usuarios);  
}



int main() {
    struct Amazonas *amazonas = malloc(sizeof(struct Amazonas));

    return 0;
}