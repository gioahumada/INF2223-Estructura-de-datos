#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pelicula {
    char *titulo;
    int duracion; // en minutos
    char *genero;
    int clasificacion; // edad mínima recomendada
};

struct NodoPelicula { /* Lista Simple */
    struct Pelicula *pelicula;
    struct NodoPelicula *sig;
};

struct Sala { 
    int numero;
    struct NodoPelicula *peliculas;
};

struct NodoSala { /* Lista Circular */
    struct Sala *sala;
    struct NodoSala *sig;
    struct NodoSala *ant;
};

struct Cine {
    char *nombre;
    struct NodoSala *salas;
};

struct NodoCine { /* Lista Simple */
    struct Cine *cine;
    struct NodoCine *sig;
};

struct CadenaCines {
    struct NodoCine *cines;
};

int duracionTotalPeliculas(struct NodoPelicula *peliculas) {
    int totalDuracion = 0;
    while (peliculas != NULL) {
        totalDuracion += peliculas->pelicula->duracion;
        peliculas = peliculas->sig;
    }
    return totalDuracion;
}

int contarPeliculas(struct NodoPelicula *peliculas) {
    int totalPeliculas = 0;
    while (peliculas != NULL) {
        totalPeliculas++;
        peliculas = peliculas->sig;
    }
    return totalPeliculas;
}

int duracionTotalSalas(struct NodoSala *salas) {
    int totalDuracion = 0;
    struct NodoSala *recSala = salas;
    if (recSala != NULL) {
        do {
            totalDuracion += duracionTotalPeliculas(recSala->sala->peliculas);
            recSala = recSala->sig;
        } while (recSala != salas);
    }
    return totalDuracion;
}

int contarPeliculasSalas(struct NodoSala *salas) {
    int totalPeliculas = 0;
    struct NodoSala *recSala = salas;
    if (recSala != NULL) {
        do {
            totalPeliculas += contarPeliculas(recSala->sala->peliculas);
            recSala = recSala->sig;
        } while (recSala != salas);
    }
    return totalPeliculas;
}

double promedioDuracionPeliculas(struct CadenaCines *cadena) {
    int totalDuracion = 0;
    int totalPeliculas = 0;
    struct NodoCine *recCine = cadena->cines;

    while (recCine != NULL) {
        totalDuracion += duracionTotalSalas(recCine->cine->salas);
        totalPeliculas += contarPeliculasSalas(recCine->cine->salas);
        recCine = recCine->sig;
    }

    if (totalPeliculas == 0) {
        return 0.0; // Evitar división por cero
    }

    return (double)totalDuracion / totalPeliculas;
}
