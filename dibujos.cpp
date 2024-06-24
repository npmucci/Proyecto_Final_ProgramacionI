#include <iostream>
#include "rlutil.h"
#include "dibujos.h"

using namespace std;

// Función para dibujar el encabezado
  void dibujarEncabezado() {
    centrarTexto(1, "EMBAUCADO");
    cout <<endl << "------------------------------------------------------------------------------------------------------------------------";
    cout<< endl;
}

// Función para centrar texto horizontalmente
void centrarTexto(int y, string texto) {
    int longitud = texto.length();
    int x = (rlutil::tcols() - longitud) / 2;
    rlutil::locate(x, y);
    cout << texto;
}

// Función para dibujar un recuadro
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
    rlutil::setBackgroundColor(rlutil::YELLOW);
    rlutil::setColor(rlutil::BLACK);
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
    cout << "\nPresione una tecla par continuar...";
    rlutil::anykey();
}


// Función para mostrar los resultados por ronda dentro de un recuadro
void dibujarResultadosPorRonda(string vecJugadores[],int vecCartasJugadorUno[],int vecCartasJugadorDos[], int totalUno, int totalDos) {
    rlutil::cls();
    int x = 5;
    int y = 3;
    int ancho = 60;
    int alto = 15;

    dibujarRecuadro(x, y, ancho, alto);


    rlutil::locate(x + 2, y + 1);
    cout << "RONDA" << "             " << vecJugadores[0]<< "                 " << vecJugadores[1];
    rlutil::locate(x + 1, y + 2);
    cout << "----------------------------------------------------------";

    for (int i = 0; i < 3; ++i) {
        rlutil::locate(x + 2, y + 3 + i);
        if(vecCartasJugadorUno[i]==0){

        cout << i+1 << "                  " << "-";
        }
        else{
        cout << i+1 << "                  " << vecCartasJugadorUno[i];
        }
         if(vecCartasJugadorDos[i]==0){

         cout << i+1 << "                       " << "-";
        }
        else{
            cout << "                       "<< vecCartasJugadorDos[i];

        }



    rlutil::locate(x + 1, y + 6);
    cout << "----------------------------------------------------------";

    rlutil::locate(x + 2, y + 7);
    cout << "TOTAL" << "               " << totalUno<< "                     " << totalDos;




    rlutil::locate(x + 2, y + 9);


}
}

