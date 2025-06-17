
#include "player_magnament.h"
#include "structs.h"

#include "game_logic.h"

#include <iomanip> // para poder controlar los espacios en la tabla y que no se desforme

#include <iostream>
#include <windows.h>
#include <limits>
#include<cstdlib> // para numeros random
#include <ctime>
#include <cstring>


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

                num_bugs_en_tirada++; // Cara 5 es 1 BUG
                break;
            case 3:
                num_fixes_en_tirada++; // Cara 4 es 1 FIX
                break;
            default:
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


void calcular_resultado( Jugador p[2], ResultadoPartida re[2], string& ganador, int& puntoGanador){

   for(int i=0;i<2;i++){

      re[i].puntos= p[i].puntos_total_partida;
      re[i].cantidadBugs = p[i].bugs_acumulados;
      re[i].puntosPorBugs= p[i].bugs_acumulados * 5;
      re[i].cantidadTiempo= p[i].puntos_tiempo;
      re[i].puntosPorTiempo= p[i].puntos_tiempo * 7;

      if(p[i].acumulo_20_puntos_sin_bugs_alguna_vez){
         re[i].puntosAcumular20=10;
      }else{
        re[i].puntosAcumular20=0;
      }

      if(p[i].llego_a_cero_bugs_alguna_vez){
         re[i].puntosCeroBugsAlgunaVez =15;
      }else{
         re[i].puntosCeroBugsAlgunaVez =0;
      }


      if(p[0].bugs_acumulados< p[1].bugs_acumulados){
         re[0].puntosMenorBugs = 7;
         re[1].puntosMenorBugs = 0;
      }else if(p[0].bugs_acumulados> p[1].bugs_acumulados){
         re[1].puntosMenorBugs = 7;
         re[0].puntosMenorBugs = 0;
      }else {
         re[0].puntosMenorBugs = 7;
         re[1].puntosMenorBugs = 7;
      }

      re[i].totalFinal=(re[i].puntos + re[i].puntosAcumular20 + re[i].puntosMenorBugs + re[i].puntosPorTiempo + re[i].puntosCeroBugsAlgunaVez) - re[i].puntosPorBugs;

   }

 if(re[0].totalFinal>re[1].totalFinal){
   ganador = p[0].nombre;
   puntoGanador=re[0].totalFinal;
 }else if(re[0].totalFinal<re[1].totalFinal){
   ganador = p[1].nombre;
   puntoGanador=re[1].totalFinal;
 }else{
   ganador= "empate";
   puntoGanador=re[0].totalFinal;
 }


}


void menuResultado(Jugador player[2],string& ganador, int& puntoGanador){

   ResultadoPartida result[2];

   calcular_resultado(player,result, ganador, puntoGanador);

  system("cls");
  cout<<endl<<endl<<endl;


  cout<<"                              FIN DE LA PARTIDA!!!                                               "<<endl;
  cout<<"                                                                                                 "<<endl;
  cout<<"   TREY                                                                                          "<<endl;
  cout<<"   -------------------------------------------------------------------                           "<<endl;
  cout<<"                                                                                                 "<<endl;
  cout<<left<<setw(25)<<"   HITO "<<right<< setw(13)<<player[0].nombre << setw(6)<<" "<<right<<setw(13)<< player[1].nombre <<endl;
  cout<<"   -------------------------------------------------------------------                           "<<endl;
  cout<<left<<setw(28)<<"   Puntos"<<right<< setw(5)<<result[0].puntos<<" PTS "<<setw(14)<<result[1].puntos<<" PTS "            <<endl;

  cout<<left<<setw(26)<<"   BUGS"<<right<< setw(5)<<"-"<< result[0].puntosPorBugs<<" PTS "<<"("<<result[0].cantidadBugs<<")"<<setw(9)<<"-"<<result[1].puntosPorBugs <<" PTS ""("<<result[1].cantidadBugs <<")"<<endl;
  cout<<left<<setw(28)<<"   Tiempo"<<right<< setw(5)<<result[0].puntosPorTiempo<<" PTS "<<"("<<result[0].cantidadTiempo<<")"<<setw(11)<<result[1].puntosPorTiempo <<" PTS "<<"("<<result[1].cantidadTiempo<<")"<<endl;

  cout<<left<<setw(28)<<"   Menor BUGS"<<right<< setw(5)<<result[0].puntosMenorBugs<<" PTS "<<setw(14)<<result[1].puntosMenorBugs<<" PTS "        <<endl;
  cout<<left<<setw(28)<<"   Llegar a 0 BUGS"<<right<< setw(5)<< result[0].puntosCeroBugsAlgunaVez <<" PTS "<<setw(14)<<result[1].puntosCeroBugsAlgunaVez<<" PTS "       <<endl;
  cout<<left<<setw(28)<<"   Acumular 20 puntos"<<right<< setw(5)<< result[0].puntosAcumular20<<" PTS "<<setw(14)<<result[1].puntosAcumular20<<" PTS "   <<endl;

  cout<<"   -------------------------------------------------------------------                           "<<endl;
  cout<<left<<setw(28)<<"   TOTAL"<<right<< setw(5)<< result[0].totalFinal<<" PTS "<<setw(14)<<result[1].totalFinal<<" PTS "              <<endl;
  cout<<"                                                                                                 "<<endl;
  cout<<"     GANADOR: "<<ganador<<" con "<< puntoGanador<<" puntos."       <<endl;
  cout<<"                                                                                                 "<<endl;
  cout<<endl<<endl<<endl;

  cout<<"      Copyright (C) TREYANOS Corporation. All rights reserved. " <<endl;

  cout<<endl;

  system("pause");

}


