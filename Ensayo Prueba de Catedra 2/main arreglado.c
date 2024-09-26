#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxVentas 3000
#define MaxProductos 3000

struct Juaguey {
  char *nombreGerente;
  struct NodoProducto * headProductos;
  struct NodoSucursal * headSucursales;
};

struct NodoProducto {
// Lista Circular
  struct Producto * producto;
  struct NodoProducto * sig;
};

struct Producto {
  int codigo;
  char *nombre;
  float valor;
  char *tipo;

};

struct NodoSucursal {
  struct NodoSucursal *ant, *sig;
  struct Sucursal *sucursal;
};

struct Sucursal {
  int id;
  char *pais;
  char *encargado;
  struct Venta ** ventas;

};

struct Venta{
  int codigo;
  char *fecha;
  struct Producto **productos;
};

float calcularValorSucursal(struct Sucursal *sucursal) {
    float totalValor = 0.0; // Variable para almacenar el valor total
    int i, j;

    // Verificamos si la sucursal es NULL
    if (sucursal == NULL || sucursal->ventas == NULL) {
        return totalValor; // Retornamos 0 si no hay ventas
    }

    // Iteramos sobre las ventas de la sucursal
    for (i = 0; i < MaxVentas; i++) {
        if (sucursal->ventas[i] == NULL) {
            break; // Si encontramos un puntero NULL, salimos del bucle
        }

        // Iteramos sobre los productos en cada venta
        for (j = 0; j < MaxProductos; j++) {
            if (sucursal->ventas[i]->productos[j] == NULL) {
                break; // Si encontramos un puntero NULL, salimos del bucle
            }

            // Acumulamos el valor de cada producto
            totalValor += sucursal->ventas[i]->productos[j]->valor;
        }
    }

    return totalValor; // Retornamos el valor total calculado
}

struct Sucursal * quitarSucursalConMenosVentas(struct Juaguey * HW) {
  struct NodoSucursal *rec = HW->headSucursales;
  struct NodoSucursal *sucursalMenosVentas = NULL;
  float menorVenta = -1;
  float totalVenta;
  struct Sucursal *eliminar = NULL;

  if (HW == NULL || HW->headSucursales == NULL) {
    return NULL;
  }
  
  while(rec != NULL) {
    totalVenta = calcularValorSucursal(rec->sucursal);

    if(menorVenta == -1 || totalVenta < menorVenta) {
      sucursalMenosVentas = rec;
      menorVenta = totalVenta;
    }
    rec = rec->sig;
  }
  if(sucursalMenosVentas->ant != NULL){
    sucursalMenosVentas->ant->sig = sucursalMenosVentas->sig;
  } else {
    HW->headSucursales = sucursalMenosVentas->sig;
    HW->headSucursales->ant = NULL;
  }

  if(sucursalMenosVentas->sig != NULL){
    sucursalMenosVentas->sig->ant = sucursalMenosVentas->ant;
    
  } // el rec esta equivocado corregir post clase.

  eliminar = sucursalMenosVentas->sucursal;
  
  return eliminar;

} // Cierre de funcion

int main(void) {
  
}
