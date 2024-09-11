#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Jugador {
    char *nombre;
    int edad;
    char *pais;
    char *posicion;
    int numero;
    int cantGoles;
};

struct NodoJugador { /* Lista Simple */
    struct Jugador *jugador;
    struct NodoJugador *sig;
};

struct Equipo { 
    char *nombre;
    char *pais;
    struct NodoJugador *jugadores;
};

struct NodoEquipo { /* Lista Circular */
    struct Equipo *equipo;
    struct NodoEquipo *sig;
    struct NodoEquipo *ant;
};

struct Competicion {
    char *nombre;
    struct NodoEquipo *equipos;
};

struct NodoCompeticion { /* Lista Simple */
    struct Competicion *competicion;
    struct NodoCompeticion *sig;
};

struct Fifa {
    struct NodoCompeticion *competiciones;
};

int cantGolesEquipo(struct Equipo *equipo) {
    int cantGoles = 0;
    struct NodoJugador *rec = equipo->jugadores;
    
    while (rec != NULL) {
        cantGoles += rec->jugador->cantGoles;
        rec = rec->sig;
    }
    return cantGoles;
}

int cantGolesCompeticion(struct Competicion *competicion) {
    int cantGoles = 0;
    struct NodoEquipo *rec = competicion->equipos;
    do {
        cantGoles += cantGolesEquipo(rec->equipo);
        rec = rec->sig;
    } while (rec != competicion->equipos);
    return cantGoles;
}

int cantGolesMundiales(struct Fifa *fifa) {
    int cantGoles = 0;
    struct NodoCompeticion *rec = fifa->competiciones;

    while (rec != NULL) {
        cantGoles += cantGolesCompeticion(rec->competicion);
        rec = rec->sig;
    }

    return cantGoles;
}

struct Equipo *equipoMasGoles(struct Competicion *competicion) {
    struct NodoEquipo *rec = competicion->equipos;
    struct Equipo *equipoMasGoles = rec->equipo;
    int maxGoles = cantGolesEquipo(equipoMasGoles);

    rec = rec->sig;
    while (rec != competicion->equipos) {
        int cantGoles = cantGolesEquipo(rec->equipo);
        if (cantGoles > maxGoles) {
            maxGoles = cantGoles;
            equipoMasGoles = rec->equipo;
        }
        rec = rec->sig;
    }

    return equipoMasGoles;
}


