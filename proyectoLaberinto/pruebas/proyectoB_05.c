/**
	\file proyectoB_05.c
	\brief Prueba la funcion mapaEscribir
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
	\brief Prueba de mapaEscribir.
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.10.03
	\return Retorna siempre 0
*/
int main (void){

struct mapa_S *ptrS;
char nombreArchivo[32];
int r;


      //-- Inicializo mapa--
      ptrS = mapaInicializar(FILAS,COLUMNAS);
      //-- Copio nombre de archivo a vector para pasar a funcion --
      strcpy(nombreArchivo,"mapaPrueba.txt");
      //-- Imprimo escenario en archivo de texto --
      r = mapaEscribir(nombreArchivo,ptrS);
      //-- Verifico retorno de mapaEscribir --
      if(r < 0){
        printf("%d\r\n",r);
      }


return(0);

}
