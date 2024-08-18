#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 46352

struct Loteria {
    struct Cliente **clientes;
    char *pais;
};

struct Cliente {
    char *nombre;
    char *apellido;
    int edad;
    struct Carton **comprados;
    int pLibre;
};

struct Carton {
    char tipoSorteo;
    char *numSorteo;
    int dia;
    int mes;
    int anio;
};

int verificarGanador(struct Loteria *kino, char *numGanador, char *nombre, char *apellido) {
    /* Funcion a crear */
    /* Funcion a crear */
    /* Funcion a crear */
}

int main() {
    struct Loteria *kino;
}