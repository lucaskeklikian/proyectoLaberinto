/**
	\file mapa.c
	\brief API de informacion de mapas.
	\details funciones usadas en parte B
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.09.28
	\version 1.0.0
*/
//--------------
//-- Includes --
//--------------

#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"


/**
	\fn char* mapaVacioCrear (int filas, int columnas)
	\brief Crea mapa con paredes, inicio, fin y lugares libres.
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.09.29
	\param filas cantidad de filas de la matriz del mapa.
	\param columnas cantidad de columnas de la matriz del mapa.
	\return Puntero a la matriz inicializada.
*/
char* mapaVacioCrear (int filas, int columnas){

char *p;
int i,j;
    //-- Verifico tamaño de matriz --
    if( (filas < 5) && (columnas < 5) ){
      return(NULL);
    }
     //-- Pido memoria --
    p = (char*) malloc (filas*columnas);
    //-- No hay memoria --
    if(p==NULL){
      return(NULL);
    }else{
      //-- Hay memoria --
      for(i=0; i<filas; i++){
        for(j=0; j<columnas; j++){
          //-- Inicializo con 'L' --
          *(p+(i*columnas)+j) = MAPA_LIBRE;

        }
      }
    }

    //-- Pared Izquierda --
    for(i=0,j=0; i<filas; i++){
      *(p+(i*columnas)+j) = MAPA_PARED;
    }
    //-- Pared Abajo --
    for(i=(filas-1),j=0; j<columnas; j++){
      *(p+(i*columnas)+j) = MAPA_PARED;
    }
    //-- Pared Arriba --
    for(i=0,j=0; j<columnas; j++){
      *(p+(i*columnas)+j) = MAPA_PARED;
    }
    //-- Pared Derecha --
    for(i=0,j=(columnas-1); i<filas; i++){
      *(p+(i*columnas)+j) = MAPA_PARED;
    }

    //-- Inicio y fin --
    *(p+(1*columnas)+1) = MAPA_INICIO;
    *(p+((filas-2)*columnas)+(columnas-2)) = MAPA_FIN;

    return(p);

}


/**
	\fn mapaInicializar (int filas, int columnas)
	\brief Crea struct mapa_S e incializa mapa con esos datos.
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.09.29
	\param filas cantidad de filas de la matriz del mapa.
	\param columnas cantidad de columnas de la matriz del mapa.
	\return Puntero a la estructura con la informacion del mapa struct mapa_S.
*/
struct mapa_S* mapaInicializar (int filas, int columnas){

struct mapa_S *ptrS;
char  *ptrMatriz;
    //--Creo matriz --
    ptrMatriz = mapaVacioCrear(filas, columnas);
    //-- Pido memoria --
    ptrS = (struct mapa_S*) malloc (sizeof(struct mapa_S));
      //-- No hay memoria --
      if(ptrS==NULL){
        return(NULL);
      }

    //-- Incializo estructura
    ptrS->filas = filas;
    ptrS->columnas = columnas;
    ptrS-> theMatrix = ptrMatriz;
    ptrS->personajeFila = 1;
    ptrS->personajeColumna = 1;


//-- Devuelvo puntero a estrcutura inicializada --
return(ptrS);

}



/**
	\fn mapaImprimir (struct mapa_S *p)
	\brief Imprime mapa
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.09.29
	\param p Puntero a la estrcutura con la informacion del mapa.
	\return Un entero, 0 pudo imprimir, -1 error
*/
int mapaImprimir (struct mapa_S *p){

int i,j,filas,columnas,personajeFila,personajeColumna, matrizTamanio, personajeFuera, personajePared;
char *ptrMapa;
  //-- Verifico si es puntero a NULL --
  if(p == NULL){
    return(-1);
  }
  //-- Copio datos de la estructura a variables auxiliares para mejor manipulacion --
  filas = p->filas;
  columnas = p->columnas;
  ptrMapa = p->theMatrix;
  personajeFila = p->personajeFila;
  personajeColumna = p->personajeColumna;
  matrizTamanio = p->matrizTamanio ;
	personajeFuera = p->personajeFuera;
	personajePared = p->personajePared;


  if(matrizTamanio < 0 ||personajeFuera < 0 || personajePared < 0){
    return(-1);
  }

  //-- Imprimo datos de la estructura --
  printf("%d,%d\r\n%d,%d\r\n", filas, columnas, personajeFila, personajeColumna );
  //-- Imprimo mapa --
  for(i=0; i<filas; i++){
    for(j=0; j<columnas; j++){

      printf("%c", *(ptrMapa+(i*columnas)+j));

        }
        printf("\r\n");
    }

    return(0);

  }

