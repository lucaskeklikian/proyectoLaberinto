/**
	\file proyectoB_07.c
	\brief Prueba la funcion mapaMarcar.
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
	\brief Prueba de mapaMarcar.
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.10.03
	\return Retorna siempre 0
*/
int main (void){

struct mapa_S *ptrS;
int r;
      //-- Inicializo mapa --
      printf("ARRIBA\r\n");
      ptrS = mapaInicializar (FILAS, COLUMNAS);
      //-- Marco posicion inicial y actual del personaje --
      r = mapaMarcar (ptrS,ARRIBA);
      //-- Imprimo mapa actualizado para verificar --
      mapaImprimir (ptrS);
      //-- Imprimo retorno de mapaMarcar --
      printf("%d\r\n",r);


      printf("ABAJO\r\n");
      ptrS = mapaInicializar (FILAS, COLUMNAS);
      r = mapaMarcar (ptrS,ABAJO);
      mapaImprimir (ptrS);
      printf("%d\r\n",r);

      printf("DERECHA\r\n");
      ptrS = mapaInicializar (FILAS, COLUMNAS);
      r = mapaMarcar (ptrS,DERECHA);
      mapaImprimir (ptrS);
      printf("%d\r\n",r);

      printf("IZQUIERDA\r\n");
      ptrS = mapaInicializar (FILAS, COLUMNAS);
      r = mapaMarcar (ptrS,IZQUIERDA);
      mapaImprimir (ptrS);
      printf("%d\r\n",r);



return(0);

}
