#pragma once

///funciones generales
void dibujarEncabezado(std::string texto);
void centrarTexto(int y, std::string texto);

///para los creditos, estad�sticas y pntaje por ronda
void dibujarRecuadro(int x, int y, int ancho, int alto);

///funciones est�ticas de cartas
void dibujarEstructuraCarta(int posx, int posy, int ancho, int alto);
void dibujarValorCarta(int posx, int posy, std::string valor);
void dibujarFiguraCarta(int posx, int posy, int palo);
int convertirPalo(const std::string &palo);
void dibujarCarta(int posx, int posy, std::string valor, std::string palo);
void dibujarCartasMano(std::string mazoValorMano[], std::string mazoFiguraMano[], std::string embaucadora, int tamMazo);

///funciones est�ticas de puntos
void mostrarPuntaje(int puntosJugadorUno[], int puntosJugadorDos[]);
void dibujarResultadosPorRonda(std::string vecJugadores[],int vecCartasJugadorUno[],int vecCartasJugadorDos[], int totalUno, int totalDos);
void dibujarGanador(std::string nombreGanador, int puntajeGanador);
