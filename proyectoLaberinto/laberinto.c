/**
	\file laberinto.c
	\brief Funcion para resolver laberinto
	\details funciones usadas en parte C
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.11.09
	\version 1.0.0
*/

//--------------
//-- Includes --
//--------------

#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

/**
	\fn struct mapa_S* laberintoResolver (struct mapa_S *p, int *cant)
	\brief Resuelve laberinto
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.11.09
	\param Puntero a la estructura con datos del mapa.
	\param Puntero a cantidad de movimientos para resolver el mapa.
	\return Puntero a estructura con datos actualizados del mapa.
*/
struct mapa_S* laberintoResolver (struct mapa_S *p, int *cant){


//-- Variables locales con los datos de struct mapa_S --
int  filas, columnas, personajeFila, personajeColumna;
char *ptrMatriz;
//-- Paso a variables locales datos de la estructura --
filas = p->filas;
columnas = p->columnas;
ptrMatriz = p->theMatrix;

//-- Indices y contadores --
int i = 0, libreNodo = 0, fin = 0, x = 0, inicio = 0;

//-- Vector para vuelta al nodo e contador para libres alrededor --
int V[4], libreVuelta = 0;

//-- Pido memoria para vectores de camino y nodos. Declaro e inicializo sus indices --

int *Nf, *Nc, n=0;

int *Cf, *Cc, c=0;

Nf = (int*) malloc ((sizeof(int)) * filas * columnas);
if(Nf == NULL){
  printf("Error malloc\r\n");
  return (p);
}

Nc = (int*) malloc ((sizeof(int)) * filas * columnas);
if(Nc == NULL){
  printf("Error malloc\r\n");
  return (p);

}

Cf = (int*) malloc ((sizeof(int)) * 2 * filas * columnas);
if(Cf == NULL){
  printf("Error malloc\r\n");
  return (p);
}



Cc = (int*) malloc ((sizeof(int)) * 2 * filas * columnas);
if(Cc == NULL){
  printf("Error malloc\r\n");
  return(p);
}



//-- Estructura con datos de alrededor y posicion actual --
struct camino posicion;



while( fin != 1){


//-- Paso a variables locales datos de la estructura --
personajeFila = p->personajeFila;
personajeColumna = p->personajeColumna;


        //-- Agrego a vector posicion actual --
        Cf [c] = personajeFila;
        Cc [c] = personajeColumna;

        //printf("Cf%d Cc%d\r\n", Cf[c],Cc[c] );

        // Relleno vector de la struct posicion con lo que hay alrededor --
        //-- Arriba --
        posicion.alrededor[0] = (*(ptrMatriz+((personajeFila-1)*columnas)+(personajeColumna)));

        //-- Abajo --
        posicion.alrededor[1] = (*(ptrMatriz+((personajeFila+1)*columnas)+(personajeColumna)));

        //-- Izquierda --
        posicion.alrededor[2] = (*(ptrMatriz+(personajeFila*columnas)+(personajeColumna-1)));

        //-- Derecha --
        posicion.alrededor[3] = (*(ptrMatriz+(personajeFila*columnas)+(personajeColumna+1)));



          //-- Me fijo cantidad de libres --
          for(i=0,libreNodo=0; i<4; i++){

            if(posicion.alrededor[i] == MAPA_LIBRE){
              libreNodo++;
            }

          }

          //--Si tengo libres voy a moverme, sumo indice vector camino, sino queda en el lugar --
          if(libreNodo != 0){
            c++;
          }

          //-- Si es nodo lo agrego al vector --
          if(libreNodo > 1){

              Nf [n] = personajeFila;
              Nc [n]= personajeColumna;
              n++;

          }

          //-- Me fijo si estoy proximo al final --
          for(i=0;i<4;i++){
            if(posicion.alrededor[i] == MAPA_FIN){
              fin = 1;

            }
          }

          //-- Para no moverme si tengo libres aparte del final --
          if(fin==1){
            for(i=0;i<4;i++){
              if(posicion.alrededor[i] != MAPA_FIN){
                posicion.alrededor[i] = MAPA_CAMINO;
              }
            }
          }


            //-- Me fijo si hay libres para avanzar --
            if(posicion.alrededor[0] == MAPA_LIBRE) {

              *cant = *cant + 1;
              mapaMarcar (p,ARRIBA);


            }else if (posicion.alrededor[1] == MAPA_LIBRE){

              *cant = *cant + 1;
              mapaMarcar (p,ABAJO);


            }else if (posicion.alrededor[2] == MAPA_LIBRE) {

              *cant = *cant + 1;
              mapaMarcar (p,IZQUIERDA);


            }else if (posicion.alrededor[3] == MAPA_LIBRE){

              *cant = *cant + 1;
              mapaMarcar (p,DERECHA);


            } else if (fin != 1 ){ //-- Si no hay libres alrededor retrocedo hasta el nodo --
                  printf("ELSEIF\r\n");

                  printf("Cf: %d Cc: %d\r\n",Cf[c],Cc[c]);
                  //-- Retrocedo hasta el nodo --
                  while( (Cf[c] != Nf[n-1]) || (Cc[c] != Nc[n-1]) ){

                    printf("WHILE\r\n");

                    //-- Paso a variable para usar dentro del while --
                    personajeFila = Cf[c];
                    personajeColumna = Cc[c];

                    if(*(ptrMatriz+(personajeFila*columnas)+(personajeColumna)) != MAPA_INICIO) {
                    *(ptrMatriz+(personajeFila*columnas)+(personajeColumna)) = MAPA_VUELTA;
                    }

                    c--;

                    *cant = *cant - 1;

                    //printf("ultimo nodo %d %d\r\n",Nf[n-1],Nc[n-1] );

                    p->personajeFila = personajeFila;
                    p->personajeColumna = personajeColumna;

                    mapaImprimir(p);
                    getchar();

                  } //-- Salgo del while, llegue al nodo.

                  printf("SALIDA WHILE\r\n");
                  printf("Cf: %d Cc: %d\r\n",Cf[c],Cc[c]);
                  personajeFila = Cf[c];
                  personajeColumna = Cc[c];


                  //-- Parado en el nodo guardo lo que hay alrededor --

                  //-- Arriba --
                  V[0] = (*(ptrMatriz+((personajeFila-1)*columnas)+(personajeColumna)));

                  //-- Abajo --
                  V[1] = (*(ptrMatriz+((personajeFila+1)*columnas)+(personajeColumna)));

                  //-- Izquierda --
                  V[2] = (*(ptrMatriz+(personajeFila*columnas)+(personajeColumna-1)));

                  //-- Derecha --
                  V[3] = (*(ptrMatriz+(personajeFila*columnas)+(personajeColumna+1)));


                  /*for(i=0;i<4;i++){
                    printf("%c",V[i] );
                  }*/

                    //printf("Nf%d Nc%d\r\n", Nf[n-1],Nc[n-1] );

                  //-- Recorro V[] e incremento contadores --
                  for(i=0,libreVuelta=0,x=0,inicio=0;i<4;i++){

                    if(V[i] == MAPA_LIBRE){
                      libreVuelta++;
                    }


                    if(V[i] == MAPA_CAMINO){
                      x++;
                    }

                    if(V[i] == MAPA_INICIO){
                      inicio++;
                    }
                  }

                  //-- Mapa sin salida --
                  if(x == 0 && libreVuelta == 0 && inicio == 0){
                    *cant = -1;
                    free(Nf);
                    free(Nc);
                    free(Cf);
                    free(Cc);
                    return (p);
                  }


                  //-- Me fijo si sigue siendo nodo al volver --

                  if(libreVuelta == 0){
                  //-- Si al volver al nodo no hay libres pongo indice para que lo pise --
                  n = n-1;
                  }

                  //--Actualizo posicion del personaje en estructura --
                  p->personajeFila = personajeFila;
                  p->personajeColumna = personajeColumna;


             }//--Fin else if (fin != 1 )


}//-- Fin While --

          free(Cf);
          free(Cc);
          free(Nc);
          free(Nf);

          return(p);

}
