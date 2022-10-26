//Guardas
#ifndef INFORMACION_H
#define INFORMACION_H
#include <string>
#include "Orden.h"

class Informacion
{
public:
  // Los constructores nos permite inicializar los productos
  Informacion(Orden);
	float getSubtotal();
  void imprime();

private:
  int numProducto;
  int cantidad;
	float subtotal;
  Producto producto;

};

#endif //INFORMACION_H