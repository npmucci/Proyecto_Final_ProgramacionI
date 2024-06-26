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
    int puntajeGanador=0;
    int puntajeMayor=0;
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
    // Verificar si la entrada no es válida
        if (cin.fail()) {
            cin.clear(); // Limpiar el error
            cin.ignore(50, '\n'); // Ignorar la entrada incorrecta
            opcion = 4; // Asignar una opción inválida para manejarla en el default
        }

    implementarOpcion(opcion, jugadorGanador,puntajeGanador,jugadorMayorPuntaje,puntajeMayor);

  }while(opcion != 0);
}

void implementarOpcion(int op, string &nombreGanador, int &puntajeGanador,string &nombreMayorPuntaje, int &puntajeMayor){
    char respuesta;
  system("cls");

  switch(op)
  {
    case 1://jugar
      jugar(nombreGanador,puntajeGanador,nombreMayorPuntaje,puntajeMayor);
      system("cls");
      break;

    case 2:
      //estadisticas
      mostrarEstadistica(nombreMayorPuntaje,puntajeMayor);
      break;
    case 3:
      //credigos
          mostrarCreditos();

      break;
    case 0:
           dibujarEncabezado("EMBAUCADO");
      cout << "REALMENTE QUERES SALIR DEL JUEGO (S/N)?" << endl;
      cin >> respuesta;
      if( toupper(respuesta)=='S'){
        rlutil::cls();
        dibujarEncabezado("EMBAUCADO");
        rlutil::setColor(rlutil::LIGHTRED);
        centrarTexto(5, "SALIENDO DEL JUEGO. GRACIAS POR JUGAR EMBAUCADO");
       rlutil::setColor(rlutil::WHITE);
       rlutil::locate(20,8);
      }
      else{
        desplegarMenu();
      }

      break;

    default:
      cout << "ERROR: opcion no  valida." << endl;
      rlutil::anykey("Presione una tecla para volver al menu principal....");
      break;


  }


}
