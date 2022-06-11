/**
	\file proyectoB_06.c
	\brief Prueba la funcion mapaLeer
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
	\brief Prueba de mapaLeer.
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.10.03
	\return Retorna siempre 0
*/
int main (void){

struct mapa_S *ptrS;
char nombreArchivo[32];
int r;

    //-- Copio nombre de archivo a vector --
    strcpy(nombreArchivo,"mapaPrueba.txt");

    //-- Leo archivo y almaceno mapa en la estructura
    ptrS = mapaLeer (nombreArchivo);

    //-- Verifico imprimiendo la estructura
    r = mapaImprimir (ptrS);
    if(r < 0){
      printf("ERROR IMPRIMIR");
    }


return(0);

}
