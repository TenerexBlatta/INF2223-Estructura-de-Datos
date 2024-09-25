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

struct Sucursal * quitarSucursalConMenosVentas(struct Juaguey * Hw) {
  struct NodoSucursal *rec = HW->headSucursales;
  struct NodoSucursal *sucursalMenosVentas = NULL;
  float menorVenta = -1;
  float totalVenta;
  struct Sucursal *eliminar = NULL;

  if (HW == NULL || HW->headSucursales == NULL {
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
  if(rec->ant != NULL){
    rec->ant->sig = rec->sig;
  } else {
    HW->headSucursales = rec->sig;
    HW->headSucursales->ant = NULL;
  }

  if(rec->sig != NULL){
    rec->sig->ant = rec->ant;
    
  } // el rec esta equivocado.

  eliminar = sucursalMenosVentas->sucursal;
  
  return eliminar;

} // Cierre de funcion



int main(void) {
  
}
