
#include "game_logic.h"
#include <vector>
#include <iostream>
#include <windows.h>
#include <limits>
#include<cstdlib> // para numeros random
#include <ctime>
#include <cstring>
#include "player_magnament.h"

using namespace std;

void armarDadoRandom(char linea1[],char linea2[],char linea3[],char linea4[],char linea5[], int numero){


  switch(numero){
    case 1:{

      strcpy(linea1," ┌───────┐ ");
      strcpy(linea2," |       | ");
      strcpy(linea3," |   x   | ");
      strcpy(linea4," |       | ");
      strcpy(linea5," └───────┘ ");


     break;
    }

    case 2:{
      strcpy(linea1," ┌───────┐ ");
      strcpy(linea2," | x     | ");
      strcpy(linea3," |       | ");
      strcpy(linea4," |     x | ");
      strcpy(linea5," └───────┘ ");

     break;
    }

    case 3:{

      strcpy(linea1," ┌───────┐ ");
      strcpy(linea2," | x     | ");
      strcpy(linea3," |   x   | ");
      strcpy(linea4," |     x | ");
      strcpy(linea5," └───────┘ ");

     break;
    }

    case 4:{
      strcpy(linea1," ┌───────┐ ");
      strcpy(linea2," | x   x | ");
      strcpy(linea3," |       | ");
      strcpy(linea4," | x   x | ");
      strcpy(linea5," └───────┘ ");

     break;
    }

    case 5:{
      strcpy(linea1," ┌───────┐ ");
      strcpy(linea2," | x   x | ");
      strcpy(linea3," |   x   | ");
      strcpy(linea4," | x   x | ");
      strcpy(linea5," └───────┘ ");
     break;
    }

    case 6:{
      strcpy(linea1," ┌───────┐ ");
      strcpy(linea2," | x   x | ");
      strcpy(linea3," | x   x | ");
      strcpy(linea4," | x   x | ");
      strcpy(linea5," └───────┘ ");
     break;
    }
  }
}



int lanzarDados(int cantDados, int& num_bugs_en_tirada, int& num_fixes_en_tirada) {
    int puntos_obtenidos_tirada = 0;
    num_bugs_en_tirada = 0;   // Inicializamos a cero
    num_fixes_en_tirada = 0;  // Inicializamos a cero

    char fila1[500] = "";
    char fila2[500] = "";
    char fila3[500] = "";
    char fila4[500] = "";
    char fila5[500] = "";

    std::cout << "\nLanzando " << cantDados << " dados...\n";
    Sleep(1000); // Pequeña pausa dramática

    for(int i = 0; i < cantDados; i++) {
        char lin1[30], lin2[30], lin3[30], lin4[30], lin5[30];
        int numero_dado = rand() % 6 + 1; // Genera un número entre 1 y 6

        // Procesar el resultado del dado
        switch (numero_dado) {
            case 1:
            case 2:
            case 3:
                puntos_obtenidos_tirada += numero_dado; // Caras 1, 2, 3 suman puntos
                break;
            case 4:
                num_fixes_en_tirada++; // Cara 4 es 1 FIX
                break;
            case 5:
                num_bugs_en_tirada++; // Cara 5 es 1 BUG
                break;
            case 6:
                num_bugs_en_tirada += 2; // Cara 6 es 2 BUGS
                break;
        }

        armarDadoRandom(lin1, lin2, lin3, lin4, lin5, numero_dado);

        strcat(fila1, lin1); strcat(fila1, "  ");
        strcat(fila2, lin2); strcat(fila2, "  ");
        strcat(fila3, lin3); strcat(fila3, "  ");
        strcat(fila4, lin4); strcat(fila4, "  ");
        strcat(fila5, lin5); strcat(fila5, "  ");
    }

    system("cls"); // Limpia la consola
    std::cout << "\n\n\n";
    std::cout << "  " << fila1 << std::endl;
    std::cout << "  " << fila2 << std::endl;
    std::cout << "  " << fila3 << std::endl;
    std::cout << "  " << fila4 << std::endl;
    std::cout << "  " << fila5 << std::endl;
    std::cout << std::endl;

    std::cout << "  Puntos obtenidos: " << puntos_obtenidos_tirada << std::endl;
    std::cout << "  Bugs obtenidos:   " << num_bugs_en_tirada << std::endl;
    std::cout << "  Fixes obtenidos:  " << num_fixes_en_tirada << std::endl;
    std::cout << std::endl << std::endl;

    system("pause");
    //system("cls");

    return puntos_obtenidos_tirada;
}

