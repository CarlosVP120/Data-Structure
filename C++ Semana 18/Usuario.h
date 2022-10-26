//Guardas
#ifndef USUARIO_H
#define USUARIO_H
#include <string>

class Usuario
{
public:
    // Los constructores nos permite inicializar los productos
    Usuario();                                                        //Constructor por default
    Usuario(std::string, std::string, std::string, std::string, int); //Constructor por parámetro

    std::string getNombre() const;
    std::string getEmail() const;
    std::string getContrasena() const;
    std::string getDireccion() const;
    int getNumUsuario() const;
    int getNumTarjeta() const;

    void setNombre(std::string);
    void setEmail(std::string);
    void setContrasena(std::string);
    void setDireccion(std::string);
    void setNumTarjeta(int);

    void imprime();

private:
    std::string nombre;
    std::string email;
    std::string contrasena;
    std::string direccion;
    int numTarjeta;
    int numUsuario;
};

#endif //USUARIO_H