//Guardas
#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>

class Producto
{
public:
    // Los constructores nos permite inicializar los productos
    Producto();        //Constructor por default
    Producto(std::string, float);  //Constructor por parámetro
    
		int getNumProducto() const;
    std::string getNombreProducto() const; 
	  int getExistencia() const;
		float getCostoProducto() const;
		float getGananciaProducto() const;

    void setNombreProducto(std::string); 
	  void setExistencia(int);
		void setCostoProducto(float);

		void imprimeProducto();

private:
  int numProducto;
  std::string nombreProducto;
  int existencia;
	float costoProducto; 
  float gananciaProducto;
};

#endif //PRODUCTO_H