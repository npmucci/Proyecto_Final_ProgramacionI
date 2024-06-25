#include <iostream>
#include "rlutil.h"
#include "dibujos.h"
#include "estadistica.h"

using namespace std;

// Función para actualizar las estadísticas con el nombre y puntaje del ganador de cada partida
void actualizarEstadistica(string nombre, int puntaje, bool &hayEstadisticas) {
    string mejorJugador;
    int mejorPuntaje;
    if (!hayEstadisticas || puntaje > mejorPuntaje) {
        mejorJugador = nombre;
        mejorPuntaje = puntaje;
        hayEstadisticas = true;
    }

    mostrarEstadistica(mejorJugador, mejorPuntaje, hayEstadisticas);
}

// Función para mostrar las estadísticas en la consola
void mostrarEstadistica(string mejorJugador, int mejorPuntaje, bool hayEstadisticas) {
    dibujarEncabezado("EMBAUCADO");
    rlutil::cls();

    int ancho = 50;
    int alto = 10;
    int x = (rlutil::tcols() - ancho) / 2;
    int y = 5;

    // Dibujar recuadro
    dibujarRecuadro(x, y, ancho, alto);

    // Cambiar color de texto
    rlutil::setColor(rlutil::LIGHTCYAN);

    // Mostrar título
    centrarTexto(y + 2, "ESTADISTICAS");
    centrarTexto(y + 3, "---------------------------------------");

    // Mostrar información del jugador con mayor puntaje o mensaje de no hay estadísticas
    rlutil::setColor(rlutil::WHITE);
        centrarTexto(y + 4, "JUGADOR CON MAYOR PUNTAJE");
        centrarTexto(y + 6, " Nombre : " + mejorJugador);
        centrarTexto(y + 7, " Puntos : " + to_string(mejorPuntaje));


    rlutil::locate(35, 17);
    rlutil::anykey("Presiona una tecla para volver al menu...");
}

