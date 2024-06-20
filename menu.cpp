#include <iostream>
#include "menu.h"
#include "jugar.h"

using namespace std;


const int CANT_JUGADORES=2;

void desplegarMenu(){


  int opcion;

  do{
    system("cls");
    cout <<endl << "EMBAUCADO" << endl;
    cout << "-------------------------" << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADISTICAS" << endl;
    cout << "3 - CREDITOS" << endl;
    cout << "-------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "Ingrese su opcion: ";
    cin >> opcion;

    implementarOpcion(opcion);

  }while(opcion != 0);
}

void implementarOpcion(int op){
    string nombreJugador;
    int mayorPuntaje;
  system("cls");

  switch(op)
  {
    case 1://jugar
      jugar(nombreJugador,mayorPuntaje);
      break;

    case 2:
      //estadisticas
      break;
    case 3:
      //credigos
      break;
    case 0:
      cout << "-------------------------" << endl;
      cout << "SALIENDO DEL JUEGO. GRACIAS POR JUGAR EMBAUCADO";
      break;

    default:
      cout << "ERROR: " << op << " No es un numero valido." << endl;
      break;

  }

  system("pause");


}