/**
	\fn mapaLiberar (struct mapa_S *p)
	\brief libera struct mapa_S y su matriz asociada
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.10.03
	\param p Puntero a la estrcutura con la informacion del mapa.
	\return Un entero  0 pudo liberar, -1 p es NULL.
*/
  int mapaLiberar (struct mapa_S *p){
  char *ptrMatriz;
    //-- Verifico que p no sea NULL --
    if(p == NULL){
      return(-1);
    }
    //-- Uso puntero auxiliar para liberar --
    ptrMatriz = p->theMatrix;

    free(ptrMatriz); //-- Libero matriz --
    free(p);//-- Libero estructura --

    return (0);

  }


/**
	\fn mapaEscribir (char *nombre, struct mapa_S *p)
	\brief Almacena escenario en archivo de texto
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.10.03
	\param Puntero al nombre del archivo a crear.
	\param Puntero al mapa a almacenar.
	\return Entero  0 si pudo crear archivo, negativo indicando error.
*/
int mapaEscribir (char *nombre, struct mapa_S *p){
FILE *f;
char *ptrMatriz;
int i=0,j=0,aux,filas,columnas,personajeFila,personajeColumna;

//-- Paso datos de estructura a variables locales --
filas = p->filas;
columnas = p->columnas;
ptrMatriz = p->theMatrix;
personajeFila = p->personajeFila;
personajeColumna = p->personajeColumna;

  //-- Abro archivo --
  f = fopen (nombre, "w");
  if (f == NULL) {
    printf ("Error al abrir el archivo");
    return(-1);
  }

  //-- Escribo en el archivo datos de la matriz y el personaje --
  fprintf(f,"%d,%d\r\n",filas,columnas );
  fprintf(f,"%d,%d\r\n", personajeFila,personajeColumna);


/*  //-- Me posiciono al principio de cada fila y escribo de a tamaño de columnas --
  for(i=0,j=0; i<filas; i++,j+=columnas){

    fwrite((ptrMatriz + j), sizeof(char), columnas, f); //-- ptrMatriz es puntero al comienzo de la matriz --
    fprintf(f,"\r\n"); //-- Paso de fila en el archivo --

  }
*/

for(i=0; i<filas; i++){
  for(j=0; j<columnas; j++){
    if(*(ptrMatriz+(i*columnas)+j) == MAPA_LIBRE || *(ptrMatriz+(i*columnas)+j) == MAPA_VUELTA ){
    fprintf(f," ");
  }else{
    fprintf(f,"%c",*(ptrMatriz+(i*columnas)+j));
  }

  }
  fprintf(f,"\r\n");
}

  //-- Cierro archivo --
  aux = fclose (f);
  if (aux != 0){
    printf("Error al cerrar el archivo\r\n");
  }


return (0);

}


/**
	\fn mapaLeer (char * nombre)
	\brief Lee mapa de un archivo de texto y lo almacena en estructura.
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.10.03
	\param Puntero al nombre del archivo a crear.
	\return ptrS puntero a la estructura creada o NULL en caso de error.
*/
struct mapa_S * mapaLeer (char * nombre){

struct mapa_S *ptrS;
FILE *f;
char *bufferMatriz;//*auxRead;
int i=0,j=0,aux,filas,columnas,personajeFila,personajeColumna, t1,t2, tamanioMatriz;

