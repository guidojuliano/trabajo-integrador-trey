
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
    num_bugs_en_tirada = 0;
    num_fixes_en_tirada = 0;

    char fila1[500] = "";
    char fila2[500] = "";
    char fila3[500] = "";
    char fila4[500] = "";
    char fila5[500] = "";

    cout << "\nLanzando " << cantDados << " dados...\n";
    Sleep(1000);

    for(int i = 0; i < cantDados; i++) {
        char lin1[30], lin2[30], lin3[30], lin4[30], lin5[30];
        int numero_dado = rand() % 6 + 1; // Genera un número entre 1 y 6

        puntos_obtenidos_tirada += numero_dado; // suman puntos total de la tirada

        // Procesar el resultado del dado
        switch (numero_dado) {
            case 1:
                num_bugs_en_tirada++;
                break;
            case 3:
                num_fixes_en_tirada++;
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
    cout << "\n\n\n";
    cout << "  " << fila1 << std::endl;
    cout << "  " << fila2 << std::endl;
    cout << "  " << fila3 << std::endl;
    cout << "  " << fila4 << std::endl;
    cout << "  " << fila5 << std::endl;
    cout << std::endl;

    cout << "  Puntos obtenidos: " << puntos_obtenidos_tirada << std::endl;
    cout << "  Bugs obtenidos:   " << num_bugs_en_tirada << std::endl;
    cout << "  Fixes obtenidos:  " << num_fixes_en_tirada << std::endl;
    cout << std::endl << std::endl;

    system("pause");
    //system("cls");

    return puntos_obtenidos_tirada;
}

void iniciarJuego(vector<Jugador>& jugadores) {
    const int MAX_RONDAS = 10;

    cout << "\n--- INICIO DE LA PARTIDA ---\n";


    for (int ronda_actual = 1; ronda_actual <= MAX_RONDAS; ronda_actual++) {
        system("cls");
        cout << "\n=============== RONDA " << ronda_actual << " ===============\n";

        // Turno del Jugador 1
        cout << "\n--- Turno de " << jugadores[0].nombre << " ---\n";
        manejarTurnoJugador(jugadores[0], jugadores[1]);


        if (jugadores[0].puntos_total_partida >= jugadores[0].carta_objetivo ||
            jugadores[1].puntos_total_partida >= jugadores[1].carta_objetivo) {
            cout << "\n¡Juego terminado por objetivo alcanzado!\n";
            break;
        }

        // Turno del Jugador 2
        cout << "\n--- Turno de " << jugadores[1].nombre << " ---\n";
        manejarTurnoJugador(jugadores[1], jugadores[0]);


        if (jugadores[0].puntos_total_partida >= jugadores[0].carta_objetivo ||
            jugadores[1].puntos_total_partida >= jugadores[1].carta_objetivo) {
            cout << "\n¡Juego terminado por objetivo alcanzado!\n";
            break;
        }


        cout << "\nFin de la Ronda " << ronda_actual << ". Presione Enter para la siguiente ronda...";

    }

    cout << "\n--- PARTIDA FINALIZADA ---\n";

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
        cout << "\n--- " << jugador_actual.nombre << "'s Turno ---\n";
        cout << "  PT: " << jugador_actual.puntos_tiempo << " | Bugs: " << jugador_actual.bugs_acumulados;
        cout << " | Puntos Ronda: " << jugador_actual.puntos_ronda_actual << "\n";
        cout << "  Puntos Totales: " << jugador_actual.puntos_total_partida << " | Carta Objetivo: " << jugador_actual.carta_objetivo << "\n\n";

        // Menú de opciones para el turno
        cout << "1. Lanzar dados\n"; // Esta opción gestionará si son 2 o 3 dados
        cout << "2. Plantarse\n";
        cout << "3. Usar FIX (TODO)\n";
        cout << "Elija una opcion: ";
        cin >> opcion_turno;

        switch(opcion_turno) {
            case 1: {
                if (jugador_actual.puntos_tiempo <= 0) {
                    cout << "\nNo tienes Puntos de Tiempo (PT) disponibles para lanzar.\n";
                    cout << "Debes plantarte o usar FIX (si aplica).\n";
                    system("pause");
                    break; // Vuelve al menú del turno
                }

                // Determinar cuántos dados lanzar
                int num_dados;

                if (primer_lanzamiento_del_turno) {
                    dados_a_lanzar = 3;
                    primer_lanzamiento_del_turno = false; // Ya no es el primer lanzamiento
                    cout << "\nLanzarás 3 dados por ser el primer lanzamiento del turno.\n";
                    system("pause");
                } else {
                    // Pregunta cuantos dados
                    int eleccion_dados;
                    bool eleccion_valida = false;
                    do {
                        system("cls");
                        cout << "\n--- " << jugador_actual.nombre << "'s Turno ---\n";
                        cout << "PT: " << jugador_actual.puntos_tiempo << "\n";
                        cout << "¿Cuántos dados quieres lanzar? (2 o 3): ";
                        cin >> eleccion_dados;
                        if (cin.fail() || (eleccion_dados != 2 && eleccion_dados != 3)) {
                            cin.clear();
                            cout << "Entrada invalida. Por favor, ingresa 2 o 3.\n";
                            Sleep(1500);
                        } else {
                            eleccion_valida = true;
                            num_dados=eleccion_dados;
                        }
                    } while (!eleccion_valida);
                    dados_a_lanzar = eleccion_dados;
                }

                if(num_dados==2){

                 jugador_actual.puntos_tiempo-=1;
                cout << "\nHas gastado 1 PT. PT restantes: " << jugador_actual.puntos_tiempo << "\n";
                }else{
                 jugador_actual.puntos_tiempo-=2;
                 cout << "\nHas gastado 2 PT. PT restantes: " << jugador_actual.puntos_tiempo << "\n";
                }

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


                if (jugador_actual.bugs_acumulados >= 3) {
                    cout << "\n¡" << jugador_actual.nombre << " ha acumulado 3 o mas BUGS! Pierde los puntos de esta ronda (" << jugador_actual.puntos_ronda_actual << ").\n";
                    jugador_actual.puntos_ronda_actual = 0; // Pierde los puntos de la ronda
                    jugador_actual.bugs_acumulados = 0; // Se resetean los bugs (o según regla si se mantienen)
                    turno_finalizado = true; // El turno termina forzosamente
                    system("pause");
                }
                break;
            }
            case 2:

                jugador_actual.puntos_total_partida += jugador_actual.puntos_ronda_actual;
                cout << "\n" << jugador_actual.nombre << " se planta. Puntos de esta ronda: " << jugador_actual.puntos_ronda_actual << ".\n";
                turno_finalizado = true;
                system("pause");
                break;
            case 3:

                cout << "\nFuncionalidad 'Usar FIX' no implementada aun. (Requiere FIXES acumulados).\n";
                system("pause");
                break;
            default:
                cout << "\nOpcion invalida. Intente de nuevo.\n";
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

    cout << "\nTurno de " << jugador_actual.nombre << " finalizado.\n";
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

void menuPrincipal (){
system("cls");
      cout<< endl;
      cout<<"--------------- Bienvenidos a TREY ---------------"<<endl;
      cout<< endl<< endl;
      cout<<"   ┌---------------------------------------┐"<<endl;
      cout<<"   | MENU PRINCIPAL                        |"<<endl;
      cout<<"   ├---------------------------------------┤"<<endl;
      cout<<"   |                                       |"<<endl;
      cout<<"   |            1 - JUGAR                  |"<<endl;
      cout<<"   |            2 - ESTADISTICA            |"<<endl;
      cout<<"   |            3 - CREDITOS               |"<<endl;
      cout<<"   |                                       |"<<endl;
      cout<<"   ├---------------------------------------┤"<<endl;
      cout<<"   |            0 - SALIR                  |"<<endl;
      cout<<"   └---------------------------------------┘"<<endl;
      cout<<endl;
}
