#include <iostream>
#include "rlutil.h"
#include "dibujos.h"

using namespace std;

/// Función para dibujar el encabezado
  void dibujarEncabezado(string texto) {
    centrarTexto(1, texto);
    cout <<endl << "------------------------------------------------------------------------------------------------------------------------";
    cout<< endl;
}

/// Función para centrar texto horizontalmente
void centrarTexto(int y, string texto) {
    int longitud = texto.length();
    int x = (rlutil::tcols() - longitud) / 2;
    rlutil::locate(x, y);
    cout << texto;
}

/// Función para dibujar un recuadro de los créditos, estadísicas y puntaje por ronda
void dibujarRecuadro(int x, int y, int ancho, int alto) {
    for (int i = 0; i < ancho; i++) {
        rlutil::locate(x + i, y);
        cout << "-"; // Línea horizontal superior
        rlutil::locate(x + i, y + alto - 1);
        cout << "-"; // Línea horizontal inferior
    }
    for (int i = 0; i < alto; i++) {
        rlutil::locate(x, y + i);
        cout << "|"; // Línea vertical izquierda
        rlutil::locate(x + ancho - 1, y + i);
        cout << "|"; // Línea vertical derecha
    }
    rlutil::locate(x, y);
    cout << "+"; // Esquina superior izquierda
    rlutil::locate(x + ancho - 1, y);
    cout << "+"; // Esquina superior derecha
    rlutil::locate(x, y + alto - 1);
    cout << "+"; // Esquina inferior izquierda
    rlutil::locate(x + ancho - 1, y + alto - 1);
    cout << "+"; // Esquina inferior derecha
}

///Dibuja la estucura de carta (la parte blanca)
void dibujarEstructuraCarta(int posx, int posy, int ancho, int alto)
{
    for (int x = posx; x < posx + ancho; x++)
    {
        for (int y = posy; y < posy + alto; y++)
        {
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(x, y);
            cout << (char) 219;
        }
    }
}

/// dubuja los valores de la carta en las puntas
void dibujarValorCarta(int posx, int posy, string valor)
{
    rlutil::locate(posx + 1, posy);
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLACK);
    cout << valor;

    if (valor.size() > 1)
    {
        rlutil::locate(posx + 9, posy + 7);
        cout << valor;
    }
    else
    {
        rlutil::locate(posx + 10, posy + 7);
        cout << valor;
    }
}

///dibuja la figura en el centro
void dibujarFiguraCarta(int posx, int posy, int palo)
{
    rlutil::locate(posx + 5, posy + 3);

    if (palo == 3 || palo == 4)
    {
        rlutil::setBackgroundColor(rlutil::WHITE);
        rlutil::setColor(rlutil::LIGHTRED);
    }
    else
    {
        rlutil::setBackgroundColor(rlutil::WHITE);
        rlutil::setColor(rlutil::BLACK);
    }
    cout << (char) palo;
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
}

///convierte el char en int para el codigo ASCII
int convertirPalo(const string &palo)
{
    if (palo == "corazon") return 3;
    else if (palo == "diamante") return 4;
    else if (palo == "trebol") return 5;
    else if (palo == "picas") return 6;

}

///reune todas las funciones anteriores y dibuja una carta
void dibujarCarta(int posx, int posy, string valor, string palo)
{
    dibujarEstructuraCarta(posx, posy, 12, 8);
    dibujarValorCarta(posx, posy, valor);
    int paloConvertido = convertirPalo(palo);
    dibujarFiguraCarta(posx, posy, paloConvertido);
}

///dibuja las 5 cartas para cada jugador y la embaucadora
void dibujarCartasMano(string mazoValorMano[], string mazoFiguraMano[], string embaucadora, int tamMazo)
{
    rlutil::hidecursor();

    // Mostrar las cartas del jugador 1

    for (int i = 0; i < tamMazo / 2; i++)
    {
        dibujarCarta((i+1) * 16, 8, mazoValorMano[i], mazoFiguraMano[i]);
        rlutil::msleep(150);
    }

    // Mostrar las cartas del jugador 2
    for (int i = 5; i < tamMazo; i++)
    {
        dibujarCarta((i - 4) * 16, 20, mazoValorMano[i], mazoFiguraMano[i]);
        rlutil::msleep(150);
    }

    //Dibujar carta embaucadora
    rlutil::locate(100,12);
    cout << " Embaucadora";

    dibujarCarta(100,14," ",embaucadora);

    rlutil::locate(1, 30);
}

///posiciona cada puntaje debajo de la carta correspondiente
void mostrarPuntaje(int puntosJugadorUno[], int puntosJugadorDos[]) {
    // Mostrar puntos de las cartas del jugador 1
     rlutil::locate(3,16);
    cout << "Puntos ";
    for (int i = 0; i < 5; i++) {
        rlutil::locate((i + 1) * 17, 16);
        cout << puntosJugadorUno[i] << " pts";
    }

    // Mostrar puntos de las cartas del jugador 2
     rlutil::locate(3,28);
    cout << "Puntos ";
    for (int i = 0; i < 5; i++) {
        rlutil::locate((i + 1) * 17, 28);
        cout << puntosJugadorDos[i] << "pts";
    }
    rlutil::locate(1, 32);
    cout << "\nPresione una tecla par continuar...";
    rlutil::anykey();
}


/// Función para mostrar los resultados por ronda dentro de un recuadro
void dibujarResultadosPorRonda(string vecJugadores[], int vecCartasJugadorUno[], int vecCartasJugadorDos[], int totalUno, int totalDos) {
    rlutil::cls();
    dibujarEncabezado("PUNTAJE");

    int ancho = 60;
    int alto = 10;
    int x = (rlutil::tcols() - ancho) / 2;
    int y = 5;

    dibujarRecuadro(x, y, ancho, alto);

    rlutil::locate(x + 2, y + 1);
    cout << "RONDA" << "             " << vecJugadores[0] << "                 " << vecJugadores[1];
    rlutil::locate(x + 1, y + 2);
    cout << "----------------------------------------------------------";

    for (int i = 0; i < 3; ++i) {
        rlutil::locate(x + 2, y + 3 + i);
        cout << i + 1 << "                  ";

        if (vecCartasJugadorUno[i] == 0) {
            cout << "-";
        } else {
            cout << vecCartasJugadorUno[i];
        }

        rlutil::locate(x + 44, y + 3 + i);
        if (vecCartasJugadorDos[i] == 0) {
            cout << "-";
        } else {
            cout << vecCartasJugadorDos[i];
        }
    }

    rlutil::locate(x + 1, y + 6);
    cout << "----------------------------------------------------------";

    rlutil::locate(x + 2, y + 7);
    cout << "TOTAL" << "              " << totalUno << "                    " << totalDos;
    rlutil::locate(40, 18);

}


void dibujarGanador (string nombreGanador, int puntajeGanador){
    rlutil::locate(43,16);
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLACK);
    cout << "  GANADOR: " << nombreGanador << " con " << puntajeGanador  << " puntos  ";

    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
     rlutil::locate(40, 18);

}

