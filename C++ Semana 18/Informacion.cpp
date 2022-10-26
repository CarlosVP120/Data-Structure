#include "Informacion.h"
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <time.h>

Informacion::Informacion(Orden _orden) {
  producto = _orden.getProducto();
  cantidad = 1;
  subtotal = producto.getCostoProducto() + producto.getCostoProducto()*0.16;
  numProducto = producto.getNumProducto();
}

float Informacion::getSubtotal() {
  return subtotal;
}

void Informacion::imprime() {
  std::cout << "\n---Detalles de Orden---\n" << std::endl;
  std::cout << "Numero de producto: " << numProducto << std::endl;
	std::cout << "Cantidad: " << cantidad << std::endl;
  std::cout << "Subtotal con IVA: " << subtotal << std::endl;
  std::cout << "Producto: " << producto.getNombreProducto() << std::endl;
  std::cout << "----------------------------" << std::endl;
}
  