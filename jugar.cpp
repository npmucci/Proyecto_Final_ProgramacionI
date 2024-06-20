#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include "jugar.h"

using namespace std;

const int TAM_MAZO_MANO = 10;
const int TAM_VEC_VALOR = 5;
const int TAM_VEC_PALO = 4;
const int CANT_RONDAS = 3;
const int CANT_JUGADORES =2;
const string VEC_VALOR[] = {"10", "J", "Q", "K", "A"};
const string VEC_FIGURA[] = {"corazon", "diamante", "picas", "trebol"};


void cargarNombre(string vecJugadores[])
{
    char confirmacion;

    do
    {
        cout << "EMBAUCADO" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "Antes de comenzar deben registrar sus nombres: " << endl << endl;

        cout << "Nombre del Jugador 1 ";
        cin.ignore();//me limpia el enter que traigo de antes de la funcion menu cuando elegí la opcion
        getline(cin, vecJugadores[0]);

        cout << "Nombre del Jugador 2 ";
        getline(cin, vecJugadores[1]);// se utiliza esta funcion para que tome nombres con los espacios en blanco


        cout << "\nConfirmar nombres (S/N): " << endl;
        cout << "\n------------------------------------------------------------------------" << endl;
        cin >> confirmacion;


        while(confirmacion != 'S' && confirmacion != 's' && confirmacion != 'N' && confirmacion != 'n') //para contemplar mayusculas y minusculas
        {
            cout << "ERROR solo se admite 'S' o 'N'" << endl;
            cout << "\nConfirmar nombres (S/N): ";
            cin >> confirmacion;

        }
        if(confirmacion == 'N' || confirmacion == 'n')
        {
            cout << "Ingrese los nombres nuevamente\n";
            system("pause");
            system("cls");
        }
        else
        {
            cout << "\n------------------------------------------------------------------------" << endl;
        }

        system("cls");

    }
    while(confirmacion != 's' && confirmacion != 'S'); //para contemplar mayusculas y minusculas

}


void cargarMazoMano(const string vecValor[], const string vecPalos[], string mazoValorMano[], string mazoPaloMano[], int tamMazoMano, int tamVecValor, int tamVecPalo)
{
    bool Repetidas = true;
    int numAzarValor, numAzarPalo;
    int contador=0;


    while (Repetidas)
    {
        // Llena el mazo con 10 cartas aleatorias de las 20 disponibles
        for (int x = 0; x < tamMazoMano; x++)
        {
            numAzarValor = rand() % tamVecValor;
            mazoValorMano[x] = vecValor[numAzarValor];
            numAzarPalo = rand() % tamVecPalo;
            mazoPaloMano[x] = vecPalos[numAzarPalo];
        }

        // Verificar si hay cartas repetidas
        Repetidas = false;
        for (int x = 0; x < tamMazoMano; x++)
        {
            for (int i = x + 1; i < tamMazoMano; i++)
            {
                if (mazoValorMano[x] == mazoValorMano[i] && mazoPaloMano[x] == mazoPaloMano[i])
                {
                    Repetidas = true;
                    break; // cuando encuentra la primer repetida, sale del bucle
                }
            }
        }
    }

}
string determinarCartaEmbaucadora()
{
    int aleatorio= rand()%TAM_VEC_PALO;
    return VEC_FIGURA[aleatorio];
}


//Parte estetica del juego
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




