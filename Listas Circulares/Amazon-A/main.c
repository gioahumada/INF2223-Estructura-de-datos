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
    struct NodoUsuarios *currentUser = amazonas->usuarios;
    struct Usuario *maxUser = NULL;
    int maxCartSize = 0;

    while (currentUser != NULL) {
        int cartSize = 0;
        struct NodoProductos *currentProduct = currentUser->usuario->carrito; // Suponiendo que 'carrito' es una lista de productos
        while (currentProduct != NULL) {
            cartSize++;
            currentProduct = currentProduct->sig;
        }
        if (cartSize > maxCartSize) {
            maxCartSize = cartSize;
            maxUser = currentUser->usuario;
        }
        currentUser = currentUser->sig;
    }

    return maxUser;
}

float promedioPrecioProductos(struct Amazonas *amazonas) {
    struct NodoProductos *currentProduct = amazonas->productos;
    float totalPrice = 0.0;
    int totalProducts = 0;

    while (currentProduct != NULL) {
        totalPrice += currentProduct->producto->precio; // Suponiendo que 'precio' es un campo en 'Producto'
        totalProducts++;
        currentProduct = currentProduct->sig;
    }

    if (totalProducts == 0) {
        return 0.0;
    }

    return totalPrice / totalProducts;
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