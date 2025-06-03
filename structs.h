#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>

// Definicion de las estructuras
struct Jugador {
    std::string nombre;
    int puntos_tiempo;
    int bugs_acumulados;
    int puntos_total_partida;
    int carta_objetivo;
    int puntos_ronda_actual;
    int lanzamientos_en_ronda;
    bool llego_a_cero_bugs_alguna_vez;
    bool acumulo_20_puntos_sin_bugs_alguna_vez;
};
#endif
