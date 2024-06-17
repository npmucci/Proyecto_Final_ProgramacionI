
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include "jugar.h"

using namespace std;

const int TAM_MAZO_MANO = 10;
const int TAM_VEC_VALOR = 5;
const int TAM_VEC_PALO = 4;
const string VEC_VALOR[] = {"10", "J", "Q", "K", "A"};
const string VEC_PALO[] = {"corazon", "diamante", "picas", "trebol"};


void cargarNombre(string vecJugadores[]){
    char confirmacion;

    do{
      cout << "EMBAUCADO" << endl;
      cout << "------------------------------------------------------------------------" << endl;
      cout << "Antes de comenzar deben registrar sus nombres: " << endl << endl;

      cout << "Nombre del Jugadr 1 ";
      cin.ignore();//me limpia el enter que traigo de antes de la funcion menu cuando elegí la opcion
      getline(cin, vecJugadores[0]);

	 cout << "Nombre del Jugadr 2 ";
      getline(cin, vecJugadores[1]);// se utiliza esta funcion para que tome nombres con los espacios en blanco


      cout << "\nConfirmar nombres (S/N): ";
      cin >> confirmacion;


      while(confirmacion != 'S' && confirmacion != 's' && confirmacion != 'N' && confirmacion != 'n'){//para contemplar mayusculas y minusculas
        cout << "ERROR solo se admite 'S' o 'N'" << endl;
        cout << "\nConfirmar nombres (S/N): ";
        cin >> confirmacion;
      }
       if(confirmacion == 'N' || confirmacion == 'n'){
        cout << "Ingrese los nombres nuevamente\n";
        system("pause");
        system("cls");
       }else{
        cout << "\n------------------------------------------------------------------------" << endl;
       }

       system("cls");

    }while(confirmacion != 's' && confirmacion != 'S');//para contemplar mayusculas y minusculas

}


void cargarMazoMano(const string vecValor[], const string vecPalos[], string mazoValorMano[], string mazoPaloMano[], int tamMazoMano, int tamVecValor, int tamVecPalo)
{
    bool Repetidas = true;
    int numAzarValor, numAzarPalo;

    while (Repetidas)
    {
        // Llena el mazo con cartas aleatorias
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
                }
            }
        }
    }
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
        rlutil::locate(posx + 10, posy + 8);
        cout << valor;
    }
    else
    {
        rlutil::locate(posx + 11, posy + 8);
        cout << valor;
    }
}

void dibujarPaloCarta(int posx, int posy, int palo)
{
    rlutil::locate(posx + 6, posy + 4);

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
    return -1;
}

void dibujarCarta(int posx, int posy, string valor, string palo)
{
    dibujarEstructuraCarta(posx, posy, 13, 9);
    dibujarValorCarta(posx, posy, valor);
    int paloConvertido = convertirPalo(palo);
    dibujarPaloCarta(posx, posy, paloConvertido);
}
void dibujarCartaEmbaucadora()
{
    int aleatorio= rand()%TAM_VEC_PALO;
    dibujarCarta(100,10,"E",VEC_PALO[aleatorio]);


}

void repartirCartas(string vecJugadores[])
{

    string mazoValorMano[TAM_MAZO_MANO];
    string mazoPaloMano[TAM_MAZO_MANO];

    // Cargar el mazo de cartas aleatoriamente
    cargarMazoMano(VEC_VALOR, VEC_PALO, mazoValorMano, mazoPaloMano, TAM_MAZO_MANO, TAM_VEC_VALOR, TAM_VEC_PALO);




    // Mostrar las cartas del jugador 1
    rlutil::setColor(rlutil::WHITE);
    cout << "  Mazo de " << vecJugadores[0];
    for (int i = 0; i < TAM_MAZO_MANO / 2; i++)
    {
        dibujarCarta((i+1) * 16, 3, mazoValorMano[i], mazoPaloMano[i]);
        rlutil::msleep(150);
    }

    // Mostrar las cartas del jugador 2
    rlutil::locate(1,13);
    cout << "  Mazo de " << vecJugadores[1];
    for (int i = 5; i < TAM_MAZO_MANO; i++)
    {
        dibujarCarta((i - 4) * 16, 15, mazoValorMano[i], mazoPaloMano[i]);
        rlutil::msleep(150);
    }

    //Dibujar carta embaucadora
    rlutil::locate(100,8);
    cout << " Embaucadora";
    dibujarCartaEmbaucadora();

    rlutil::locate(1, 25);
}


void jugar(string vecJugadores[]){

	cargarNombre(vecJugadores);
	repartirCartas(vecJugadores);

}
