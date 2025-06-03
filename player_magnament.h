#ifndef PLAYER_MANAGEMENT_H
#define PLAYER_MANAGEMENT_H

#include "structs.h"
#include <vector>

// Declaraci�n de la funci�n para registrar jugadores

void registrarNombresJugadores(std::vector<Jugador>& jugadores);
void asignarCartaYPT(Jugador& jugador);
void mostrarCartaYPTInicial(const Jugador& jugador);


#endif // PLAYER_MANAGEMENT_H
