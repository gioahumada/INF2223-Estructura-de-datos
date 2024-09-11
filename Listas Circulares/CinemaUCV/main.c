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

double promedioDuracionPeliculas(struct CadenaCines *cadena) {
    /* CODIGO ACA */
    /* CODIGO ACA */
    /* CODIGO ACA */
}