      //-- Pido memoria --
      ptrS = (struct mapa_S *) malloc (sizeof(struct mapa_S));
      //-- No hay memoria --
      if(ptrS==NULL){
        return(NULL);
      }
      //-- Abro archivo --
      f = fopen (nombre, "r");
      if (f == NULL) {
        printf("Error al abrir el archivo");

      }

      //-- Inicializo indicadores en 0 --
      ptrS->matrizTamanio = 0;
      ptrS->personajeFuera = 0;
      ptrS->personajePared = 0;



      //-- Leo informacion de matriz y personaje --
      fscanf(f,"%d,%d\r\n",&filas,&columnas);
      fscanf(f,"%d,%d\r\n",&personajeFila,&personajeColumna);

      t1 = ftell (f);//-- Principio de la matriz --


      //-- Pido memoria para la matriz donde almacenare la matriz leida del archivo--
      bufferMatriz = (char*) malloc (filas * columnas);

      if(bufferMatriz == NULL){
        return(NULL);
      }

      //-- Si uso fread --
    /*  auxRead = (char*) malloc (2);
      if(auxRead == NULL){
        return(NULL);
      }
    */



      //--Leo desde archivo y almaceno en bufferMatriz hasta que encuentre EOF --
      while(feof(f)==0){

             //-- Me posiciono al principio de cada fila, dejo varias formas de leer--

                 //fscanf(f,"%[^\n]\r\n",(bufferMatriz+i));//-- Leo hasta salto de linea y paso a linea siguiente --
                 fscanf(f,"%s\r\n",(bufferMatriz+i));
                 //fread((bufferMatriz + i), sizeof(char), columnas, f);
                 //fread(auxRead, sizeof(char), 2, f);//-- Leo \r\n y los descarto
                 //fgets(bufferMatriz + i, columnas+3, f);
                 i+=columnas;// indice del puntero a la filas de la matriz
                 j++; // cantidad de filas reales
                }

                t2 = ftell(f);//-- Final de la matriz --

                //-- Calculo tamaño real de la matriz --
                tamanioMatriz = t2-t1-j; //-- con j resto los \n --
                //printf("Tamaño matriz:%d\r\n", tamanioMatriz);

                if(tamanioMatriz != (filas * columnas)){

                  printf("Tamaño incorrecto (mapaLeer)\r\n");
                  ptrS->matrizTamanio = -2;

                }


                if ( (personajeFila) < 1 || (personajeFila > filas) ){
                  printf("Personaje fuera de la matriz,fila.\r\n");
                  ptrS->personajeFuera = -3;

                }

                if ( (personajeColumna) < 1 || (personajeColumna > columnas) ){
                  printf("Personaje fuera de la matriz,columna.\r\n");
                  ptrS->personajeFuera = -3;
                }


                if(*(bufferMatriz+(personajeFila*columnas)+personajeColumna) == MAPA_PARED){
                  printf("Posicion del personaje incorrecta PARED\r\n");
                  ptrS->personajePared = -4;
                }


      //-- Inicializo estructura con los datos leidos del archivo --
      ptrS->filas = filas;
      ptrS->columnas = columnas;
      ptrS->theMatrix = bufferMatriz ;
      ptrS->personajeFila = personajeFila;
      ptrS->personajeColumna = personajeColumna;

      //-- Cierro archivo --
      aux = fclose (f);
      if (aux != 0){
        printf("Error al cerrar el archivo\r\n");
      }

//free(auxRead);
//-- Devuelvo puntero a estructura inicializada --
return(ptrS);

}

