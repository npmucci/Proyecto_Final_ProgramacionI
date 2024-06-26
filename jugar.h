#pragma once

///funcion para cargar nombres
void cargarNombre();

//funciones para gestionar los mazos y la mebaucadora
void cargarMazoMano(const std::string vecValor[], const std::string vecPalos[], std::string mazoValorMano[], std::string mazoPaloMano[], int tamMazoMano, int tamVecValor, int tamVecPalo);
std::string determinarCartaEmbaucadora(std::string vecFigura[], int tamVecFigura);

///funciones para para las rondas y puntos
void calcularPuntosCartas(int puntosJugadorUno[], int puntosJugadorDos[], std::string vecValor[], std::string vecFigura[], std::string embaucadora);
int sumarVector(int vecPuntos[], int tamanio);
void repartirCartas(std::string const vecValor[], std::string const vecFigura[], std::string vecValorMano[], std::string vecFiguraMano[], std::string vecJugadores[], int puntosJugadorUno[], int puntosJugadorDos[], int puntosAcumuladosJugadorUno, int puntosAcumuladosJugadorDos);

///funcion principal
void jugar(std::string &nombreGanador, int &puntajeGanador, std::string &jugadorMejorPuntaje, int &mejorPuntaje);

///funcion para determinar el ganador
void determinarGanador(int vecRondaJugadorUno[], int vecRondaJugadorDos[], int puntosTotalesJugadorUno, int puntosTotalesJugadorDos, std::string vecJugadores[], std::string &jugadorMayorPuntaje, int &mayorPuntaje);
void desempatar(int vecRondaJugadorUno[], int vecRondaJugadorDos[], int puntosTotalesJugadorUno, int puntosTotalesJugadorDos, std::string vecJugadores[], std::string &jugadorMayorPuntaje, int &mayorPuntaje);















