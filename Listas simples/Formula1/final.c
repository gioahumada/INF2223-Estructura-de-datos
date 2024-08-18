#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Piloto {
    int id;
    char *nombre;
    int edad;
    float sueldo;
};

struct NodoPiloto {
    struct Piloto *datosPiloto;
    struct NodoPiloto *ant, *sig;
};

struct Tecnico {
    char *nombre;
    int edad;
    char *especialidad;
};

struct Equipo {
    char *nombreJefe;
    int cantidadTecnicos;
    struct Tecnico **tecnicos;
    int pLibreTecnicos;
    struct Piloto *pilotos[3];
};

struct Scuderia {
    char *nombre;
    char *fechaCreacion;
    int campeonatosGanados;
    struct Equipo *equipo;
};

struct NodoScuderia {
    struct Scuderia *datosScuderia;
    struct NodoScuderia *sig;
};

struct Formula1 {
    struct NodoScuderia *headScuderia;
    struct NodoPiloto *headPiloto;
};

int buscarPiloto(struct NodoPilotos **head, int id) {
    struct NodoPiloto *rec = *head;
    if (rec != NULL) {
        do {
            if (rec->datosPiloto->id == id) return 1;
            rec = rec->sig;
        } while(rec != *head);
    }
    return 0;
}

struct Piloto *getPilotoBuscado(struct NodoPiloto **head, int id) {
    struct NodoPiloto *rec = *head;

    if(rec != NULL) {
        do {
            if(rec->datosPiloto->id == id) {
                return rec->datosPiloto;
            }
            rec = rec->sig;
        } while(rec != *head);
    }
    return NULL;
}

int quitarEntrante(struct NodoScuderia **head, struct Piloto *pilotoEntrante) {
    struct NodoScuderia *rec = (*head)->sig; /* Nodo Fantasma :) */
    int i;

    while(rec != NULL) {
        for(i = 0;i<3;i++) {
            if(rec->datosScuderia->equipo->pilotos[i] != NULL) {
                if(rec->datosScuderia->equipo->pilotos[i] == pilotoEntrante) {
                    rec->datosScuderia->equipo->pilotos[i] = NULL;
                    return 1;
                }
            }
        }
        rec = rec->sig;
    }
    return 0;
}

int remplazarPiloto(struct NodoScuderia **head, struct Piloto *pilotoEntrante, struct Piloto *pilotoSaliente) {
    struct NodoScuderia *rec = (*head)->sig;
    int i;

    while (rec != NULL) {
        for(i = 0; i<3;i++) {
            if(rec->datosScuderia->equipo->pilotos[i] != NULL && rec->datosScuderia->equipo->pilotos[i] == pilotoSaliente) {
                rec->datosScuderia->equipo->pilotos[i] = pilotoEntrante;
                return 1;
            }
        }
        rec = rec->sig;
    }

    return 0;
}

struct Piloto *asignarPilotoScuderia(struct Formula1 *f1, int idPilotoSaliente, int idPilotoEntrante) {
    struct Piloto *pilotoSaliente = NULL;
    struct Piloto *pilotoEntrante = NULL;

    if(buscarPiloto(f1->headPiloto, idPilotoSaliente) && buscarPiloto(f1->headPiloto, idPilotoEntrante) && idPilotoEntrante != idPilotoSaliente) {
        pilotoEntrante = getPilotoBuscado(f1->headPiloto, pilotoEntrante);
        pilotoSaliente = getPilotoBuscado(f1->headPiloto, pilotoSaliente);

        quitarEntrante(&f1->headScuderia, pilotoEntrante);
        remplazarPiloto(&f1->headScuderia, pilotoEntrante, pilotoSaliente);

        return pilotoSaliente;
    }

    return NULL;
}

int main() {

}

