// Control 2.
#include <stdio.h>
#include <stdlib.h>

// Structs Originales.
struct BandaCriminal{
    char *nombre;
    struct NodoLadron *headLadrones;
    struct NodoBanco *headBancos;
};
struct NodoLadron{
    struct Ladron *datosLadron;
    struct NodoLadron *sig;
};
struct NodoBanco{
    struct Banco *datosBanco;
    struct NodoBanco *sig, *ant;
};
struct Ladron{
    char *apodo;
    char *rut;
    int maxRobos;
    struct Robo **robos;
    int pLibreRobos;
};

struct Banco{
    char *nombre;
    char *direccion;
    int saldo;
};

struct Robo{
    char *fecha;
    int monto;
    struct Banco *bancoRobado;
};

int recorrerLadron(struct NodoLadron *ladronesRecorridos, struct NodoBanco *banco){
    struct NodoLadron * rec = ladronesRecorridos;
    int robosDelBanco = 0;
    
    if(){}

    return robosDelBanco;
}

int recorrerBancos(struct NodoBanco *bancosRecorridos) {
    struct NodoBanco * rec = bancosRecorridos;
    if(bancosRecorridos != null) {
        while(rec->sig != null) {
        
            
        }
    }
    
}


struct NodoBanco * getBancosMasRobados(struct BandaCriminal *losCareNodo){
  struct NodoBanco *recListaBancos = losCareNodo->headBancos;
  struct NodoBanco *bancosMasRobados;

  
  if(losCareNodo != NULL) {
    while(


    return bancosMasRobados;
    
  } else {
      return NULL;
  }
}



int main(void) {
    struct BandaCriminal losCareNodo;
    printf("congrats, at least u reached the main function lmao.");
}
