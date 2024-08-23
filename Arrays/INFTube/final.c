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

void procesarVideosUsuario(struct Usuario *usuario) {
    int maxVideos = 0;
    switch (usuario->tipoCuenta) { /* Esto simplemente podria haber sido una sentencia de if */
        case 'A':
            maxVideos = MAX_A;
            break;
        case 'B':
            maxVideos = MAX_B;
            break;
        case 'C':
            maxVideos = MAX_C;
            break;
        default:
            return;
    }

    for (int i = 0; i < maxVideos; i++) { /* Este recorrido podria haber sido tmb con cantVideosSubidos */
        if (usuario->videosSubidos[i] != NULL && strcmp(usuario->videosSubidos[i]->estadoVideo, "Infraccion") == 0) {
            usuario->videosSubidos[i] = NULL;
            usuario->infracciones++;
        }
    }
}

void quitarVideosInfraccion(struct INFTube *itube) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (itube->usuarios[i] != NULL) {
            procesarVideosUsuario(itube->usuarios[i]);
            if (itube->usuarios[i]->infracciones > 3) {
                itube->usuarios[i] = NULL;
            }
        }
    }
}

int main() {
    struct INFTube *itube;
}