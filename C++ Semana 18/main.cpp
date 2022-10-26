#include <iostream>
#include <limits>
#include "Informacion.h"
using namespace std;

int main()
{
  system("clear");
  int registro, tarjeta;
  char opc, nom[30], direccion[30];
  string email, contra;
  Usuario usuario;

  // PRODUCTOS
  Producto* objs= new Producto[10];
  Producto Carrito[10];
  Orden ordenes[10];

	cout << "\nPROYECTO INTEGRADOR: COMERCIO ELECTRONICO\nA01641147\nA01641113";
	cout << "\n- - - - - - - - - - - - -" << endl;

	cout << "¿Deseas registrarte?  [1] Si / [2] No" << endl;
	cin >> registro;

  while (registro > 2 || registro < 1){
		cout << "\n- - - - - - - - - - - - -" << endl;
    cout << "Ingrese una opcion valida..." << endl;
    cout << "¿Deseas registrarte?  [1] Si / [2] No" << endl;
	  cin >> registro;
  }

	if (registro == 1) {
    cin.ignore(numeric_limits<int>::max(),'\n');
		cout <<  "Ingresa tu nombre: ";
		cin.getline(nom,30);
		cout <<  "Ingresa tu email: " ;
		cin >> email;
    cout <<  "Ingresa tu contrasena: " ;
		cin >> contra;
		cout <<  "Ingresa tu direccion: " ;
    cin.ignore(numeric_limits<int>::max(),'\n');
		cin.getline(direccion,30);
		cout <<  "Ingresa tu numero tarjeta: " ;
		cin >> tarjeta;
    usuario = Usuario (nom,email,contra,direccion,tarjeta);
    system("clear"); 
    cout << "- - - - - - - - - - - - -" << endl;
		cout <<  "¡Bienvenid@ "<< usuario.getNombre() << "!" << endl;
    cout <<  "Tu ID es... "<< usuario.getNumUsuario() << endl;
		cout << "Te recomendamos guardar tu ID para poder realizar compras mas tarde";
  }
	
  else if (registro == 2) {
    cout << "- - - - - - - - - - - - -" << endl;
    cout <<  "¡Bienvenid@! has iniciado sesión como "<< usuario.getNombre() << "!" << endl;
    cout <<  "El modo invitado no permite realizar compras, te recomendamos registrarte..." << endl;
  }

  // PRODCUTOS
  objs[0] = Producto("iPhone 13 Pro Max",29500);
  objs[1] = Producto("Sistema de sonido Bose",10999);
  objs[2] = Producto("Beats Solo3 Wireless",3649);
  objs[3] = Producto("MacBook Pro 13'",49859);
  objs[4] = Producto("Lapiz interactivo",900);
  objs[5] = Producto("Television 5K",35999);
  objs[6] = Producto("Camara HD",10000);
  objs[7] = Producto("Xbox Series X",7500);
  objs[8] = Producto("iPad Pro 13'",3599);
  objs[9] = Producto("Impresora Epson L375",3599);
  
  do {
		cout << "\n- - - - - - - - - - - - -" << endl;
		cout << "MENÚ DE OPCIONES\n\n\t[1] Ver catalogo de productos\n\t[2] Mi Usuario\n\t[3] Comprar producto\n\t[4] Orden y detalles\n\n\t[5] Salir";
		cout << "\n\nIngresa la opción que deseas ejecutar: ";
		cin >> opc;
		cout << "- - - - - - - - - - - - -" << endl;
    switch (opc)
    {
    case '1':
      system("clear");
      cout << "- - CATALOGO DE PRODUCTOS - -\n" << endl;
			cout << "| PRODUCTO | PRECIO | ID |\n" << endl;
      for(int i = 0; i <= 9; i = i + 1) {
					cout << "---------------------------" <<endl;
					cout << "Producto: " << objs[i].getNombreProducto() << endl;
					cout << "Precio: $"<< objs[i].getCostoProducto() << endl;
					cout << "ID: " << objs[i].getNumProducto() << endl;
          
        }
      break;
   
    case '2':
      int actUsuario;
      system("clear");
      cout << "- - MI USUARIO - -" << endl;
      usuario.imprime();

      if (usuario.getNumUsuario() != 0) {

        cout << "¿Deseas actualizar tu usuario?  [1] Si / [2] No" << endl ;
        cin >> actUsuario;
        if (actUsuario == 1) {

          string email;
          string contra;
          int tarjeta;
          char opcion, nombre[30],direccion[30];
          
          do {
            cout << "Actualizar usuario\n\n\t[1] Nombre\n\t[2] Email\n\t[3] Contraseña\n\t[4] Direccion\n\t[5] Numero de tarjeta\n\n\t[6] Salir" ;
            cout << "\n\nIngresa la opción que deseas ejecutar: ";
            cin >> opcion;

            switch (opcion) {
            
              case '1':
                cout << "- - - - - - - - - - - - -" << endl;
                cout << "Ingrese su nuevo nombre de usuario..." << endl;
                cin.ignore(numeric_limits<int>::max(),'\n');
                cin.getline(nombre,30);
                usuario.setNombre(nombre);
								cout << "- - - - - - - - - - - - -" << endl;
                break;

              case '2':
                cout << "- - - - - - - - - - - - -" << endl;
                cout << "Ingrese su nuevo email..." << endl;
                cin >> email;
                usuario.setEmail(email);
								cout << "- - - - - - - - - - - - -" << endl;
                break;

              case '3':
                cout << "- - - - - - - - - - - - -" << endl;
                cout << "Ingrese su nueva contrasena..." << endl;
                cin >> contra;
                usuario.setContrasena(contra);
								cout << "- - - - - - - - - - - - -" << endl;
                break;

              case '4':
                cout << "- - - - - - - - - - - - -" << endl;
                cout << "Ingrese su nueva direccion..." << endl;
                cin.ignore(numeric_limits<int>::max(),'\n');
                cin.getline(direccion,40);
                usuario.setDireccion(direccion);
								cout << "- - - - - - - - - - - - -" << endl;
                break;

              case '5':
                cout << "- - - - - - - - - - - - -" << endl;
                cout << "Ingrese su nuevo numero de tarjeta..." << endl;
                cin >> tarjeta;
                usuario.setNumTarjeta(tarjeta);
								cout << "- - - - - - - - - - - - -" << endl;

                break;
                
              case '6':
                cout << "- - - - - - - - - - - - -" << endl;
                cout << "Saliendo..." << endl;
                break;

              default:
                cout << "Ingrese una opción válida\n" << endl;
            }
          } while (opcion != '6');
        }
      }
      
      else {
        cout << "No puede actualizar su informacion siendo invitado...\n" << endl;
      }

      break;

    case '3':
      int cont,idP, subtotCarrito, confirmarOrdenes,IDeliminarProducto, eliminados;
			eliminados = 0;
      subtotCarrito = 0;
      cont = 0;
			idP = 1;
			IDeliminarProducto = 1;

      system("clear");
      cout << "- - COMPRAR PRODUCTO - -" << endl;
			if (usuario.getNumUsuario() != 0) {
				cout << "| PRODUCTO | PRECIO | ID |\n" << endl; 
        for(int i = 0; i <= 9 ; i = i + 1) {
          cout << "| "  << objs[i].getNombreProducto() << " | $" << objs[i].getCostoProducto()<< " | " << objs[i].getNumProducto() << endl;
        }
				cout << "\nIngresa '0' cuando ya no desees comprar otro producto\n" << endl;
				cout << "- - - - - - - - - - - - -" << endl;

				while (idP != 0){
					cout << "Ingresa el 'ID' del producto que deseas comprar: ";
					cin >> idP;
					if (idP != 0) {
            for(int i = 0; i <= 9 ; i = i + 1) {
              if (idP == objs[i].getNumProducto()) {
                Carrito[cont] = objs[i];
                cont ++;
              }
            }
          }
				}
        cout << "\n- - LISTA DE TUS PRODUCTOS - -\n" << endl;
        for(int i = 0; i < cont; i = i + 1) {
          cout << "| "  << Carrito[i].getNombreProducto() << " | $" << Carrito[i].getCostoProducto()<< " | " << Carrito[i].getNumProducto() << endl;
					subtotCarrito += Carrito[i].getCostoProducto();
        }
        cout << "- - - - - - - - - - - - -" << endl;
				cout << "Subtotal de compra:  $ "<< subtotCarrito << endl;
        cout << "\n- - - - - - - - - - - - -" << endl;
				cout << "¿Desea confirmar sus ordenes?  [1] Si / [2] Cancelar orden"<< endl;
				cin >> confirmarOrdenes;
        if (confirmarOrdenes == 1){
          system("clear");
					cout << "¡Excelente "<< usuario.getNombre() <<"! se han generado las siguientes ordenes..." << endl;
          for(int i = 0; i < cont; i = i + 1) {
            ordenes[i] = Orden (Carrito[i],usuario);
            ordenes[i].ordenar();
          }
				}

				else if (confirmarOrdenes == 2){
          cont = -1;
          Producto Carrito[10];								
          cout << "¡Carrito vaciado! " << endl;
				}
      }
      else {
        cout << "\nNo puede comprar productos siendo invitado...\n" << endl;
      }    
      break;

    case '4':
      float total;
      int confirmarPago;
      total = 0;
      if (usuario.getNumUsuario() != 0) {
        system("clear");
        cout << "- - ORDEN Y DETALLES - -" << endl;
        cout << "- - - - - - - - - - - - -" << endl;
        cout << "Estas son sus ordenes a pagar...\n" << endl;
        for(int i = 0; i < cont; i = i + 1) {
          Informacion informacionOrden(ordenes[i]);
          informacionOrden.imprime();
          total += informacionOrden.getSubtotal();
        }
        cout << endl << "Total a pagar: $" << total << endl;
        cout << "- - - - - - - - - - - - -" << endl;
        cout << "Para confirmar y pagar ingrese su ID... (si olvidaste tu ID recuerda que puedes verlo en la opcion 'Mi Usuario')" << endl;
        cout << "Para seguir comprando ingrese 0" << endl;
        cin >> confirmarPago;

        if (confirmarPago == usuario.getNumUsuario()) {
          system("clear");
          cout << "\n- - - - - - - - - - - - -" << endl;
          cout << "¡Felicidades " << usuario.getNombre() << "!" << endl;
          cout << "El siguiente pedido será enviado a " << usuario.getDireccion() << " en 2-5 días hábiles...\n" << endl;

          for(int i = 0; i < cont; i = i + 1) {
            Informacion informacionOrden(ordenes[i]);
            cout << "| "  << ordenes[i].getProducto().getNombreProducto() << " | $" << informacionOrden.getSubtotal() << " | " << endl;
          }
          cout << "- - - - - - - - - - - - -" << endl;
          cout << "Pago de $" << total << " realizado correctamente, a la tarjeta " << "***" << to_string(usuario.getNumTarjeta()).substr(to_string(usuario.getNumTarjeta()).length() - 3, 3) << "\n¡Gracias por su compra!" << endl;
          opc = '5';
        }
        else if (confirmarPago != 0) {
          cout << "\nOpcion invalida... Regresando al menu...\n" << endl;
        }
      }

      else {
        cout << "\nNo puede ver sus ordenes siendo invitado...\n" << endl;
      } 
      break;
      
    case '5':						
      //cout << "- - - - - - - - - - - - -" << endl;
      cout << "Cerrando sesion..." << endl;
      break;
      
    default:
      cout << "Ingrese una opción válida\n" << endl;
  }
		cin.ignore();
		cout << "\nPresiona enter para continuar...";
		cin.get();
    system("clear");
	} while (opc != '5');

		return 0;
}