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

int eliminarTiendaProductoPeligroso(struct ToysNUs *tnu, char *productoPeligroso) {
    /* CODIGO AQUI */
    /* CODIGO AQUI */
    /* CODIGO AQUI */
    /* CODIGO AQUI */
}

int main() {
    struct ToysNUs *tnu;
    return 0;
}