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

int cantGolesMundiales(struct Fifa *fifa) {
    /* CODIGO ACA */
    /* CODIGO ACA */
    /* CODIGO ACA */
    /* CODIGO ACA */
}

struct Equipo *equipoMasGoles(struct Competicion *competicion) {
    /* CODIGO ACA */
    /* CODIGO ACA */
    /* CODIGO ACA */
    /* CODIGO ACA */
}


