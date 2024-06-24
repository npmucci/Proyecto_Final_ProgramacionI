#include <iostream>
#include "menu.h"
#include "dibujos.h"
#include "jugar.h"
#include "creditos.h"


using namespace std;


void desplegarMenu(){
  int opcion;

  do{
    system("cls");
   dibujarEncabezado();

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
          mostrarCreditos();
      break;
    case 0:
      cout << "-------------------------" << endl;
      cout << "SALIENDO DEL JUEGO. GRACIAS POR JUGAR EMBAUCADO" << endl;
      break;

    default:
      cout << "ERROR: " << op << " No es un numero valido." << endl;
      break;

  }

  system("pause");


}
