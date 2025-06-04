#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H
#include <vector>
#include "structs.h"
int lanzarDados(int cantDados, int& num_bugs_en_tirada, int& num_fixes_en_tirada);

void menuCreditos();

void confirmarSalir(char confirm, int& eleccion );

void cartelDeError();

void armarDadoRandom(char linea1[],char linea2[],char linea3[],char linea4[],char linea5[], int numero);

void menuEstadistica();

void iniciarJuego(std::vector<Jugador>& jugadores);

void manejarTurnoJugador(Jugador& jugador_actual, Jugador& jugador_oponente);

void menuPrincipal();



#endif // GAME_LOGIC_H
