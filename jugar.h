#pragma once

void cargarNombre();
void cargarMazoMano(const std::string vecValor[], const std::string vecPalos[], std::string mazoValorMano[], std::string mazoPaloMano[], int tamMazoMano, int tamVecValor, int tamVecPalo);
void dibujarEstructuraCarta(int posx, int posy, int ancho, int alto);
void dibujarValorCarta(int posx, int posy, std::string valor);
void dibujarPaloCarta(int posx, int posy, int palo);
int convertirPalo(const std::string &palo);
void dibujarCarta(int posx, int posy, std::string valor, std::string palo);
void dibujarCartaEmbaucadora();
void repartirCartas(std::string vecJugadores);
void jugar(std::string vecJugadores[]);















