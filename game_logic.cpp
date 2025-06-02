
#include "game_logic.h"

#include <iostream>
#include <windows.h>
using namespace std;

#include<cstdlib> // para numeros random
#include <ctime>
#include <cstring>




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
