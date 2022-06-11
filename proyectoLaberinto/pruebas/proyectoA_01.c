/**
	\file proyectoA_01.c
	\brief Prueba la funcion matrizImprimir
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.09.28
	\version 1.0.0
*/

//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include "matriz.h"

/**
	\fn int main (void)
	\brief Prueba de matrizImprimir.
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.09.28
	\return Retorna siempre 0
*/
int main (void){

char matriz [FILAS] [COLUMNAS];
char *ptrMatriz;   //-- Puntero a la matriz --
int i,j;

//-- Apunto a matriz --
ptrMatriz = &matriz[0][0];
  //-- Recorro matriz --
  for(i=0; i<FILAS; i++){
    for(j=0; j<COLUMNAS; j++){
      //-- Inicializo matriz con un valor --
      *(ptrMatriz+(i*COLUMNAS)+j) = 'M';

    }
  }
  //-- Imprimo matriz --
  matrizImprimir (ptrMatriz, FILAS, COLUMNAS);

return (0);

}
