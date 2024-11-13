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
    /* CODIGO AQUI */
    /* CODIGO AQUI */
    /* CODIGO AQUI */
    /* CODIGO AQUI */
    /* CODIGO AQUI */
}

float promedioPrecioProductos(struct Amazonas *amazonas) {
    /* CODIGO AQUI */
    /* CODIGO AQUI */
    /* CODIGO AQUI */
    /* CODIGO AQUI */
    /* CODIGO AQUI */
}

/* Ejercicio propuesto */

void recorrerBoletas(struct Amazonas *amazonas) {
    /* CODIGO AQUI */
    /* CODIGO AQUI */
    /* CODIGO AQUI */
    /* CODIGO AQUI */
    /* CODIGO AQUI */
}



int main() {
    struct Amazonas *amazonas = malloc(sizeof(struct Amazonas));

    return 0;
}