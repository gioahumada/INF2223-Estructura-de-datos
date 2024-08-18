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

struct Piloto *asignarPilotoScuderia(struct Formula1 *f1, int idPilotoSaliente, int idPilotoEntrante) {
    /* Codigo a desarrollar */
    /* Codigo a desarrollar */
    /* Codigo a desarrollar */
    /* Codigo a desarrollar */
    
}

int main() {

}

