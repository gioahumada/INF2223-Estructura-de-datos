#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Persona {
    char *nombre;
    char *apellido;
    char *rut;
    char *ciudad;
    char *pais;
    char *fechaNacimiento;
};

struct NodoPersona { /* Lista Circular */
    struct Persona *persona;
    struct NodoPersona *sig;
    struct NodoPersona *ant;
};

struct RegistroCivil {
    struct NodoPersona *personas;
};

struct Persona *copiaPersonaRut(struct RegistroCivil *registro, char *rut) {
    struct NodoPersona *nodo = registro->personas;
    do {
        if (strcmp(nodo->persona->rut, rut) == 0) {
            struct Persona *persona = malloc(sizeof(struct Persona));
            persona->nombre = malloc(strlen(nodo->persona->nombre) + 1);
            persona->apellido = malloc(strlen(nodo->persona->apellido) + 1);
            persona->rut = malloc(strlen(nodo->persona->rut) + 1);
            persona->ciudad = malloc(strlen(nodo->persona->ciudad) + 1);
            persona->pais = malloc(strlen(nodo->persona->pais) + 1);
            persona->fechaNacimiento = malloc(strlen(nodo->persona->fechaNacimiento) + 1);

            strcpy(persona->nombre, nodo->persona->nombre);
            strcpy(persona->apellido, nodo->persona->apellido);
            strcpy(persona->rut, nodo->persona->rut);
            strcpy(persona->ciudad, nodo->persona->ciudad);
            strcpy(persona->pais, nodo->persona->pais);
            strcpy(persona->fechaNacimiento, nodo->persona->fechaNacimiento);

            return persona;
        }
        nodo = nodo->sig;
    } while (nodo != registro->personas);
    return NULL;
}

void eliminarPersonaRut(struct RegistroCivil *registro, char *rut) {
    if (registro->personas == NULL) {
        return; // La lista está vacía
    }

    struct NodoPersona *nodo = registro->personas;

    do {
        if (strcmp(nodo->persona->rut, rut) == 0) {
            if (nodo->sig == nodo) {
                // Es el único nodo en la lista
                registro->personas = NULL;
            } else {
                // Ajustar los punteros para excluir el nodo actual
                nodo->ant->sig = nodo->sig;
                nodo->sig->ant = nodo->ant;
                if (registro->personas == nodo) {
                    registro->personas = nodo->sig; // Actualizar el puntero de la lista si es necesario
                }
            }
            // No liberamos la memoria, solo desenlazamos
            nodo->sig = NULL;
            nodo->ant = NULL;
            nodo->persona = NULL;
            return;
        }
        nodo = nodo->sig;
    } while (nodo != registro->personas);
}