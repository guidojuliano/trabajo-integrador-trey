
#include <iostream>
#include <windows.h>

#include "game_logic.h"

#include<cstdlib> // para numeros random
#include <ctime>


using namespace std;

int main(){
    srand(time(0));
    SetConsoleOutputCP(65001);

    int eleccion;
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

      switch(eleccion){
        case 1:
          //cout<<"estas en jugar";
          lanzarDados(3);
          break;

        case 2:
          cout<<"estas en estadistica";
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
