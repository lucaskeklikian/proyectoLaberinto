/**
	\file matriz.c
	\brief API de creacion e impresion de matrices.
	\details funciones usadas en parte A
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.09.28
	\version 1.0.0
*/
//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

/**
	\fn void matrizImprimir (char *p, int filas, int columnas)
	\brief Imprime matriz
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.09.28
	\param *p Puntero a la martiz.
	\param filas Cantidad de filas de la matriz
	\param columnas Cantidad de columnas de la matriz.
	\return void
*/

void matrizImprimir (char *p, int filas, int columnas){

int i,j;
  
  //-- Recorro matriz --
  for(i=0; i<filas; i++){
    for(j=0; j<columnas; j++){
      //-- Imprimo contenido de la matriz --
      printf("%c", *(p+(i*columnas)+j));

        }
        //-- Cuando salgo del for de filas imprimo salto de linea --
        printf("\r\n");
    }
  }

  /**
  	\fn char* matrizCrear (int filas, int columnas, char valor)
  	\brief Crea matriz
  	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
  	\date 2018.09.28
  	\param filas Cantidad de filas de la matriz
  	\param columnas Cantidad de columnas de la matriz.
    \param valor Valor con el que se debe inicializar la matriz.
    \return Un puntero a la matriz creada o NULL en caso de error.
  */

char* matrizCrear (int filas, int columnas, char valor){

char *p;
int i,j;
  //-- Pido memoria --
  p = (char*) malloc (filas*columnas);
  //-- No hay memoria --
  if(p==NULL){
    return(NULL);
  }else{
    //-- Hay memoria, recorro matriz --
    for(i=0; i<filas; i++){
      for(j=0; j<columnas; j++){
        //-- Inicializo matriz con valor pasado como parametro --
        *(p+(i*columnas)+j) = valor;

      }
    }
  }
  //-- Devuelvo puntero a la matriz --
  return(p);
}
