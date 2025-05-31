
#include "misfunciones.h"

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



int lanzarDados(int cantDados){
    int puntosObtenidos=0;
    char fila1[500] = "";
    char fila2[500] = "";
    char fila3[500] = "";
    char fila4[500] = "";
    char fila5[500] = "";

    for(int i= 0; i<cantDados;i++) {
        char lin1[30], lin2[30], lin3[30], lin4[30], lin5[30];
        int numero = rand() % 6 + 1;
        puntosObtenidos+=numero;
        armarDadoRandom(lin1, lin2, lin3, lin4, lin5, numero);

        strcat(fila1, lin1); strcat(fila1, "  ");
        strcat(fila2, lin2); strcat(fila2, "  ");
        strcat(fila3, lin3); strcat(fila3, "  ");
        strcat(fila4, lin4); strcat(fila4, "  ");
        strcat(fila5, lin5); strcat(fila5, "  ");

      }
    system("cls");

    cout<<endl<<endl<<endl;
    cout <<"  "<<fila1 << endl;
    cout <<"  "<< fila2 << endl;
    cout <<"  "<< fila3 << endl;
    cout <<"  "<< fila4 << endl;
    cout <<"  "<< fila5 << endl;
    cout <<endl;

    cout<<" puntos obtenidos: "<<puntosObtenidos<< endl;
    cout<<endl<<endl<<endl;
    system("pause");
    system("cls");

}



