#pragma once

void dibujarEncabezado(std::string texto);
void centrarTexto(int y, std::string texto);
void dibujarRecuadro(int x, int y, int ancho, int alto);
void dibujarEstructuraCarta(int posx, int posy, int ancho, int alto);
void dibujarValorCarta(int posx, int posy, std::string valor);
void dibujarPaloCarta(int posx, int posy, int palo);
int convertirPalo(const std::string &palo);
void dibujarCarta(int posx, int posy, std::string valor, std::string palo);
void dibujarCartasMano(std::string mazoValorMano[], std::string mazoFiguraMano[], std::string embaucadora, int tamMazo);
void mostrarPuntaje(int puntosJugadorUno[], int puntosJugadorDos[]);
void dibujarResultadosPorRonda(std::string vecJugadores[],int vecCartasJugadorUno[],int vecCartasJugadorDos[], int totalUno, int totalDos);
void dibujarGanador(std::string nombreGanador, int puntajeGanador);
