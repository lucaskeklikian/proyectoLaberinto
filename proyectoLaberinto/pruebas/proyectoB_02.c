/**
	\file proyectoB_02.c
	\brief Prueba la funcion mapaInicializar
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
	\brief Prueba de mapaInicializar.
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.09.29
	\return Retorna siempre 0
*/
int main (void){
struct mapa_S *p; //-- Puntero a la struct mapa_S inicializada --

  //-- p apunta a estructura inicializada --
  p = mapaInicializar (FILAS, COLUMNAS);
  //-- Imprimo campos de struct mapa_S --
  printf("%d,%d\r\n%d,%d\r\n", p->filas, p->columnas, p->personajeFila, p->personajeColumna );
  //-- Verifico la inicializacion --
  matrizImprimir (p->theMatrix, FILAS, COLUMNAS);


return(0);
}
