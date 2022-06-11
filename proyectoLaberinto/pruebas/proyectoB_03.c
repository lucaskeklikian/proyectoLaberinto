/**
	\file proyectoB_03.c
	\brief Prueba la funcion mapaImprimir
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

#include "matriz.h" //-- Uso matriz.h para FILA y COLUMNA --

/**
	\fn int main (void)
	\brief Prueba de mapaImprimir.
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.09.29
	\return Retorna siempre 0
*/
int main (void){
struct mapa_S *p; //-- Puntero a estructura con informacion del mapa
int r;

  //-- Inicializo mapa--
  p = mapaInicializar (FILAS, COLUMNAS);
  //--Imprimo mapa --
  r = mapaImprimir (p);
  //-- No puedo imprimir mapa --
  if(r == -1){
    printf("ERROR IMPRIMIR MAPA\r\n");
  }

return(0);
}
