#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include "jugar.h"
#include "dibujos.h"
#include "estadistica.h"

using namespace std;

void jugar(string &nombreGanador, int &puntajeGanador, string &jugadorMejorPuntaje, int &mejorPuntaje)
{
    // Mazos con los que se van a jugar
    const string VEC_VALOR[5] = {"10", "J", "Q", "K", "A"};
    const string VEC_FIGURA[4] = {"corazon", "diamante", "picas", "trebol"};

    // Tamaños de los vectores
    const int CANT_RONDAS = 3;
    const int CANT_JUGADORES = 2;
    const int TAM_MAZO_MANO = 10;

    //Variables del juego
    string vecJugadores[CANT_JUGADORES];
    string mazoValorMano[TAM_MAZO_MANO];
    string mazoFiguraMano[TAM_MAZO_MANO];

    // Variables para guardar los puntos
    int puntosCartasJugadorUno[5] = {0, 0, 0, 0, 0}; // Vector para guardar el puntaje que suma cada una de las 5 cartas
    int puntosCartasJugadorDos[5] = {0, 0, 0, 0, 0}; // Vector para guardar el puntaje que suma cada una de las 5 cartas
    int puntosRondaJugadorUno[CANT_RONDAS] = {0, 0, 0}; // Vector para guardar el puntaje individual de cada ronda del jugador 1
    int puntosRondaJugadorDos[CANT_RONDAS] = {0, 0, 0}; // Vector para guardar el puntaje individual de cada ronda del jugador 2
    int puntosAcumuladosJugadorUno = 0; // Acumular los puntajes de cada ronda para el jugador 1
    int puntosAcumuladosJugadorDos = 0; // Acumular los puntajes de cada ronda para el jugador 2

    // Variables cambio embaucadora
    string embaucadora;
    bool confirmacionUno;
    bool confirmacionDos;
    int costo = 20;

    // Pedir nombre a los juagores
    cargarNombre(vecJugadores);

    //ciclo de juego
    for (int ronda = 1; ronda <= CANT_RONDAS; ronda++)
    {
        dibujarEncabezado("EMBAUCADO");
        centrarTexto(3, "Ronda #" + to_string(ronda));
        centrarTexto(4, vecJugadores[0] + " VS " + vecJugadores[1]);

        repartirCartas(VEC_VALOR, VEC_FIGURA, mazoValorMano, mazoFiguraMano, vecJugadores, puntosCartasJugadorUno, puntosCartasJugadorDos, puntosAcumuladosJugadorUno, puntosAcumuladosJugadorDos, TAM_MAZO_MANO);

        ///primera ronda se calculan los puntos de forma normal
        if(ronda==1)
        {
            puntosRondaJugadorUno[ronda - 1] = sumarVector(puntosCartasJugadorUno, 5);
            puntosRondaJugadorDos[ronda - 1] = sumarVector(puntosCartasJugadorDos,5);
        }


        else if (ronda == 2)
        {
            confirmacionUno=cambiarEmbaucadora(vecJugadores[0]);
            if(confirmacionUno)
            {
                implementarCambioEmbaucadora(ronda,vecJugadores[0], puntosAcumuladosJugadorUno, VEC_FIGURA, 4, mazoValorMano, mazoFiguraMano, puntosCartasJugadorUno, puntosCartasJugadorDos, puntosRondaJugadorUno[ronda - 1], puntosRondaJugadorDos[ronda - 1], costo, confirmacionUno,confirmacionDos,31);
            }
            else
            {
                confirmacionDos=cambiarEmbaucadora(vecJugadores[1]);
                if(confirmacionDos)
                {
                    implementarCambioEmbaucadora(ronda,vecJugadores[1], puntosAcumuladosJugadorDos, VEC_FIGURA, 4, mazoValorMano, mazoFiguraMano, puntosCartasJugadorDos, puntosCartasJugadorUno, puntosRondaJugadorDos[ronda - 1], puntosRondaJugadorUno[ronda - 1], costo, confirmacionUno,confirmacionDos,32);
                }
            }


            if (!confirmacionUno && !confirmacionDos)
            {
                // Si ninguno de los jugadores cambió la carta embaucadora, calcula los puntos sin restar el costo
                puntosRondaJugadorUno[ronda - 1] = sumarVector(puntosCartasJugadorUno, 5);
                puntosRondaJugadorDos[ronda - 1] = sumarVector(puntosCartasJugadorDos, 5);
                rlutil::locate(1,32);
            }
        }
        else
        {
            confirmacionDos=cambiarEmbaucadora(vecJugadores[1]);
            if(confirmacionDos)
            {
                implementarCambioEmbaucadora(ronda,vecJugadores[1], puntosAcumuladosJugadorDos, VEC_FIGURA, 4, mazoValorMano, mazoFiguraMano, puntosCartasJugadorDos, puntosCartasJugadorUno, puntosRondaJugadorDos[ronda - 1], puntosRondaJugadorUno[ronda - 1], costo,confirmacionUno,confirmacionDos,31);

            }
            else
            {
                confirmacionUno=cambiarEmbaucadora(vecJugadores[0]);
                if(confirmacionUno)
                {
                    implementarCambioEmbaucadora(ronda,vecJugadores[0], puntosAcumuladosJugadorUno, VEC_FIGURA, 4, mazoValorMano, mazoFiguraMano, puntosCartasJugadorUno, puntosCartasJugadorDos, puntosRondaJugadorUno[ronda - 1], puntosRondaJugadorDos[ronda - 1], costo, confirmacionUno,confirmacionDos,32);
                }
            }


            if (!confirmacionUno && !confirmacionDos)
            {
                // Si ninguno de los jugadores cambió la carta embaucadora, calcula los puntos sin restar el costo
                puntosRondaJugadorUno[ronda - 1] = sumarVector(puntosCartasJugadorUno, 5);
                puntosRondaJugadorDos[ronda - 1] = sumarVector(puntosCartasJugadorDos, 5);
                rlutil::locate(1, 32);
            }
        }


        puntosAcumuladosJugadorUno = sumarVector(puntosRondaJugadorUno, CANT_RONDAS);
        puntosAcumuladosJugadorDos = sumarVector(puntosRondaJugadorDos, CANT_RONDAS);
        rlutil::anykey("Para ver el puntaje presione una tecla ");
        mostrarPuntaje(puntosCartasJugadorUno, puntosCartasJugadorDos);

        if(ronda==1 || ronda==2)
        {
            dibujarResultadosPorRonda(vecJugadores, puntosRondaJugadorUno, puntosRondaJugadorDos, puntosAcumuladosJugadorUno, puntosAcumuladosJugadorDos);
        }


        rlutil::anykey();
        rlutil::cls();
    }

    determinarGanador(puntosRondaJugadorUno, puntosRondaJugadorDos, puntosAcumuladosJugadorUno, puntosAcumuladosJugadorDos, vecJugadores, nombreGanador, puntajeGanador);
    dibujarResultadosPorRonda(vecJugadores, puntosRondaJugadorUno, puntosRondaJugadorDos, puntosAcumuladosJugadorUno, puntosAcumuladosJugadorDos);
    rlutil::msleep(500);
    dibujarGanador(nombreGanador, puntajeGanador);
    actualizarEstadistica(nombreGanador, puntajeGanador, jugadorMejorPuntaje, mejorPuntaje);
    rlutil::anykey("Presione una tecla para volver al menu");
}

