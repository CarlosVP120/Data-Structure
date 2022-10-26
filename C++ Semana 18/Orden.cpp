#include "Orden.h"
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <time.h>

Orden::Orden() {
  Producto _producto;
  Usuario _cliente;
  producto = _producto;
  cliente = _cliente;
}

Orden::Orden(Producto _producto, Usuario _cliente) {
  producto = _producto;
  cliente = _cliente;
}

Producto Orden::getProducto(){
  return producto;
}

void Orden::ordenar()
{
	time_t rawtime;
  struct tm *timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  fechaCreacion = asctime(timeinfo);

  fechaEnvio = "2 - 5 dias habiles";

  std::cout << "\n---Informacion de Orden---\n" << std::endl;
  std::cout << "Numero de producto: " << producto.getNumProducto() << std::endl;
	std::cout << "Fecha de creacion: " << fechaCreacion;
  std::cout << "Fecha de envio: " << fechaEnvio << std::endl;
  std::cout << "Usuario: " << cliente.getNumUsuario() << std::endl;
  std::cout << "----------------------------" << std::endl;
}