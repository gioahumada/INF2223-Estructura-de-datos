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

int verificarCarton(struct Cliente *client, char *numGanador, char *nombre, char *apellido) {
    int i;
    for(i = 0; i < client->pLibre; i++) {
        if(client->comprados[i] != NULL && strcmp(client->comprados[i]->numSorteo, numGanador) == 0) {
            if(client->comprados[i]->tipoSorteo == 'A') {
                if(strcmp(nombre, client->nombre) == 0 && strcmp(apellido, client->apellido) == 0)
                    return 1;
            }
        }
    }
    return 0;
}

int verificarGanador(struct Loteria *kino, char *numGanador, char *nombre, char *apellido) {
    int i;
    if(kino != NULL) {
        for(i = 0; i < MAX; i++) {
            if(kino->clientes[i] != NULL && verificarCarton(kino->clientes[i], numGanador, nombre, apellido)) 
                return 1;
        }
    }
    return 0;
}

int main() {
    struct Loteria *kino;
}