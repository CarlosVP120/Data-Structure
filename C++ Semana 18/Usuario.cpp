#include "Usuario.h"
#include <iostream>
#include <ctime>

// Constructores
Usuario::Usuario()
{
    nombre = "Visitante";
    email = "usuario@visitante.com";
    contrasena = "visitante";
    numUsuario = 0;
    direccion = "indefinida";
    numTarjeta = 1234567890;
}

Usuario::Usuario(std::string _nombre, std::string _email, std::string _contrasena, std::string _direccion, int _numTarjeta)
{
    nombre = _nombre;
    email = _email;
    contrasena = _contrasena;
    srand(time(NULL));
    numUsuario = rand() % 5000 + 1000;
    direccion = _direccion;
    numTarjeta = _numTarjeta;
}

// Getters
std::string Usuario::getNombre() const
{
    return nombre;
}

std::string Usuario::getEmail() const
{
    return email;
}

std::string Usuario::getContrasena() const
{
    return contrasena;
}

std::string Usuario::getDireccion() const
{
    return direccion;
}

int Usuario::getNumUsuario() const
{
    return numUsuario;
}

int Usuario::getNumTarjeta() const
{
    return numTarjeta;
}

// Setters
void Usuario::setNombre(std::string _nombre)
{
    nombre = _nombre;
}
void Usuario::setEmail(std::string _email)
{
    email = _email;
}
void Usuario::setContrasena(std::string _contrasena)
{
    contrasena = _contrasena;
}
void Usuario::setDireccion(std::string _direccion)
{
    direccion = _direccion;
}
void Usuario::setNumTarjeta(int _numTarjeta)
{
    numTarjeta = _numTarjeta;
}

// Imprimir
void Usuario::imprime()
{
    std::cout << "\n---Informacion del usuario---" << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Contrasena: "
              << "***" << contrasena.substr(contrasena.length() - 3, 10) << std::endl;
    std::cout << "ID de usuario: " << numUsuario << std::endl;
    std::cout << "Direccion: " << direccion << std::endl;
    std::cout << "Tarjeta: "
              << "***" << std::to_string(numTarjeta).substr(std::to_string(numTarjeta).length() - 3, 3) << std::endl;
    std::cout << "----------------------------" << std::endl;
}