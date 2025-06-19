#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "structs.h"
#include <string>
int lanzarDados(int cantDados, int& num_bugs_en_tirada, int& num_fixes_en_tirada);

void menuCreditos();

void confirmarSalir(char confirm, int& eleccion );

void cartelDeError();

void armarDadoRandom(char linea1[],char linea2[],char linea3[],char linea4[],char linea5[], int numero);

void menuEstadistica(const std::string& ganador, const int& puntoGanador, Ranking ganadores[5]);

void cargaranking(Ranking jugadores[5]);

void iniciarJuego(Jugador jugadores[2],std::string& ganador, int& puntoGanador,Ranking ganadores[5]);

void manejarTurnoJugador(Jugador& jugador_actual, int ronda_actual);

void menuPrincipal();

int simularLanzamiento(int valor_dado_fijo, int cantDados, int& num_bugs_en_tirada, int& num_fixes_en_tirada);
int simularLanzamiento3Fixes(int& num_bugs_en_tirada, int& num_fixes_en_tirada);
int simularLanzamiento3Bugs(int& num_bugs_en_tirada, int& num_fixes_en_tirada);


#endif // GAME_LOGIC_H