void iniciarJuego(std::vector<Jugador>& jugadores) {
    const int MAX_RONDAS = 10;

    std::cout << "\n--- INICIO DE LA PARTIDA ---\n";


    for (int ronda_actual = 1; ronda_actual <= MAX_RONDAS; ronda_actual++) {
        system("cls");
        std::cout << "\n=============== RONDA " << ronda_actual << " ===============\n";

        // Turno del Jugador 1
        std::cout << "\n--- Turno de " << jugadores[0].nombre << " ---\n";
        manejarTurnoJugador(jugadores[0], jugadores[1]); // Esta es otra función clave que crearemos

        // Comprobar si el juego ha terminado después del turno del jugador 1 (ej. si alcanzó los puntos objetivo)
        if (jugadores[0].puntos_total_partida >= jugadores[0].carta_objetivo ||
            jugadores[1].puntos_total_partida >= jugadores[1].carta_objetivo) {
            std::cout << "\n¡Juego terminado por objetivo alcanzado!\n";
            break; // Sale del bucle de rondas
        }

        // Turno del Jugador 2
        std::cout << "\n--- Turno de " << jugadores[1].nombre << " ---\n";
        manejarTurnoJugador(jugadores[1], jugadores[0]); // Pasa al otro jugador como oponente

        // Comprobar si el juego ha terminado después del turno del jugador 2
        if (jugadores[0].puntos_total_partida >= jugadores[0].carta_objetivo ||
            jugadores[1].puntos_total_partida >= jugadores[1].carta_objetivo) {
            std::cout << "\n¡Juego terminado por objetivo alcanzado!\n";
            break; // Sale del bucle de rondas
        }

        // Aquí podrías añadir una pausa al final de cada ronda
        std::cout << "\nFin de la Ronda " << ronda_actual << ". Presione Enter para la siguiente ronda...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

    // Una vez que el bucle de rondas termina (por max_rondas o por objetivo)
    std::cout << "\n--- PARTIDA FINALIZADA ---\n";
    // Aquí deberías llamar a una función para determinar y mostrar el ganador
    // y las estadísticas finales (ej. mostrarEstadisticasFinales(jugadores);)
}

void manejarTurnoJugador(Jugador& jugador_actual, Jugador& jugador_oponente) {
    int opcion_turno;
    bool turno_finalizado = false;
    int dados_a_lanzar = 3; // El primer lanzamiento SIEMPRE es con 3 dados
    bool primer_lanzamiento_del_turno = true; // Flag para controlar el primer lanzamiento

    // Reiniciar puntos_ronda_actual y lanzamientos_en_ronda para el turno actual
    jugador_actual.puntos_ronda_actual = 0;
    jugador_actual.lanzamientos_en_ronda = 0;

    do {
        system("cls");
        std::cout << "\n--- " << jugador_actual.nombre << "'s Turno ---\n";
        std::cout << "  PT: " << jugador_actual.puntos_tiempo << " | Bugs: " << jugador_actual.bugs_acumulados;
        std::cout << " | Puntos Ronda: " << jugador_actual.puntos_ronda_actual << "\n";
        std::cout << "  Puntos Totales: " << jugador_actual.puntos_total_partida << " | Carta Objetivo: " << jugador_actual.carta_objetivo << "\n\n";

        // Menú de opciones para el turno
        std::cout << "1. Lanzar dados\n"; // Esta opción gestionará si son 2 o 3 dados
        std::cout << "2. Plantarse\n";
        std::cout << "3. Usar FIX (TODO)\n";
        std::cout << "Elija una opcion: ";
        std::cin >> opcion_turno;

        switch(opcion_turno) {
            case 1: {
                if (jugador_actual.puntos_tiempo <= 0) {
                    std::cout << "\nNo tienes Puntos de Tiempo (PT) disponibles para lanzar.\n";
                    std::cout << "Debes plantarte o usar FIX (si aplica).\n";
                    system("pause");
                    break; // Vuelve al menú del turno
                }

                // Determinar cuántos dados lanzar
                if (primer_lanzamiento_del_turno) {
                    dados_a_lanzar = 3;
                    primer_lanzamiento_del_turno = false; // Ya no es el primer lanzamiento
                    std::cout << "\nLanzarás 3 dados por ser el primer lanzamiento del turno.\n";
                    system("pause");
                } else {
                    // Preguntar al jugador cuántos dados quiere lanzar (2 o 3)
                    int eleccion_dados;
                    bool eleccion_valida = false;
                    do {
                        system("cls"); // Limpiar para la elección de dados
                        std::cout << "\n--- " << jugador_actual.nombre << "'s Turno ---\n";
                        std::cout << "PT: " << jugador_actual.puntos_tiempo << "\n";
                        std::cout << "¿Cuántos dados quieres lanzar? (2 o 3): ";
                        std::cin >> eleccion_dados;
                        if (std::cin.fail() || (eleccion_dados != 2 && eleccion_dados != 3)) {
                            std::cin.clear(); // Limpiar flags de error
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer
                            std::cout << "Entrada invalida. Por favor, ingresa 2 o 3.\n";
                            Sleep(1500);
                        } else {
                            eleccion_valida = true;
                        }
                    } while (!eleccion_valida);
                    dados_a_lanzar = eleccion_dados;
                }

                // Gastar 1 PT por lanzamiento
                jugador_actual.puntos_tiempo--;
                std::cout << "\nHas gastado 1 PT. PT restantes: " << jugador_actual.puntos_tiempo << "\n";
                system("pause");

                int puntos_tirada;
                int bugs_tirada;
                int fixes_tirada;

                puntos_tirada = lanzarDados(dados_a_lanzar, bugs_tirada, fixes_tirada);

                // Aplicar reglas de la tirada:
                jugador_actual.puntos_ronda_actual += puntos_tirada;
                jugador_actual.bugs_acumulados += bugs_tirada;
                jugador_actual.bugs_acumulados -= fixes_tirada;
                if (jugador_actual.bugs_acumulados < 0) {
                    jugador_actual.bugs_acumulados = 0;
                }

                jugador_actual.lanzamientos_en_ronda++;

                // **Verificación de penalización por BUGS** (revisar reglas exactas del PDF)
                // Si acumula 3 o más BUGS, se planta automáticamente y pierde puntos de la ronda
                if (jugador_actual.bugs_acumulados >= 3) {
                    std::cout << "\n¡" << jugador_actual.nombre << " ha acumulado 3 o mas BUGS! Pierde los puntos de esta ronda (" << jugador_actual.puntos_ronda_actual << ").\n";
                    jugador_actual.puntos_ronda_actual = 0; // Pierde los puntos de la ronda
                    jugador_actual.bugs_acumulados = 0; // Se resetean los bugs (o según regla si se mantienen)
                    turno_finalizado = true; // El turno termina forzosamente
                    system("pause");
                }
                break;
            }
            case 2:
                // Plantarse: sumar puntos de la ronda al total
                jugador_actual.puntos_total_partida += jugador_actual.puntos_ronda_actual;
                std::cout << "\n" << jugador_actual.nombre << " se planta. Puntos de esta ronda: " << jugador_actual.puntos_ronda_actual << ".\n";
                turno_finalizado = true;
                system("pause");
                break;
            case 3:
                // Lógica para usar FIX (si tienes implementado un contador de FIXES en Jugador)
                // Tendrías que añadir un contador de FIXES a la struct Jugador
                // y lógica para descontarlos aquí.
                std::cout << "\nFuncionalidad 'Usar FIX' no implementada aun. (Requiere FIXES acumulados).\n";
                system("pause");
                break;
            default:
                std::cout << "\nOpcion invalida. Intente de nuevo.\n";
                Sleep(1000);
                break;
        }

        // Si el jugador se queda sin PT y no se ha plantado/forzado el fin de turno
        if (jugador_actual.puntos_tiempo <= 0 && !turno_finalizado) {
             std::cout << "\n¡" << jugador_actual.nombre << " se ha quedado sin Puntos de Tiempo (PT)!\n";
             std::cout << "Debes plantarte (opcion 2) para terminar tu turno.\n";
             // Se forza al jugador a plantarse si no tiene PT
             // O podrías forzar el turno a terminar aquí si las reglas lo indican.
             // Para simplificar, lo dejo que el usuario elija plantarse manualmente.
             system("pause");
        }

    } while (!turno_finalizado); // El bucle continúa hasta que el turno finalice

    std::cout << "\nTurno de " << jugador_actual.nombre << " finalizado.\n";
    Sleep(1000); // Pequeña pausa antes de pasar al siguiente turno/ronda
}

void menuCreditos(){

  cout<<endl<<endl;

  cout<<"   ╔═══════════════════════════════════════════════════════════════════════════════════╗"<<endl;
  cout<<"   ║                                                                                   ║"<<endl;
  cout<<"   ║   CREDITOS                                                                        ║"<<endl;
  cout<<"   ║                                                                                   ║"<<endl;
  cout<<"   ║                                                                                   ║"<<endl;
  cout<<"   ║                                                                                   ║"<<endl;
  cout<<"   ║                  ┌──────────┬──────────────────────────────────┐                  ║"<<endl;
  cout<<"   ║                  │  lEGAJO  │   NOMBRE Y APELLIDO              │                  ║"<<endl;
  cout<<"   ║                  ├──────────┼──────────────────────────────────┤                  ║"<<endl;
  cout<<"   ║                  │          │                                  │                  ║"<<endl;
  cout<<"   ║                  │   33063  │  Cristian Sebastian Gonzalez     │                  ║"<<endl;
  cout<<"   ║                  │          │                                  │                  ║"<<endl;
  cout<<"   ║                  │   32311  │  Guido Juliano Mazzuchini Ubaldi │                  ║"<<endl;
  cout<<"   ║                  │          │                                  │                  ║"<<endl;
  cout<<"   ║                  │   32396  │  Ismael Valentin Aleman          │                  ║"<<endl;
  cout<<"   ║                  │          │                                  │                  ║"<<endl;
  cout<<"   ║                  └──────────┴──────────────────────────────────┘                  ║"<<endl;
  cout<<"   ║                                                                                   ║"<<endl;
  cout<<"   ║                                                                                   ║"<<endl;
  cout<<"   ║                                                                                   ║"<<endl;
  cout<<"   ║                                                                                   ║"<<endl;
  cout<<"   ║                                                                                   ║"<<endl;
  cout<<"   ║            Copyright (C) TREYANOS Corporation. All rights reserved.               ║"<<endl;
  cout<<"   ╚═══════════════════════════════════════════════════════════════════════════════════╝"<<endl;

  cout<<endl;
}


void confirmarSalir(char confirm , int& eleccion){
      if(confirm== 'S' || confirm=='N'){
          if(confirm=='S'){
            return ;
          }else{
            eleccion=4;
            return;
            }
      }else{
          cout<<endl<<" eleccion incorrecta vuelva a intentar"<<endl;
      }

}


void cartelDeError(){
  system("cls");
    cout<<endl<<endl;

        cout<<" ┌--------------------------------------------┐"<<endl;
        cout<<" |                                            |"<<endl;
        cout<<" |  eleccion incorrecta, vuelva a intentar!!  |"<<endl;
        cout<<" |                                            |"<<endl;
        cout<<" └--------------------------------------------┘"<<endl;


}


void menuEstadistica(){
  system("cls");
cout<<endl<<endl;

  cout<<"                                                                                        "<<endl;
  cout<<"                                                                                        "<<endl;
  cout<<"   TREY                                                                                 "<<endl;
  cout<<"   ------------------------------------------------------------                         "<<endl;
  cout<<"                                                                                        "<<endl;
  cout<<"   HITO                                                                                 "<<endl;
  cout<<"   ------------------------------------------------------------                         "<<endl;
  cout<<"   Puntos                                                                               "<<endl;
  cout<<"   BUGS                                                                                 "<<endl;
  cout<<"   Tiempo                                                                               "<<endl;
  cout<<"   Menor BUGS                                                                           "<<endl;
  cout<<"   Llegar a 0 BUGS                                                                      "<<endl;
  cout<<"   Acumular 20 puntos                                                                   "<<endl;
  cout<<"   ------------------------------------------------------------                         "<<endl;
  cout<<"   TOTAL                                                                                "<<endl;
  cout<<"                                                                                        "<<endl;
  cout<<"   GANADOR:                                                                             "<<endl;
  cout<<"                                                                                        "<<endl;
  cout<<endl<<endl<<endl;

  cout<<"      Copyright (C) TREYANOS Corporation. All rights reserved. "<<endl;

  cout<<endl;

  system("pause");

}
