#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include "jugar.h"
#include "dibujos.h"

using namespace std;

void cargarNombre(string vecJugadores[])
{
    char confirmacion;

    do
    {
        dibujarEncabezado("EMBAUCADO");
        cout << "Antes de comenzar deben registrar sus nombres: " << endl << endl;

        cout << "Nombre del Jugador 1 ";
        cin.ignore();//me limpia el enter que traigo de antes de la funcion menu cuando elegí la opcion
        getline(cin, vecJugadores[0]);

        cout << "Nombre del Jugador 2 ";
        getline(cin, vecJugadores[1]);// se utiliza esta funcion para que tome nombres con los espacios en blanco


        cout << "\nConfirmar nombres (S/N): ";
        cin >> confirmacion;
        confirmacion=toupper(confirmacion);
        cout << "\n------------------------------------------------------------------------" << endl;



        while(confirmacion != 'S' && confirmacion != 'N') //para contemplar mayusculas y minusculas uso toupper
        {
            cout << "ERROR solo se admite 'S' o 'N'" << endl;
            cout << "\nConfirmar nombres (S/N): ";
            cin >> confirmacion;
            confirmacion=toupper(confirmacion);//funcion toupper me transforma el ingreso a masyucula

        }
        if(confirmacion == 'N')
        {
            cout << "Ingrese los nombres nuevamente\n";
            system("pause");
            system("cls");
        }

        system("cls");

    }
    while(confirmacion != 's' && confirmacion != 'S'); //para contemplar mayusculas y minusculas

}


