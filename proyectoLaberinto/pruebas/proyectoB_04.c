/**
	\file proyectoB_04.c
	\brief Prueba la funcion mapaLiberar
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.10.03
	\version 1.0.0
*/

//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include <string.h>
#include "matriz.h" // para FILAS y COLUMNAS

/**
	\fn int main (void)
	\brief Prueba de mapaLiberar.
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.10.03
	\return Retorna siempre 0
*/
int main (void){

struct mapa_S *ptrS;
int r;
  //-- Inicializo mapa--
  ptrS = mapaInicializar (FILAS, COLUMNAS);
  //-- Libero mapa --
  r = mapaLiberar(ptrS);
  //-- Imprimo lo que devuelve mapaLiberar
  printf("%d\r\n", r);

return(0);

}