/**
	\fn mapaMarcar (struct mapa_S *p, int direccion)
	\brief Mueve el personaje una posicion en la direccion indicada y marca inicio y posicion actual.
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.10.03
	\param p Puntero a la estructura del mapa inicializada.
  \param direccion Entero que indica sentido del movimiento.
  \return Entero 0 si pudo avanzar, -1 si p es NULL, -2 si la direccion es invalida.
*/
int mapaMarcar (struct mapa_S *p, int direccion){

int personajeFila,personajeColumna,columnas;
char *ptrMatriz;


//-- Copio informacion de la estructura a variables locales --
columnas = p->columnas;
ptrMatriz = p->theMatrix;
personajeFila = p->personajeFila;
personajeColumna = p->personajeColumna;
    // -- Verifico que el puntero no sea NULL --
    if(p == NULL){
      return(-1);
    }


    //-- Switcheo segun valor de direccion --
    switch (direccion) {

      case ARRIBA:
                    //-- Marco inicio del personaje antes de moverse --
                    if (*(ptrMatriz+(personajeFila*columnas)+(personajeColumna)) != MAPA_INICIO){
                    *(ptrMatriz+(personajeFila*columnas)+(personajeColumna)) = MAPA_CAMINO;
                    }

                    //-- Marco nueva posicion del personaje --
                    if(*(ptrMatriz+((personajeFila-1)*columnas)+(personajeColumna))== MAPA_PARED){
                      return(-2); //-- Hay pared --
                    }else{
                    *(ptrMatriz+((personajeFila-1)*columnas)+(personajeColumna)) = MAPA_CAMINO;
                    //-- Actualizo estructura con nueva fila del personaje despues de moverse una posicion --
                    (p->personajeFila)--;
                    }break;

     case ABAJO:
                    //-- Marco inicio del personaje antes de moverse --
                    if (*(ptrMatriz+(personajeFila*columnas)+(personajeColumna)) != MAPA_INICIO){
                    *(ptrMatriz+(personajeFila*columnas)+(personajeColumna)) = MAPA_CAMINO;
                    }
                    //-- Marco nueva posicion del personaje --
                    if(*(ptrMatriz+((personajeFila+1)*columnas)+(personajeColumna))== MAPA_PARED) {
                      return(-2);
                    }else{
                    *(ptrMatriz+((personajeFila+1)*columnas)+(personajeColumna)) = MAPA_CAMINO;
                    //-- Actualizo estructura con nueva fila del personaje despues de moverse una posicion --
                    (p->personajeFila)++;
                    }break;

    case DERECHA :
                    //-- Marco inicio del personaje antes de moverse --
                    if (*(ptrMatriz+(personajeFila*columnas)+(personajeColumna)) != MAPA_INICIO){
                    *(ptrMatriz+(personajeFila*columnas)+(personajeColumna)) = MAPA_CAMINO;
                    }
                    //-- Marco nueva posicion del personaje --
                    if(*(ptrMatriz+(personajeFila*columnas)+(personajeColumna+1)) == MAPA_PARED){
                      return(-2);
                    }else{
                    *(ptrMatriz+(personajeFila*columnas)+(personajeColumna+1)) = MAPA_CAMINO;
                    //-- Actualizo estructura con nueva columna del personaje despues de moverse una posicion --
                    (p->personajeColumna)++;
                    }break;

   case IZQUIERDA :
                    //-- Marco inicio del personaje antes de moverse --
                    if (*(ptrMatriz+(personajeFila*columnas)+(personajeColumna)) != MAPA_INICIO){
                    *(ptrMatriz+(personajeFila*columnas)+(personajeColumna)) = MAPA_CAMINO;
                    }
                    //-- Marco nueva posicion del personaje --
                    if(*(ptrMatriz+(personajeFila*columnas)+(personajeColumna-1)) == MAPA_PARED){
                    return(-2);
                    }else{
                    *(ptrMatriz+(personajeFila*columnas)+(personajeColumna-1)) = MAPA_CAMINO;
                    //-- Actualizo estructura con nueva columna del personaje despues de moverse una posicion --
                    (p->personajeColumna)--;
                    }break;
                    //-- Si la direccion es invalida --
          default:  return(-2);

}
  mapaImprimir(p);
  getchar();

//-- Si pudo avanzar --
return(0);

}