void acomodarRanking(Ranking ganadores[5],const string& jp, const int& puntoJp){

  for(int i=0; i<5;i++){

     if(puntoJp > ganadores[i].puntos ){

         for(int x=4; x>i;x--){
               ganadores[x].ganador= ganadores[x-1].ganador;
               ganadores[x].puntos = ganadores[x-1].puntos;
         }
         ganadores[i].ganador= jp;
         ganadores[i].puntos= puntoJp;
         break;
     }
   }
}


void iniciarJuego(Jugador jugadores[2], string& ganador, int& puntoGanador, Ranking ganadores[5]) {
    const int MAX_RONDAS = 2;

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


    menuResultado(jugadores, ganador, puntoGanador);

    acomodarRanking(ganadores, ganador,puntoGanador);
    cout << "\n--- PARTIDA FINALIZADA ---\n";

}


void accionFixes(Jugador& jugador, int fixes_tirada){

         int aux = jugador.bugs_acumulados;

         if (aux - fixes_tirada <= 0){
            jugador.bugs_acumulados=0;

           // hito cero bug
         if (aux >0){
            jugador.llego_a_cero_bugs_alguna_vez=true;
            }
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

                        cout << "\n--- " << pj.nombre << "'s Turno ---\n";
                        cout << "PT: " << pj.puntos_tiempo << "\n";

                        // verificacion de penalizacion
                        if(pj.bugs_acumulados>2){
                        cout << "Tiene una penalizacion por acumulacion de bug"<<endl;
                        cout << "solo puede elejir lanzar (2) dados: "<<endl;
                        cin >> cuantos_dados;

                           if(cuantos_dados!=2){
                               cout<<"Te avise que solo puedes elejir 2 dados, lo hago por ti."<<endl;
                              cuantos_dados=2;
                           }
                        }else{


                        cout << "¿Cuántos dados quieres lanzar? (2 o 3): ";
                        cin >> cuantos_dados;
                        }

                        if (cin.fail() || (cuantos_dados != 2 && cuantos_dados != 3)) {
                            cin.clear(); // Limpiar flags de error
                            cout << "Entrada invalida. Por favor, ingresa 2 o 3.\n";

                            Sleep(1500);
                        } else {
                            valido = true;
                        }
                    } while (!valido);

}



void manejarTurnoJugador(Jugador& jugador_actual, Jugador& jugador_oponente) {
    int opcion_turno;
    bool turno_finalizado = false;

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
        cout << " 1. Lanzar dados\n"; // Esta opción gestionará si son 2 o 3 dados
        cout << " 2. Plantarse\n";
        cout << " Elija una opcion: ";
        cin >> opcion_turno;


        switch(opcion_turno) {
            case 1: {
                if (jugador_actual.puntos_tiempo <= 0) {

                    cout << "\n No tienes Puntos de Tiempo (PT) disponibles para lanzar.\n";
                    cout << " Debes plantarte.\n";

                    system("pause");
                    break; // Vuelve al menú del turno
                }

                    // Preguntar al jugador cuántos dados quiere lanzar (2 o 3)
                    int eleccion_dados;

                    bool eleccion_valida = false;


                if (jugador_actual.puntos_tiempo < 2) {
                  cout << "\nTienes 1 PT. Solo puedes lanzar 2 dados.\n";
                  eleccion_dados = 2;
                  eleccion_valida = true;
                } else {

                  cuantos_dados_tiras(jugador_actual, eleccion_dados, eleccion_valida, eleccion_dados);

                }

                // Gastar 1 o 2 PT por lanzamiento
                if(eleccion_dados==2){

                 jugador_actual.puntos_tiempo-=1;

                cout << "\n Has gastado 1 PT. PT restantes: " << jugador_actual.puntos_tiempo << "\n";
                }else{
                 jugador_actual.puntos_tiempo-=2;
                 cout << "\n Has gastado 2 PT. PT restantes: " << jugador_actual.puntos_tiempo << "\n";

                }

                system("pause");

                int puntos_tirada;
                int bugs_tirada=0;
                int fixes_tirada=0;
                //jugador_actual.bugs_acumulados=0;

                puntos_tirada = lanzarDados(eleccion_dados, bugs_tirada, fixes_tirada);

                // Aplicando reglas de las tiradas (bugs y fix)

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


                break;
            }
            case 2:
                // Plantarse: sumar puntos de la ronda al total
                jugador_actual.puntos_total_partida += jugador_actual.puntos_ronda_actual;

                cout << "\n" << jugador_actual.nombre << " se planta. Puntos de esta ronda: " << jugador_actual.puntos_ronda_actual << ".\n";

                  // hito acumulo 20 puntos
                  if ( jugador_actual.puntos_ronda_actual>=20){
                    jugador_actual.acumulo_20_puntos_sin_bugs_alguna_vez=true;
                  }


                turno_finalizado = true;
                system("pause");
                break;

            default:

                cout << "\nOpcion invalida. Intente de nuevo.\n";

                Sleep(1000);
                break;
        }

          // Si el jugador se queda sin PT y no se ha plantado/forzado el fin de turno
          if (jugador_actual.puntos_tiempo <= 0 && !turno_finalizado) {

               cout << "\n¡" << jugador_actual.nombre << " se ha quedado sin Puntos de Tiempo (PT)!\n";
               cout << "Debes plantarte (opcion 2) para terminar tu turno.\n";

               // Se forza al jugador a plantarse si no tiene PT
               // O podrías forzar el turno a terminar aquí si las reglas lo indican.
               // Para simplificar, lo dejo que el usuario elija plantarse manualmente.
               system("pause");
          }

    } while (!turno_finalizado); // El bucle continúa hasta que el turno finalice

    cout << "\nTurno de " << jugador_actual.nombre << " finalizado.\n";
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
  cout<<"   ║                  │  LEGAJO  │   NOMBRE Y APELLIDO              │                  ║"<<endl;
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

            return;
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

