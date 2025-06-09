
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

        puntos_obtenidos_tirada += numero_dado; // suman puntos total de la tirada

        // Procesar el resultado del dado
        switch (numero_dado) {
            case 1:
                num_bugs_en_tirada++; // Cara 5 es 1 BUG
                break;
            case 3:
                num_fixes_en_tirada++; // Cara 4 es 1 FIX
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


void accionFixes(Jugador& jugador, int fixes_tirada){
            if(jugador.bugs_acumulados - fixes_tirada <0){
            jugador.bugs_acumulados=0;
         }else{
           jugador.bugs_acumulados-=fixes_tirada;
         }

         if (fixes_tirada==1){
               cout<<"salio 1 fix se resta 1 bug del total acumulado"<<endl;

         }else if( fixes_tirada==2){
             cout<<"salio 2 fix se resta 2 bug del total acumulado"<<endl;
         }else if( fixes_tirada==3){
            cout<<"salio 3 fix se resta 3 bug del total acumulado"<<endl;
         }
}

void penalizacion(Jugador& pj, int bugs_tirada){

      if(pj.bugs_acumulados>5){
         cout<<"tienen una penalizacion por acumulacion de bug (6 o mas)"<<endl;
         cout<<" se le va a descontar 5 puntos de total acumulado por cada bug en la tirada"<<endl;

         pj.puntos_total_partida-=(5 * bugs_tirada);
         system("pause");
      }
}

void cuantos_dados_tiras(Jugador& pj, int& eleccion, bool& valido, int& cuantos_dados ){

   do {
                        system("cls"); // Limpiar para la elección de dados
                        std::cout << "\n--- " << pj.nombre << "'s Turno ---\n";
                        std::cout << "PT: " << pj.puntos_tiempo << "\n";

                        // verificacion de penalizacion
                        if(pj.bugs_acumulados>2){
                        std::cout << "Tiene una penalizacion por acumulacion de bug"<<endl;
                        std::cout << "solo puede elejir lanzar (2) dados: "<<endl;
                        std::cin >> cuantos_dados;
                           if(cuantos_dados!=2){
                               cout<<"Te avise que solo puedes elejir 2 dados, lo hago por ti."<<endl;
                              cuantos_dados=2;
                           }
                        }else{

                        std::cout << "¿Cuántos dados quieres lanzar? (2 o 3): ";
                        std::cin >> cuantos_dados;
                        }

                        if (std::cin.fail() || (cuantos_dados != 2 && cuantos_dados != 3)) {
                            std::cin.clear(); // Limpiar flags de error
                            std::cout << "Entrada invalida. Por favor, ingresa 2 o 3.\n";
                            Sleep(1500);
                        } else {
                            valido = true;
                        }
                    } while (!valido);

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
        std::cout << "Elija una opcion: ";
        std::cin >> opcion_turno;

        switch(opcion_turno) {
            case 1: {
                if (jugador_actual.puntos_tiempo <= 0) {
                    std::cout << "\nNo tienes Puntos de Tiempo (PT) disponibles para lanzar.\n";
                    std::cout << "Debes plantarte.\n";
                    system("pause");
                    break; // Vuelve al menú del turno
                }

                    // Preguntar al jugador cuántos dados quiere lanzar (2 o 3)
                    int eleccion_dados;
                    bool eleccion_valida = false;

                    //prueba de penalizacion eliminar linea luego
                    jugador_actual.bugs_acumulados=6;

                    cuantos_dados_tiras(jugador_actual, eleccion_dados, eleccion_valida, eleccion_dados);


                // Gastar 1 o 2 PT por lanzamiento
                if(eleccion_dados==2){

                 jugador_actual.puntos_tiempo-=1;
                std::cout << "\nHas gastado 1 PT. PT restantes: " << jugador_actual.puntos_tiempo << "\n";
                }else{
                 jugador_actual.puntos_tiempo-=2;
                 std::cout << "\nHas gastado 2 PT. PT restantes: " << jugador_actual.puntos_tiempo << "\n";
                }

                system("pause");

                int puntos_tirada;
                int bugs_tirada=0;
                int fixes_tirada=0;
                //jugador_actual.bugs_acumulados=0;

                puntos_tirada = lanzarDados(eleccion_dados, bugs_tirada, fixes_tirada);

                // Aplicar reglas de la tirada (bugs y fix)

                switch (bugs_tirada){
               case 1:

                  cout<<"salio 1 bug perdiste los puntos ganados actuales y tu turno, ademas sumas 1 bug "<<endl;
                  jugador_actual.bugs_acumulados+=1;
                  penalizacion( jugador_actual, bugs_tirada);

                  turno_finalizado = true; // El termina turno

                  break;
               case 2:

                  cout<<"salio 2 bug perdiste los puntos ganados actuales y tu turno, ademas sumas 2 bug "<<endl<<endl;

                  jugador_actual.bugs_acumulados+=2;
                  jugador_actual.puntos_tiempo -=1;

                  penalizacion(jugador_actual, bugs_tirada);

                  turno_finalizado = true; // El termina turno


                  break;
               case 3:
                  jugador_actual.bugs_acumulados+=3;
                  jugador_actual.puntos_tiempo -=2;
                  penalizacion(jugador_actual, bugs_tirada);

                  turno_finalizado = true; // El termina turno

                  break;
               default:
                  // si sale 0 o cualquier otro numero no quiero que haga nada
                  break;

                }

                  switch(fixes_tirada){

               case 1:

                  accionFixes(jugador_actual, fixes_tirada);

                  jugador_actual.puntos_ronda_actual+=puntos_tirada;
                  system("pause");
                  break;
               case 2:

                  accionFixes(jugador_actual, fixes_tirada);
                  cout<<endl<<endl<<"ademas ganas 1 punto de tiempo"<<endl;
                  jugador_actual.puntos_tiempo+=1;
                  jugador_actual.puntos_ronda_actual+=puntos_tirada;
                  system("pause");
                  break;
               case 3:

                  accionFixes(jugador_actual, fixes_tirada);
                  cout<<endl<<"ademas ganas 2 punto de tiempo"<<endl;
                  jugador_actual.puntos_tiempo+=2;
                  jugador_actual.puntos_ronda_actual+=puntos_tirada;
                  system("pause");
                  break;
               default:
                  break;

                  }

                if(fixes_tirada ==0 && bugs_tirada==0){
                  jugador_actual.puntos_ronda_actual+=puntos_tirada;
                }

                jugador_actual.lanzamientos_en_ronda++;

                // **Verificación de penalización por BUGS** (revisar reglas exactas del PDF)
                // Si acumula 3 o más BUGS, se planta automáticamente y pierde puntos de la ronda
//                if (jugador_actual.bugs_acumulados >= 3) {
//                    std::cout << "\n¡" << jugador_actual.nombre << " ha acumulado 3 o mas BUGS! Pierde los puntos de esta ronda (" << jugador_actual.puntos_ronda_actual << ").\n";
//                    jugador_actual.puntos_ronda_actual = 0; // Pierde los puntos de la ronda
//                    jugador_actual.bugs_acumulados = 0; // Se resetean los bugs (o según regla si se mantienen)
//                    turno_finalizado = true; // El turno termina forzosamente
//                    system("pause");
//                }
                break;
            }
            case 2:
                // Plantarse: sumar puntos de la ronda al total
                jugador_actual.puntos_total_partida += jugador_actual.puntos_ronda_actual;
                std::cout << "\n" << jugador_actual.nombre << " se planta. Puntos de esta ronda: " << jugador_actual.puntos_ronda_actual << ".\n";
                turno_finalizado = true;
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


void menuCreditos(){
  system("cls");

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
  system("pause");
  system("cls");
}


void confirmarSalir(char confirm , int& eleccion){
      if(confirm== 'S' || confirm=='N'){
          if(confirm=='S'){
            return ;
          }else{
            eleccion=894;
            return;
            }
      }else{
         // cout<<endl<<" eleccion incorrecta vuelva a intentar"<<endl;
         cartelDeError();
         eleccion=894;
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



