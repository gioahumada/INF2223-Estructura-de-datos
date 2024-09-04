#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Producto {
    char *nombre;
    float precio;
    int cantidad;
};

struct NodoProducto {
    struct Producto *producto;
    struct NodoProducto *sig;
};

struct Tienda {
    char *nombre;
    char *direccion;
    struct NodoProducto *productos;
};

struct NodoTiendas {
    struct Tienda *tienda;
    struct NodoTiendas *sig;
};

struct ToysNUs {
    struct NodoTiendas *tiendas;
};

int revisarProductos(struct NodoTiendas *tiendas, char *productoPeligroso) {
    if (tiendas == NULL || tiendas->tienda == NULL || tiendas->tienda->productos == NULL) {
        return 0;
    }
    
    struct NodoProducto *rec = tiendas->tienda->productos;
    while (rec != NULL) {
        if (strcmp(rec->producto->nombre, productoPeligroso) == 0) {
            return 1;
        }
        rec = rec->sig;
    }
    return 0;
}

int eliminarTiendaProductoPeligroso(struct ToysNUs *tnu, char *productoPeligroso) {
    struct NodoTiendas *rec = tnu->tiendas;
    struct NodoTiendas *ant = NULL;

    while (rec != NULL) {
        if (revisarProductos(rec, productoPeligroso)) {
            if (ant == NULL) {
                tnu->tiendas = rec->sig;
            } else {
                ant->sig = rec->sig;
            }
            return 1;
        }
        ant = rec;
        rec = rec->sig;
    }

    return 0;
}

int main() {
    struct ToysNUs *tnu;
    return 0;
}