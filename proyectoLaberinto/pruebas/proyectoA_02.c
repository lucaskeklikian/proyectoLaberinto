/**
	\file proyectoA_02.c
	\brief Prueba la funcion matrizCrear
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
	\brief Prueba de matrizCrear.
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.09.28
	\return Retorna siempre 0
*/
int main (void){

char *ptrMatriz;   //-- Puntero a la matriz --
  //-- Creo matriz --
  ptrMatriz = matrizCrear (FILAS, COLUMNAS, 'L');
  //-- Imprimo matriz --
  matrizImprimir (ptrMatriz, FILAS, COLUMNAS);
  
return (0);

}