void cargarMazoMano(const string vecValor[], const string vecPalos[], string mazoValorMano[], string mazoPaloMano[], int tamMazoMano, int tamVecValor, int tamVecPalo)
{
    bool Repetidas = true;
    int numAzarValor, numAzarPalo;

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
string determinarCartaEmbaucadora(string const vecFigura[], int const tamVecFigura)
{
    int aleatorio= rand()%tamVecFigura;
    return vecFigura[aleatorio];
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
int sumarVector(int vecPuntos[], int tamanio)
{
    int resultado=0;

    for (int i=0; i<tamanio; i++)
    {
        resultado +=vecPuntos[i];
    }

    return resultado;
}


void repartirCartas(string const vecValor[], string const vecFigura[],string vecValorMano[], string vecFiguraMano[],  string vecJugadores[], int puntosJugadorUno[], int puntosJugadorDos[], int puntosAcumuladosJugadorUno, int puntosAcumuladosJugadorDos, int tamMazo)
{
    const int TAM_VEC_VALOR = 5;
    const int TAM_VEC_FIGURA = 4;

    // Cargar el mazo de cartas aleatoriamente para la ronda
    cargarMazoMano(vecValor, vecFigura, vecValorMano, vecFiguraMano, tamMazo, TAM_VEC_VALOR, TAM_VEC_FIGURA);

    // Determinar cuál es la carta embaucadora
    string embaucadora = determinarCartaEmbaucadora(vecFigura, TAM_VEC_FIGURA);

    // Mostrar la ronda 1
    rlutil::locate(1, 6);
    cout << "  Mazo de " << vecJugadores[0] << " (" << puntosAcumuladosJugadorUno << " puntos)";

    rlutil::locate(1, 18);
    cout << "  Mazo de " << vecJugadores[1] << " (" << puntosAcumuladosJugadorDos << " puntos)";
    dibujarCartasMano(vecValorMano, vecFiguraMano, embaucadora, tamMazo);

    // Calcular los puntajes y mostrarlos
    calcularPuntosCartas(puntosJugadorUno, puntosJugadorDos, vecValorMano, vecFiguraMano, embaucadora);

}

void determinarGanador(int vecRondaJugadorUno[], int vecRondaJugadorDos[], int puntosTotalesJugadorUno, int puntosTotalesJugadorDos, string vecJugadores[], string &jugadorMayorPuntaje, int &mayorPuntaje){

  if(puntosTotalesJugadorUno>puntosTotalesJugadorDos){
    jugadorMayorPuntaje=vecJugadores[0];
    mayorPuntaje=puntosTotalesJugadorUno;
  }
  else if (puntosTotalesJugadorUno<puntosTotalesJugadorDos){
        jugadorMayorPuntaje=vecJugadores[1];
        mayorPuntaje=puntosTotalesJugadorDos;

  }
  else{
    desempatar(vecRondaJugadorUno,vecRondaJugadorDos,puntosTotalesJugadorUno,puntosTotalesJugadorDos,vecJugadores,jugadorMayorPuntaje,mayorPuntaje);
  }
}

void desempatar(int vecRondaJugadorUno[], int vecRondaJugadorDos[], int puntosTotalesJugadorUno, int puntosTotalesJugadorDos, string vecJugadores[], string &jugadorMayorPuntaje, int &mayorPuntaje){
 int mejorRondaJugadorUno=0, mejorRondaJugadorDos =0;

 for (int i =0 ; i<3; i++){
    if(vecRondaJugadorUno[i]>mejorRondaJugadorUno){
        mejorRondaJugadorUno=vecRondaJugadorUno[i];
    }
    if(vecRondaJugadorDos[i]>mejorRondaJugadorDos){
        mejorRondaJugadorDos=vecRondaJugadorDos[i];
    }
 }

    if(mejorRondaJugadorUno>mejorRondaJugadorDos){
        jugadorMayorPuntaje=vecJugadores[0];
        mayorPuntaje=puntosTotalesJugadorUno;
    }
    else{
        jugadorMayorPuntaje=vecJugadores[1];
        mayorPuntaje=puntosTotalesJugadorDos;
    }

}

void jugar(string &jugadorMayorPuntaje, int &mayorPuntaje)
{
    //mazos con los que se van a jugar
    const string VEC_VALOR[5] = {"10", "J", "Q", "K", "A"};
    const string VEC_FIGURA[4] = {"corazon", "diamante", "picas", "trebol"};

    //tamaños de los vectores
    const int CANT_RONDAS = 3;
    const int CANT_JUGADORES = 2;
    const int TAM_MAZO_MANO = 10;

    // creo el vector vacio para despues guardar los nombres
    string vecJugadores[CANT_JUGADORES];

    //se crean los vectores que se van a usar en cada mano
    string mazoValorMano[TAM_MAZO_MANO]; // se crean el mazo de palos
    string mazoFiguraMano[TAM_MAZO_MANO]; // se crea el mazo de figuras

    //variables para guardar los puntos
    int puntosCartasJugadorUno[5] = {0, 0, 0, 0, 0}; // vector para guardar el puntaje que suma cada una de las 5 cartas
    int puntosCartasJugadorDos[5] = {0, 0, 0, 0, 0}; // vector para guardar el puntaje que suma cada una de las 5 cartas
    int puntosRondaJugadorUno[CANT_RONDAS] = {0, 0, 0}; // vector para guardar el puntaje individual de cada ronda jug 1
    int puntosRondaJugadorDos[CANT_RONDAS] = {0, 0, 0}; // vector para guardar el puntaje individual de cada ronda jug 1
    int puntosAcumuladosJugadorUno = 0; // acumular los puntajes de cada ronda para el jugador 1
    int puntosAcumuladosJugadorDos = 0; // acumular los puntajes de cada ronda para el jugador 2

    //variables para las rondas 2 y 3
    char respuesta;
    string nuevaEmbacaudora;

    //implementacion del juego 1° pido los nombres
    cargarNombre(vecJugadores);

    //2° se utiliza un ciclo for para implementar la logica de cada una de las rondas
    for (int ronda = 1; ronda <= CANT_RONDAS; ronda++)
    {
        dibujarEncabezado("EMBAUCADO");
        centrarTexto(3, "Ronda #" + to_string(ronda));
        centrarTexto(4, vecJugadores[0] + " VS " + vecJugadores[1]);
        string embaucadora;

        // Funcionalidad específica para cada ronda
        switch (ronda)
        {
            //primera ronda, solo se reparten las cartas y se muestran los puntos
            case 1:
                repartirCartas(VEC_VALOR, VEC_FIGURA, mazoValorMano, mazoFiguraMano, vecJugadores, puntosCartasJugadorUno, puntosCartasJugadorDos, puntosAcumuladosJugadorUno, puntosAcumuladosJugadorDos, TAM_MAZO_MANO);
                cout << "Para ver el puntaje presione una tecla ";
                rlutil::anykey();
                mostrarEstadistica(puntosCartasJugadorUno, puntosCartasJugadorDos);
                cout << endl;
                puntosRondaJugadorUno[ronda - 1] = sumarVector(puntosCartasJugadorUno, 5);
                puntosRondaJugadorDos[ronda - 1] = sumarVector(puntosCartasJugadorDos, 5);
                puntosAcumuladosJugadorUno = sumarVector(puntosRondaJugadorUno, 3);
                puntosAcumuladosJugadorDos = sumarVector(puntosRondaJugadorDos, 3);
                dibujarResultadosPorRonda(vecJugadores, puntosRondaJugadorUno, puntosRondaJugadorDos, puntosAcumuladosJugadorUno, puntosAcumuladosJugadorDos);
                break;

            //antes de mostrar los puntos se pregunta al jugador 1 si quiere cambiar la carta embaucadora
            case 2:
                repartirCartas(VEC_VALOR, VEC_FIGURA, mazoValorMano, mazoFiguraMano, vecJugadores, puntosCartasJugadorUno, puntosCartasJugadorDos, puntosAcumuladosJugadorUno, puntosAcumuladosJugadorDos, TAM_MAZO_MANO);
                cout << vecJugadores[0] << " Queres cambiar la carta embaucadora (te va a costar 20 puntos)? (s/n): ";
                cin >> respuesta;
                while (toupper(respuesta) != 'S' && toupper(respuesta) != 'N')
                {
                    rlutil::locate(1, 30);
                    cout << "Opcion invalida. Por favor ingrese 's' para Si o 'n' para No: ";
                    cin >> respuesta;
                }
                if (toupper(respuesta) == 'S')
                {
                    if(puntosAcumuladosJugadorUno>=20){
                    nuevaEmbacaudora = determinarCartaEmbaucadora(VEC_FIGURA, 4);
                    dibujarCarta(100, 14, " ", nuevaEmbacaudora);
                    puntosAcumuladosJugadorUno -= 20;
                    rlutil::locate(1, 6);
                    cout << "  Mazo de " << vecJugadores[0] << " (" << puntosAcumuladosJugadorUno << " puntos)";
                    calcularPuntosCartas(puntosCartasJugadorUno, puntosCartasJugadorDos, mazoValorMano, mazoFiguraMano, nuevaEmbacaudora);
                    puntosRondaJugadorUno[ronda - 1] = sumarVector(puntosCartasJugadorUno, 5) - 20; // le resto al jugador 1 los 20 puntos de la embaucadora
                    puntosRondaJugadorDos[ronda - 1] = sumarVector(puntosCartasJugadorDos, 5);
                    }
                    else{
                        cout << "No tienes suficientes puntos para cambiar la carta embaucadora." << endl;
                    }
                }


                else
                {
                    cout << vecJugadores[1] << " Queres cambiar la carta embaucadora (te va a costar 20 puntos)? (s/n): ";
                    cin >> respuesta;
                    if (respuesta == 's' || respuesta == 'S')
                    {
                        nuevaEmbacaudora = determinarCartaEmbaucadora(VEC_FIGURA, 4);
                        dibujarCarta(100, 14, " ", nuevaEmbacaudora);
                        puntosAcumuladosJugadorDos -= 20;
                        rlutil::locate(1, 18);
                        cout << "  Mazo de " << vecJugadores[1] << " (" << puntosAcumuladosJugadorDos << " puntos)";
                        calcularPuntosCartas(puntosCartasJugadorUno, puntosCartasJugadorDos, mazoValorMano, mazoFiguraMano, nuevaEmbacaudora);
                    puntosRondaJugadorUno[ronda - 1] = sumarVector(puntosCartasJugadorUno, 5);
                    puntosRondaJugadorDos[ronda - 1] = (sumarVector(puntosCartasJugadorDos, 5) - 20); // le resto al jugador 2 los 20 puntos de la embaucadora
                    }
                    else{

                    puntosRondaJugadorUno[ronda - 1] = sumarVector(puntosCartasJugadorUno, 5);
                    puntosRondaJugadorDos[ronda - 1] = sumarVector(puntosCartasJugadorDos, 5);
                    }
                }
                rlutil::locate(1, 29);
                cout << "\nPara ver el puntaje presione una tecla ";
                rlutil::anykey();
                mostrarEstadistica(puntosCartasJugadorUno, puntosCartasJugadorDos);
                puntosAcumuladosJugadorUno = sumarVector(puntosRondaJugadorUno, 3);
                puntosAcumuladosJugadorDos = sumarVector(puntosRondaJugadorDos, 3);
                dibujarResultadosPorRonda(vecJugadores, puntosRondaJugadorUno, puntosRondaJugadorDos, puntosAcumuladosJugadorUno, puntosAcumuladosJugadorDos);
                break;

            case 3:
                repartirCartas(VEC_VALOR, VEC_FIGURA, mazoValorMano, mazoFiguraMano, vecJugadores, puntosCartasJugadorUno, puntosCartasJugadorDos, puntosAcumuladosJugadorUno, puntosAcumuladosJugadorDos, TAM_MAZO_MANO);
                cout << vecJugadores[1] << " Queres cambiar la carta embaucadora (te va a costar 20 puntos)? (s/n): ";
                cin >> respuesta;
                if (respuesta == 's' || respuesta == 'S')
                {
                    nuevaEmbacaudora = determinarCartaEmbaucadora(VEC_FIGURA, 4);
                    dibujarCarta(100, 14, " ", nuevaEmbacaudora);
                    puntosAcumuladosJugadorDos -= 20;
                    rlutil::locate(1, 18);
                    cout << "  Mazo de " << vecJugadores[1] << " (" << puntosAcumuladosJugadorDos << " puntos)";
                    calcularPuntosCartas(puntosCartasJugadorUno, puntosCartasJugadorDos, mazoValorMano, mazoFiguraMano, nuevaEmbacaudora);
                    puntosRondaJugadorUno[ronda - 1] = sumarVector(puntosCartasJugadorUno, 5);
                    puntosRondaJugadorDos[ronda - 1] = sumarVector(puntosCartasJugadorDos, 5)-20;
                }
                else
                {
                    cout << vecJugadores[0] << " Queres cambiar la carta embaucadora (te va a csotar 20 puntos)? (s/n): ";
                    cin >> respuesta;
                    if (respuesta == 's' || respuesta == 'S')
                    {
                        nuevaEmbacaudora = determinarCartaEmbaucadora(VEC_FIGURA, 4);
                        dibujarCarta(100, 14, " ", nuevaEmbacaudora);
                        puntosAcumuladosJugadorUno -= 20;
                        rlutil::locate(1, 6);
                        cout << "  Mazo de " << vecJugadores[0] << " (" << puntosAcumuladosJugadorUno << " puntos)";
                        calcularPuntosCartas(puntosCartasJugadorUno, puntosCartasJugadorDos, mazoValorMano, mazoFiguraMano, nuevaEmbacaudora);
                        puntosRondaJugadorUno[ronda - 1] = sumarVector(puntosCartasJugadorUno, 5)-20;
                        puntosRondaJugadorDos[ronda - 1] = sumarVector(puntosCartasJugadorDos, 5);
                    }
                    else{
                        puntosRondaJugadorUno[ronda - 1] = sumarVector(puntosCartasJugadorUno, 5);
                        puntosRondaJugadorDos[ronda - 1] = sumarVector(puntosCartasJugadorDos, 5);
                    }
                }
                rlutil::locate(1, 29);
                cout << "\nPara ver el puntaje presione una tecla ";
                rlutil::anykey();
                mostrarEstadistica(puntosCartasJugadorUno, puntosCartasJugadorDos);
                determinarGanador(puntosRondaJugadorUno,puntosRondaJugadorDos,puntosAcumuladosJugadorUno,puntosAcumuladosJugadorDos,vecJugadores,jugadorMayorPuntaje,mayorPuntaje);
                puntosAcumuladosJugadorUno = sumarVector(puntosRondaJugadorUno, 3);
                puntosAcumuladosJugadorDos = sumarVector(puntosRondaJugadorDos, 3);
                dibujarResultadosPorRonda(vecJugadores, puntosRondaJugadorUno, puntosRondaJugadorDos, puntosAcumuladosJugadorUno, puntosAcumuladosJugadorDos);
                dibujarGanador(jugadorMayorPuntaje,mayorPuntaje);
                break;
        }

        rlutil::anykey();
        rlutil::cls();
    }



}


