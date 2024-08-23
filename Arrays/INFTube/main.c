#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10000
#define MAX_ADMINS 20

#define MAX_A 1000
#define MAX_B 500
#define MAX_C 50

struct Video {
    int id;
    char *nombreVideo;
    char *fechaPublicacion;
    char *tipoContenido;
    int segundos;
    int minutos;
    int comentarios;
    char *estadoVideo;
};

struct Usuario {
    int id;
    char *username;
    char tipoCuenta;
    struct Video **videosSubidos;
    int cantVideosSubidos;
    int infracciones;
};

struct Admin {
    int id;
    char *username;
    int nivelAcceso; 
    struct Video **videosModerados; 
    int cantVideosModerados;
};

struct INFTube {
    struct Usuario **usuarios;
    struct Admin **administradores;
};


void quitarVideosInfraccion(struct INFTube *itube) {
    /* Codigo Aqui */
    /* Codigo Aqui */
    /* Codigo Aqui */
    /* Codigo Aqui */
}

int main() {
    struct INFTube *itube;
}