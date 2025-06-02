#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <windows.h>
#include <cctype>
#include <cstdlib>
#include "player_magnament.h"
using namespace std;

void registrarNombresJugadores(std::vector<Jugador>& jugadores) {
    string nombre_temporal;
    char confirmacion;
    bool nombres_confirmados = false;

    if (jugadores.size() != 2) {
        jugadores.resize(2);
    }

    do {
        system("cls");
        cout << "\nTREY\n";
        cout << "--------------------------------------\n";
        cout << "Antes de comenzar deben registrar sus nombres:\n\n";

        cout << "¿Nombre jugador 1? ";
        cin >> jugadores[0].nombre;
        cout << "¿Nombre jugador 2? ";
        cin >> jugadores[1].nombre;

        cout << "\nNombres registrados:\n";
        cout << "Jugador 1: " << jugadores[0].nombre << "\n";
        cout << "Jugador 2: " << jugadores[1].nombre << "\n";

        cout << "\n¿Confirmar nombres? (S/N) ";
        cin >> confirmacion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        confirmacion = toupper(confirmacion);

        if (confirmacion == 'S') {
            nombres_confirmados = true;

            asignarCartaYPT(jugadores[0]);
            asignarCartaYPT(jugadores[1]);

            system("cls");
            cout << "\n--- ASIGNACION DE CARTAS Y PT ---\n";
            mostrarCartaYPTInicial(jugadores[0]);
            mostrarCartaYPTInicial(jugadores[1]);
            cout << "\nPresione cualquier tecla para continuar...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        } else if (confirmacion != 'N') {
            cout << "Respuesta invalida. Por favor, ingrese 'S' o 'N'.\n";
            Sleep(1500);
        }
    } while (!nombres_confirmados);

    cout << "\nNombres confirmados! El juego esta listo para iniciar.\n";
    Sleep(1500);
}

void asignarCartaYPT(Jugador& jugador) {
    jugador.carta_objetivo = rand() % 16 + 50;

    if (jugador.carta_objetivo >= 50 && jugador.carta_objetivo <= 55) {
        jugador.puntos_tiempo = 7;
    } else if (jugador.carta_objetivo >= 56 && jugador.carta_objetivo <= 60) {
        jugador.puntos_tiempo = 8;
    } else { // 61-65
        jugador.puntos_tiempo = 9;
    }

    jugador.bugs_acumulados = 0;
    jugador.puntos_total_partida = 0;
    jugador.puntos_ronda_actual = 0;
    jugador.lanzamientos_en_ronda = 0;
    jugador.llego_a_cero_bugs_alguna_vez = false;
    jugador.acumulo_20_puntos_sin_bugs_alguna_vez = false;
}

void mostrarCartaYPTInicial(const Jugador& jugador) {
    std::cout << "\n--- " << jugador.nombre << " ---\n";
    std::cout << "Carta de Proyecto: " << jugador.carta_objetivo << "\n";
    std::cout << "Puntos de Tiempo (PT) iniciales: " << jugador.puntos_tiempo << "\n";
    std::cout << "--------------------------------\n";
}
