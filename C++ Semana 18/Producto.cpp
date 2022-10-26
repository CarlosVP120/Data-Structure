#include "Producto.h"
#include <iostream>
#include <ctime>

// Constructores
Producto::Producto()
{
  srand(time(NULL));
  numProducto = rand() % 200 + 100;
  nombreProducto = "Producto";
  existencia = 0;
	costoProducto = 0; 
  gananciaProducto = 0;
}

Producto::Producto(std::string _nombreProducto, float _costoProducto)
{
  numProducto = rand() % 9000 + 1000;
  nombreProducto = _nombreProducto;
  existencia = rand() % 100 + 1;
	costoProducto = _costoProducto; 
  gananciaProducto = _costoProducto * 0.1;
}

// Getters
int Producto::getNumProducto() const
{
    return numProducto;
}

std::string Producto::getNombreProducto() const
{
    return nombreProducto;
}

int Producto::getExistencia() const
{
    return existencia;
}

float Producto::getCostoProducto() const
{
    return costoProducto;
}

float Producto::getGananciaProducto() const
{
    return gananciaProducto;
}

// Setters		
void Producto::setNombreProducto(std::string _nombreProducto)
{
    nombreProducto = _nombreProducto;
}
void Producto::setExistencia(int _existencia)
{
    existencia = _existencia;
}
void Producto::setCostoProducto(float _costoProducto)
{
    costoProducto = _costoProducto;
}

// Imprimir
void Producto::imprimeProducto()
{
    std::cout << "\n---Informacion del Producto---\n" << std::endl;
    std::cout << "Nombre Producto: " << nombreProducto << std::endl;
    std::cout << "Numero de producto: " << numProducto << std::endl;
    std::cout << "Existencia: " << existencia << std::endl;
    std::cout << "Costo del producto: " << costoProducto << std::endl;
    std::cout << "Ganancia: " << gananciaProducto << std::endl;
    std::cout << "----------------------------" << std::endl;
}

