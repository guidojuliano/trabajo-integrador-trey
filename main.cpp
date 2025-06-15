
#include <iostream>
#include <windows.h>

#include <cstdlib>

#include <ctime>
#include <limits>
#include "game_logic.h"
#include "player_magnament.h"

using namespace std;

int main(){
    srand(time(0));

    SetConsoleOutputCP(65001);//para que se vea acentos y caracteres especiales

    Ranking ganadores[5];

    cargaranking(ganadores);

    string ganador =ganadores[0].ganador;
    int puntoGanador = ganadores[0].puntos;


    int eleccion = -1;

    Jugador jugadores[2];

    char confirm;


    while(eleccion!=0){

      menuPrincipal();
      cout<<"    Por favor elija una opcion: ";
      cin>>eleccion;

      switch(eleccion){
        case 1:
          registrarNombresJugadores(jugadores);
          iniciarJuego(jugadores, ganador, puntoGanador, ganadores);
          break;
        case 2:
         menuEstadistica(ganador, puntoGanador, ganadores);
          break;
        case 3:
          cout<<endl<<endl<<endl;
          menuCreditos();
          cout<<endl<<endl<<endl;
          break;
        case 0:
          cout<<endl<<"¿Esta seguro que quiere salir? S/N: ";
          cin>> confirm;
          confirm= toupper(confirm);
          confirmarSalir(confirm , eleccion);
          Sleep(2000);
          break;

        default:
        cartelDeError();
        Sleep(2000);
        system("cls");
        break;
      }
    }


    return 0;

}
