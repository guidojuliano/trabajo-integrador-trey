
#include <iostream>
#include <windows.h>
#include<cstdlib>
#include <ctime>
#include <limits>
#include "game_logic.h"
#include "player_magnament.h"

using namespace std;

int main(){
    srand(time(0));
    SetConsoleOutputCP(65001);


    int eleccion = -1;
    vector<Jugador> jugadores(2);
    char confirm;


    while(eleccion!=0){

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
      cout<<"    Por favor elija una opcion: ";
      cin>>eleccion;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      switch(eleccion){
        case 1:
          //cout<<"estas en jugar";
          //lanzarDados(3);
          registrarNombresJugadores(jugadores);
          iniciarJuego(jugadores);
          break;

        case 2:
          menuEstadistica();
          break;

        case 3:
          system("cls");
          cout<<endl<<endl<<endl;
          menuCreditos();
          cout<<endl<<endl<<endl;
          system("pause");
          system("cls");
          break;

        case 0:
                cout<<endl<<"¿Esta seguro que quiere salir? S/N: ";
                cin>> confirm;
                confirm= toupper(confirm);
                confirmarSalir(confirm , eleccion);
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