void cargaranking(Ranking jugadores[5]){
   jugadores[0].ganador="ROBERTITO";
   jugadores[0].puntos= 4;
   jugadores[1].ganador="PEPE";
   jugadores[1].puntos= 3;
   jugadores[2].ganador="RICKY";
   jugadores[2].puntos= 2;
   jugadores[3].ganador="MARIA";
   jugadores[3].puntos= 1;
   jugadores[4].ganador="JOSE";
   jugadores[4].puntos= 1;

}


void menuEstadistica(const string& ganador, const int& puntoGanador, Ranking ganadores[5]){



system("cls");
  cout<<endl<<endl;

  cout<<"   ╔═══════════════════════════════════════════════════════════════════════════╗"<<endl;
  cout<<"   ║                                                                           ║"<<endl;
  cout<<left<<setw(20)<< "   ║   Ultimo ganador: "<<setw(13)<<ganador <<"con "<<left<<setw(3)<< puntoGanador <<      "Puntos                              ║"<<endl;
  cout<<"   ║                                                                           ║"<<endl;
  cout<<"   ║                                                                           ║"<<endl;
  cout<<"   ║                                TOP FIVE                                   ║"<<endl;
  cout<<"   ║                              ------------                                 ║"<<endl;
  cout<<"   ║                ┌───┬─────────────────┬────────────┐                       ║"<<endl;
  cout<<"   ║                │pos│     Nombre      │   Puntos   │                       ║"<<endl;
  cout<<"   ║                ├───┼─────────────────┼────────────┤                       ║"<<endl;
  cout<<"   ║                │ 1 │    "<<left<<setw(12)<<ganadores[0].ganador <<" │      "<<left<<setw(3)<< ganadores[0].puntos<<"   │                       ║"<<endl;
  cout<<"   ║                │   │                 │            │                       ║"<<endl;
  cout<<"   ║                │ 2 │    "<<left<<setw(12)<<ganadores[1].ganador <<" │      "<<left<<setw(3)<< ganadores[1].puntos<<"   │                       ║"<<endl;
  cout<<"   ║                │   │                 │            │                       ║"<<endl;
  cout<<"   ║                │ 3 │    "<<left<<setw(12)<<ganadores[2].ganador <<" │      "<<left<<setw(3)<< ganadores[2].puntos<<"   │                       ║"<<endl;
  cout<<"   ║                │   │                 │            │                       ║"<<endl;
  cout<<"   ║                │ 4 │    "<<left<<setw(12)<<ganadores[3].ganador <<" │      "<<left<<setw(3)<< ganadores[3].puntos<<"   │                       ║"<<endl;
  cout<<"   ║                │   │                 │            │                       ║"<<endl;
  cout<<"   ║                │ 5 │    "<<left<<setw(12)<<ganadores[4].ganador <<" │      "<<left<<setw(3)<< ganadores[4].puntos<<"   │                       ║"<<endl;
  cout<<"   ║                └───┴─────────────────┴────────────┘                       ║"<<endl;
  cout<<"   ║                                                                           ║"<<endl;
  cout<<"   ║                                                                           ║"<<endl;
  cout<<"   ║        Copyright (C) TREYANOS Corporation. All rights reserved.           ║"<<endl;
  cout<<"   ╚═══════════════════════════════════════════════════════════════════════════╝"<<endl;

  cout<<endl;


system("pause");

}