void cargarNombre(string vecJugadores[])
{
    char respuesta;
    bool confirmar;

    do
    {
        dibujarEncabezado("EMBAUCADO");
        cout << "Antes de comenzar deben registrar sus nombres: " << endl << endl;

        cout << "Nombre del Jugador 1 ";
        cin.ignore();//me limpia el enter que traigo de antes de la funcion menu cuando elegí la opcion
        getline(cin, vecJugadores[0]);

        cout << "Nombre del Jugador 2 ";
        getline(cin, vecJugadores[1]);// se utiliza esta funcion para que tome nombres con los espacios en blanc0
        cout << endl;
        cout << "Confirmar Nombres? (S/N) " << endl;
        cout << endl << endl << "-------------------------------------------------" << endl;
        rlutil::locate(27,8);
        cin >> respuesta;
        confirmar = manejarRespuesta(respuesta,1,9);
        if(!confirmar)
        {

            cout << "Ingrese los nombres nuevamente\n";
            system("pause");
            system("cls");
        }

        system("cls");

    }
    while(!confirmar); //para contemplar mayusculas y minusculas

}
///funcion generica para todas la preguntas de si y no
bool manejarRespuesta(char respuesta, int posx,int posy)
{
    while (toupper(respuesta) != 'S' && toupper(respuesta) != 'N')
    {
        rlutil::locate(posx,posy);
        cout << "Opcion invalida. Por favor ingrese 's' para Si o 'n' para No: ";
        cin >> respuesta;
    }
    if(toupper(respuesta) == 'S')
    {
        return true;
    }
    else
    {
        return false;
    }

}
//con esta funcion en cada mano, lleno el mazo con 10 cartas
void cargarMazoMano(const string vecValor[], const string vecFigura[], string mazoValorMano[], string mazoFiguraMano[], int tamMazoMano, int tamVecValor, int tamVecFigura)
{
    bool Repetidas = true;
    int numAzarValor, numAzarFigura;

    while (Repetidas)
    {
        // Llena el mazo con 10 cartas aleatorias de las 20 disponibles
        for (int x = 0; x < tamMazoMano; x++)
        {
            numAzarValor = rand() % tamVecValor;
            mazoValorMano[x] = vecValor[numAzarValor];
            numAzarFigura = rand() % tamVecFigura;
            mazoFiguraMano[x] = vecFigura[numAzarFigura];
        }

        // Verificar si hay cartas repetidas
        Repetidas = false;
        for (int x = 0; x < tamMazoMano; x++)
        {
            for (int i = x + 1; i < tamMazoMano; i++)
            {
                if (mazoValorMano[x] == mazoValorMano[i] && mazoFiguraMano[x] == mazoFiguraMano[i])
                {
                    Repetidas = true;
                    break; // cuando encuentra la primer repetida, sale del bucle
                }
            }
        }
    }

}

