#include <iostream>
#include "rlutil.h"
#include "dibujos.h"

using namespace std;


// Función para mostrar los créditos estéticamente
void mostrarCreditos() {
    rlutil::cls();

    int ancho = 56;
    int alto = 17;
    int x = (rlutil::tcols() - ancho) / 2;
    int y = (rlutil::trows() - alto) / 2;

    // Dibujar recuadro
    dibujarRecuadro(x, y, ancho, alto);

    // Cambiar color de texto


    // Mostrar título
    rlutil::setColor(rlutil::LIGHTCYAN);
    centrarTexto(y + 2, "CREDITOS");
    centrarTexto(y + 3, "-------------------------------------------");

    // Mostrar información de la versión del juego
    rlutil::setColor(rlutil::WHITE);
    centrarTexto(y + 4, "Embaucados 9.0 version creada por");

    // Mostrar nombres de alumnos
    centrarTexto(y + 6, "   Natalia Patricia Mucci - Legajo: 30490");
    centrarTexto(y + 7, "   Diego Omar Salas  - Legajo: 304591");

    // Mostrar nombre del profesor
    centrarTexto(y + 10, "Menciones especiales");
    centrarTexto(y + 12, "Creador del juego original: Angel Simon");

    // Mostrar mención a rlutil
    centrarTexto(y + 14, "Biblioteca rlutil -Copyright (C) 2010 Tapio Vierros");

    //posicion el cursor al medio parq que cuando vuelva al menu, ponga el texto ahi
     rlutil::setColor(rlutil::YELLOW);
     rlutil::locate(40,25);
      rlutil::anykey("Presiona una tecla para volver al menu...");
}
