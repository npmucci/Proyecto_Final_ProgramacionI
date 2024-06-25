#include <iostream>
#include "rlutil.h"
#include "menu.h"
#include "dibujos.h"
#include "jugar.h"
#include "estadistica.h"
#include "creditos.h"



using namespace std;


void desplegarMenu(){
    string jugadorGanador;
    string jugadorMayorPuntaje;
    int puntajeGanador;
    int puntajeMayor;
    bool hayEstadistica = false;
    int opcion;

  do{
    rlutil::setColor(rlutil::WHITE);
    system("cls");
   dibujarEncabezado("EMBAUCADO");

    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADISTICAS" << endl;
    cout << "3 - CREDITOS" << endl;
    cout << "-------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "Ingrese su opcion: ";
    cin >> opcion;

    implementarOpcion(opcion, jugadorGanador,puntajeGanador,jugadorMayorPuntaje,puntajeMayor,hayEstadistica);

  }while(opcion != 0);
}

void implementarOpcion(int op, string &nombreGanador, int &puntajeGanador,string &nombreMayorPuntaje, int &puntajeMayor, bool &hayEstadistica){

  system("cls");

  switch(op)
  {
    case 1://jugar
      jugar(nombreGanador,puntajeGanador);
      system("cls");
      break;

    case 2:
      //estadisticas
      actualizarEstadistica(nombreGanador,puntajeGanador,nombreMayorPuntaje,puntajeMayor,hayEstadistica);
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


}