void repartirCartas(string const vecValor[], string const vecFigura[],string vecValorMano[], string vecFiguraMano[],  string vecJugadores[], int puntosJugadorUno[], int puntosJugadorDos[], int puntosAcumuladosJugadorUno, int puntosAcumuladosJugadorDos, int tamMazo)
{
    int tamVecValor = 5;
    int tamVecFigura = 4;

    /// Cargar el mazo de cartas aleatoriamente para la ronda
    cargarMazoMano(vecValor, vecFigura, vecValorMano, vecFiguraMano, tamMazo, tamVecValor, tamVecFigura);

    /// Determinar cuál es la carta embaucadora
    string embaucadora = determinarCartaEmbaucadora(vecFigura, tamVecFigura);

    // Mostrar la ronda 1
    rlutil::locate(1, 6);
    cout << "  Mazo de " << vecJugadores[0] << " (" << puntosAcumuladosJugadorUno << " puntos)";

    rlutil::locate(1, 18);
    cout << "  Mazo de " << vecJugadores[1] << " (" << puntosAcumuladosJugadorDos << " puntos)";
    ///dibujo la parte estetica de las cartas
    dibujarCartasMano(vecValorMano, vecFiguraMano, embaucadora, tamMazo);

    /// Calcular los puntajes
    calcularPuntosCartas(puntosJugadorUno, puntosJugadorDos, vecValorMano, vecFiguraMano, embaucadora);

}
// elijo al azar un carta embaucadora del mazo de figuras
string determinarCartaEmbaucadora(string const vecFigura[], int const tamVecFigura)
{
    int aleatorio= rand()%tamVecFigura;
    return vecFigura[aleatorio];
}



// se utiliza el vector de las 10 cartas de la cada mano para calcular los puntos de los jugadores
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
        else // calculo los puntos de acuerdo a la tabla
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
                puntosJugadorUno[i] = 15;
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
                puntosJugadorDos[j] = 15;
            }
            else
            {
                puntosJugadorDos[j] = 20;
            }
        }
    }
}

//funcion generica para sumar valores de vectores
int sumarVector(int vecPuntos[], int tamanio)
{
    int resultado=0;

    for (int i=0; i<tamanio; i++)
    {
        resultado +=vecPuntos[i];
    }

    return resultado;
}





bool cambiarEmbaucadora(string jugador)
{
    char respuesta;
    bool confirmacion;
    cout << jugador << " queres cambiar la carta embaucadora (te va a costar 20 puntos)? (s/n): ";
    cin >> respuesta;
    confirmacion=manejarRespuesta(respuesta,1,32);
}

