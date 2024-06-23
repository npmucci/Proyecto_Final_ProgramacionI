#include <iostream>
#include "rlutil.h"
#include "dibujos.h"

using namespace std;

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

void dibujarPaloCarta(int posx, int posy, int palo)
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

int convertirPalo(const string &palo)
{
    if (palo == "corazon") return 3;
    else if (palo == "diamante") return 4;
    else if (palo == "trebol") return 5;
    else if (palo == "picas") return 6;

}

void dibujarCarta(int posx, int posy, string valor, string palo)
{
    dibujarEstructuraCarta(posx, posy, 12, 8);
    dibujarValorCarta(posx, posy, valor);
    int paloConvertido = convertirPalo(palo);
    dibujarPaloCarta(posx, posy, paloConvertido);
}




void dibujarCartasMano(string mazoValorMano[], string mazoFiguraMano[], string embaucadora, int tamMazo)
{
    rlutil::hidecursor();

    // Mostrar las cartas del jugador 1
    rlutil::setColor(rlutil::WHITE);
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

    rlutil::locate(1, 29);
}

void mostrarPuntaje(int puntosJugadorUno[], int puntosJugadorDos[]) {
    // Mostrar puntos de las cartas del jugador 1
     rlutil::locate(1,16);
    cout << "Puntos ";
    rlutil::setColor(rlutil::WHITE);
    for (int i = 0; i < 5; i++) {
        rlutil::locate((i + 1) * 17, 16);
        cout << puntosJugadorUno[i] << " pts";
    }

    // Mostrar puntos de las cartas del jugador 2
     rlutil::locate(1,28);
    cout << "Puntos ";
    for (int i = 0; i < 5; i++) {
        rlutil::locate((i + 1) * 17, 28);
        cout << puntosJugadorDos[i] << "pts"
         ;
    }
}

