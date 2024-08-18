#include <stdio.h>

struct Loteria {
    struct Carton **cartones; 
    int pLibre;
};

struct Carton {
    int numeroSorteo;
    int dia;
    int mes;
};

struct Carton *getCartonNumeroGanador(struct Loteria *loto, int numGanador) {
    int i;
    for(i = 0; i<loto->pLibre;i++) {
        if(loto->cartones[i] != NULL && loto->cartones[i]->numeroSorteo == numGanador) {
            return loto->cartones[i];
        }
    }
    return NULL;
}

int main() {
    struct Loteria *loto;
}