void implementarCambioEmbaucadora(int ronda,string jugador, int &puntosAcumulados, const string VEC_FIGURA[], int tamFigura, string mazoValorMano[], string mazoFiguraMano[],int puntosCartasJugador[], int puntosCartasOponente[], int &puntosRondaJugador, int &puntosRondaOponente, int costo, bool &confirmacionUno, bool &confirmacionDos, int posz)
{
    string nuevaEmbaucadora;

    if(puntosAcumulados >= costo)
    {
        nuevaEmbaucadora = determinarCartaEmbaucadora(VEC_FIGURA, tamFigura);
        dibujarCarta(100, 14, " ", nuevaEmbaucadora);
        puntosAcumulados -= costo;
        if((ronda == 2 && confirmacionUno) || (ronda == 3 && confirmacionUno))
        {
            rlutil::locate(1, 6);
            cout << "  Mazo de " << jugador << " (" << puntosAcumulados << " puntos)";
            calcularPuntosCartas(puntosCartasJugador, puntosCartasOponente, mazoValorMano, mazoFiguraMano, nuevaEmbaucadora);
        }
        else  if((ronda == 2 && confirmacionDos) || (ronda == 3 && confirmacionDos))
        {

            rlutil::locate(1, 18);
            cout << "  Mazo de " << jugador << " (" << puntosAcumulados << " puntos)";
            calcularPuntosCartas(puntosCartasOponente, puntosCartasJugador, mazoValorMano, mazoFiguraMano, nuevaEmbaucadora);
        }
        puntosRondaJugador = sumarVector(puntosCartasJugador, 5) - costo;
        puntosRondaOponente = sumarVector(puntosCartasOponente, 5);
        rlutil::locate(1,posz);
    }
    else
    {
        cout << "No tienes suficientes puntos para cambiar la carta embaucadora." << endl;
    }
}

/// de acuerdo a los puntajes se determina el ganador
void determinarGanador(int vecRondaJugadorUno[], int vecRondaJugadorDos[], int puntosTotalesJugadorUno, int puntosTotalesJugadorDos, string vecJugadores[], string &jugadorMayorPuntaje, int &mayorPuntaje)
{

    if(puntosTotalesJugadorUno>puntosTotalesJugadorDos)
    {
        jugadorMayorPuntaje=vecJugadores[0];
        mayorPuntaje=puntosTotalesJugadorUno;
    }
    else if (puntosTotalesJugadorUno<puntosTotalesJugadorDos)
    {
        jugadorMayorPuntaje=vecJugadores[1];
        mayorPuntaje=puntosTotalesJugadorDos;

    }
    else
    {
        desempatar(vecRondaJugadorUno,vecRondaJugadorDos,puntosTotalesJugadorUno,puntosTotalesJugadorDos,vecJugadores,jugadorMayorPuntaje,mayorPuntaje);
    }
}

/// en caso de empate, gana el jugador que tuvo mas puntos en una ronda
void desempatar(int vecRondaJugadorUno[], int vecRondaJugadorDos[], int puntosTotalesJugadorUno, int puntosTotalesJugadorDos, string vecJugadores[], string &jugadorMayorPuntaje, int &mayorPuntaje)
{
    int mejorRondaJugadorUno=0, mejorRondaJugadorDos =0;

    for (int i =0 ; i<3; i++)
    {
        if(vecRondaJugadorUno[i]>mejorRondaJugadorUno)
        {
            mejorRondaJugadorUno=vecRondaJugadorUno[i];
        }
        if(vecRondaJugadorDos[i]>mejorRondaJugadorDos)
        {
            mejorRondaJugadorDos=vecRondaJugadorDos[i];
        }
    }

    if(mejorRondaJugadorUno>mejorRondaJugadorDos)
    {
        jugadorMayorPuntaje=vecJugadores[0];
        mayorPuntaje=puntosTotalesJugadorUno;
    }
    else if(mejorRondaJugadorUno<mejorRondaJugadorDos)
    {
        jugadorMayorPuntaje=vecJugadores[1];
        mayorPuntaje=puntosTotalesJugadorDos;
    }
    else
    {
        jugadorMayorPuntaje= "EMPATE";/// como ambos empataron en rondas y en puntos no hay ganador, es un empate
        mayorPuntaje=puntosTotalesJugadorDos; /// como ambos empataron en rondas y en puntos es indistinto que puntaje mayor se ponga
    }

}




