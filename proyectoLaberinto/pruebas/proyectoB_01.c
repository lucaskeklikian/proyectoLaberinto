/**
	\file proyectoB_01.c
	\brief Prueba la funcion mapaVacioCrear.
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.09.29
	\version 1.0.0
*/

//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

#include "matriz.h" //-- Uso matriz.h para FILA,COLUMNA y matrizImprimir --

/**
	\fn int main (void)
	\brief Prueba de mapaVacioCrear.
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.09.29
	\return Retorna siempre 0
*/
int main (void){
char *ptrMatriz;

  //-- Creo mapa --
  ptrMatriz = mapaVacioCrear(FILAS,COLUMNAS);
  //-- La matriz es chica --
  if(ptrMatriz==NULL){
    printf("ERROR FILAS Y COLUMNAS\r\n");
    return(0);
  }
  matrizImprimir (ptrMatriz, FILAS, COLUMNAS);


return(0);
}
