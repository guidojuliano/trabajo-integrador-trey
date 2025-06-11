#ifndef PLAYER_MANAGEMENT_H
#define PLAYER_MANAGEMENT_H

#include "structs.h"

// Declaración de la función para registrar jugadores

void registrarNombresJugadores(std::Jugador jugadores[2]);
void asignarCartaYPT(Jugador& jugador);
void mostrarCartaYPTInicial(const Jugador& jugador);


#endif // PLAYER_MANAGEMENT_H
