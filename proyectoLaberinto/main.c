/**
	\file main.c
	\brief Prueba la funcion laberintoResolver
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.11.12
	\version 1.0.0
*/

//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include <string.h>
/**
	\fn int main (int argc,char *argV[])
	\brief Prueba de laberintoResolver
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.11.12
  \param Cantidad de argumentos
  \param Puntero a argumento, archivo con el mapa a resolver
	\return Retorna siempre 0
*/

//int main (void){
int main (int argc,char *argV[]){
int r,cant=0,resta,j=0;
long int i;
struct mapa_S *ptrS;

//-- Para generar archivo con mapa resuelto --
char nombre[32] ;
char archivo[32];
char * ptrNombre;
char *aux1,*aux2;

strcpy(nombre,argV[1]);


aux1 = strrchr(nombre,'/');

resta = aux1 - nombre;

aux2 = strrchr(nombre,'.');


for(i = (long int)(aux1); i < (long int)(aux2);i++ ){
  archivo[j] = nombre[resta+1];
  resta++;
  j++;
}


archivo [j+0] = 'r';
archivo [j+1] = 'e';
archivo [j+2] = 's';
archivo [j+3] = '\0';



ptrNombre = archivo;

      ptrS = mapaLeer (argV[1]);

      r = mapaImprimir (ptrS);

      if(r < 0){
        printf("ERROR IMPRIMIR (mapaImprimir)\r\n");
        return(0);
      }


      ptrS = laberintoResolver (ptrS, &cant);

      //printf("MAIN\r\n");
      r = mapaImprimir (ptrS);

      mapaEscribir (ptrNombre,ptrS);

      if(r < 0){
        printf("ERROR IMPRIMIR (mapaImprimir)");
        return(0);
      }

      if(cant<0){
        printf("Mapa sin salida : %d\r\n",cant );
      }else{
      printf("Cantidad de movimientos: %d\r\n",cant);
      }


      return (0);

}
