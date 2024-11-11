struct Medalla{
    int id;
    char *nombre;
    char *categoria;
};

struct NodoMedalla{
    struct Medalla *detalle;
    struct NodoMedalla *sig;
};

struct Jugador{
    int id;
    char *nombre;
    int edad;
    struct Medalla **medallas; //Arreglo no compacto
};

struct NodoJugador{
    struct Jugador *jugador;
    struct NodoJugador *enlace1, *enlace2; //En un árbol enlace1=inzquierda, enlace2=derecha; en una lista doble enlace1=ante y enlace2=sig.
};

struct SistemaJuegos{
    struct NodoJugador *jugadores; //ABB
    struct NodoMedalla *medallas; //Lista simple circular con tail
};


Implemente:

struct Jugador *jugadorConMasMedallas(struct SistemaJuegos *ps5);

// Recibe por parámetro un puntero al sistema de juegos y deberá retornar el jugador que tiene la mayor cantidad de medallas. Asuma que sólo existe un mayor. 
// En caso de fracaso retorna NULL. No puede asumir una variable "mayor = 0". No puede hacer cambios en la definición de los structs.
