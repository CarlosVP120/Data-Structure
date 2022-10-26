//Guardas
#ifndef ORDEN_H
#define ORDEN_H
#include <string>
#include "Usuario.h"
#include "Producto.h"

class Orden
{
public:
  // Los constructores nos permite inicializar los productos
  Orden();
  Orden(Producto,Usuario);
  Producto getProducto();
  void ordenar();


private:
  int numProducto;
  std::string fechaCreacion;
  std::string fechaEnvio;
	int numUsuario;
  Usuario cliente;
  Producto producto;
};

#endif //ORDEN_H