void repartirCartas(string mazoValorMano[], string mazoFiguraMano[], string embaucadora)
{
    rlutil::hidecursor();

    // Mostrar las cartas del jugador 1
    rlutil::setColor(rlutil::WHITE);
    for (int i = 0; i < TAM_MAZO_MANO / 2; i++)
    {
        dibujarCarta((i+1) * 16, 8, mazoValorMano[i], mazoFiguraMano[i]);
        rlutil::msleep(150);
    }

    // Mostrar las cartas del jugador 2
    for (int i = 5; i < TAM_MAZO_MANO; i++)
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


void calcularPuntosCartas(int puntosJugadorUno[], int puntosJugadorDos[], string vecValor[], string vecFigura[], string embaucadora)
{
    // Calcular los puntos del jugador 1 teniendo en cuenta las 5 primeras cartas del vector
    for (int i = 0; i < 5; i++)
    {
        // Verificar si el palo coincide con la embaucadora
        if (vecFigura[i] == embaucadora)
        {
            puntosJugadorUno[i] = 0;
        }
        else
        {
            if (vecValor[i] == "10")
            {
                puntosJugadorUno[i] = 10;
            }
            else if (vecValor[i] == "J")
            {
                puntosJugadorUno[i] = 11;
            }
            else if (vecValor[i] == "Q")
            {
                puntosJugadorUno[i] = 12;
            }
            else if (vecValor[i] == "K")
            {
                puntosJugadorUno[i] = 13;
            }
            else
            {
                puntosJugadorUno[i] = 20;
            }
        }
    }

    // Calcular los puntos del jugador 2 teniendo en cuenta las 5 siguientes cartas del vector
    for (int i = 5; i < 10; i++)
    {
        int j = i - 5;
        if (vecFigura[i] == embaucadora)
        {
            puntosJugadorDos[j] = 0;
        }
        else
        {
            if (vecValor[i] == "10")
            {
                puntosJugadorDos[j] = 10;
            }
            else if (vecValor[i] == "J")
            {
                puntosJugadorDos[j] = 11;
            }
            else if (vecValor[i] == "Q")
            {
                puntosJugadorDos[j] = 12;
            }
            else if (vecValor[i] == "K")
            {
                puntosJugadorDos[j] = 13;
            }
            else
            {
                puntosJugadorDos[j] = 20;
            }
        }
    }
}
void calcularPuntosRonda(int puntosJugadorUno[], int puntosJugadorDos[], int puntosRondaJugadorUno[], int puntosRondaJugadorDos[]) {

}
void calcularPuntosAcumulados(int puntosRondaJugadorUno[], int puntosRondaJugadorDos[], int &puntosAcumuladosUno, int &puntosAcumuladosDos) {

}


void implementarRonda(string vecJugadores[], int puntosJugadorUno[], int puntosJugadorDos[], int &puntosAcumuladosJugadorUno, int &puntosAcumuladosJugadorDos) {
    string mazoValorMano[TAM_MAZO_MANO]; // se crean el mazo de palos
    string mazoPaloMano[TAM_MAZO_MANO]; // se crea el mazo de figuras

    // Cargar el mazo de cartas aleatoriamente para la ronda
    cargarMazoMano(VEC_VALOR, VEC_FIGURA, mazoValorMano, mazoPaloMano, TAM_MAZO_MANO, TAM_VEC_VALOR, TAM_VEC_PALO);

    // Determinar cuál es la carta embaucadora
    string embaucadora = determinarCartaEmbaucadora();

    // Mostrar la ronda 1
    rlutil::locate(1, 6);
    cout << "  Mazo de " << vecJugadores[0] << " (" << puntosAcumuladosJugadorUno << " puntos)";

    rlutil::locate(1, 18);
    cout << "  Mazo de " << vecJugadores[1] << " (" << puntosAcumuladosJugadorDos << " puntos)";
    repartirCartas(mazoValorMano, mazoPaloMano, embaucadora);

    // Calcular los puntajes y mostrarlos
    calcularPuntosCartas(puntosJugadorUno, puntosJugadorDos, mazoValorMano, mazoPaloMano, embaucadora);
    cout << "Para ver el puntaje presione una tecla ";
    rlutil::anykey();
    mostrarPuntaje(puntosJugadorUno, puntosJugadorDos);
    cout << endl;
}

void jugar(string &jugadorMayorPuntaje, int &mayorPuntaje) {
    int puntosCartasJugadorUno[5] = {0, 0, 0, 0, 0}; // vector para guardar el puntaje que suma cada una de las 5 cartas
    int puntosCartasJugadorDos[5] = {0, 0, 0, 0, 0}; // vector para guardar el puntaje que suma cada una de las 5 cartas
    int puntosRondaJugadorUno[CANT_RONDAS] = {0, 0, 0}; // vector para guardar el puntaje individual de cada ronda jug 1
    int puntosRondaJugadorDos[CANT_RONDAS] = {0, 0, 0}; // vector para guardar el puntaje individual de cada ronda jug 1
    int puntosAcumuladoJugadorUno = 0; // acumular los puntajes de cada ronda para el jugador 1
    int puntosAcumuladoJugadorDos = 0; // acumular los puntajes de cada ronda para el jugador 2
    string vecJugadores[CANT_JUGADORES];

    cargarNombre(vecJugadores);

    for (int ronda = 1; ronda <= CANT_RONDAS; ronda++) {
        cout << "EMBAUCADO" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "Ronda #" << ronda << endl;
        cout << vecJugadores[0] << " VS " << vecJugadores[1] << endl;
        // Funcionalidad específica para cada ronda

                implementarRonda(vecJugadores, puntosCartasJugadorUno, puntosCartasJugadorDos, puntosAcumuladoJugadorUno, puntosAcumuladoJugadorDos);

                //calcularPuntosRonda(puntosCartasJugadorUno, puntosCartasJugadorDos, puntosRondaJugadorUno, puntosRondaJugadorDos);

                //calcularPuntosAcumulados(puntosRondaJugadorUno, puntosRondaJugadorDos, puntosAcumuladoJugadorUno, puntosAcumuladoJugadorDos);

        system("pause");
        rlutil::cls();
}
    }
