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

struct NodoPersona {
    struct Persona *persona;
    struct NodoPersona *sig;
    struct NodoPersona *ant;
};

struct RegistroCivil {
    struct NodoPersona *personas;
};

struct Persona *copiaPersonaRut(struct RegistroCivil *registro, char *rut) {
    /* CODIGO AQUI */
    /* CODIGO AQUI */
    /* CODIGO AQUI */
    /* CODIGO AQUI */
    /* CODIGO AQUI */
}

void eliminarPersonaRut(struct RegistroCivil *registro, char *rut) {
    /* CODIGO AQUI */
    /* CODIGO AQUI */
    /* CODIGO AQUI */
    /* CODIGO AQUI */
    /* CODIGO AQUI */
}