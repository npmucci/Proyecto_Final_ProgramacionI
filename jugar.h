#pragma once

void cargarNombre();
void cargarMazoMano(const std::string vecValor[], const std::string vecPalos[], std::string mazoValorMano[], std::string mazoPaloMano[], int tamMazoMano, int tamVecValor, int tamVecPalo);
std::string determinarCartaEmbaucadora(std::string vecFigura[], int tamVecFigura);
void calcularPuntosCartas(int puntosJugadorUno[], int puntosJugadorDos[], std::string vecValor[], std::string vecFigura[], std::string embaucadora);
int sumarVector(int vecPuntos[], int tamanio);
void implementarRonda(std::string const vecValor[], std::string const vecFigura[], std::string vecValorMano[], std::string vecFiguraMano[], std::string vecJugadores[], int puntosJugadorUno[], int puntosJugadorDos[], int puntosAcumuladosJugadorUno, int puntosAcumuladosJugadorDos);
void jugar(std::string &nombreJugador, int &mayorPuntaje);















