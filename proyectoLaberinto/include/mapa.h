/**
	\file mapa.h
	\brief Archivo que contiene la informacion para armar los mapas.
	\author Jerónimo F. Atencio (jerome5416@gmail.com)
	\date 2018.09.27
*/
#ifndef MAPA_H
#define MAPA_H

//-- MAPA --
#define MAPA_LIBRE				((char)'L')	//!< Lugar libre.
#define MAPA_PARED				((char)'W')	//!< Pared del mapa.
#define MAPA_INICIO				((char)'I')	//!< Inicio del laberinto.
#define MAPA_FIN				((char)'F')	//!< Final del laberinto.
#define MAPA_CAMINO				((char)'X')	//!< Camino recorrido por el personaje.
#define MAPA_VUELTA				((char)'O')	//!< Camino de vuelta al nodo.

//-- Direccion --
#define ARRIBA					((int)0)	//!< Arriba
#define ABAJO					((int)1)	//!< Abajo
#define IZQUIERDA				((int)2)	//!< Izquierda
#define DERECHA					((int)3)	//!< Derecha


/**	\struct mapa_S
	\brief Estructura de del mapa.
*/
struct mapa_S {
	int filas;				//!< Cantidad de filas del mapa.
	int columnas;			//!< Cantidad de columnas del mapa.
	char *theMatrix	;		//!< Puntero a la matriz del mapa.
	int personajeFila;		//!< Fila donde se encuentra el personaje.
	int personajeColumna;	//!< Columna donde se encuentra el personaje.
	int matrizTamanio;//!< Indicador de tamaño de matriz incorrecto.
	int personajeFuera;//!< Indicador de personaje fuera de la matriz.
	int personajePared;//!< Indicador de personaje sobre pared.
};

/**	\struct camino
	\brief Estructura que almacena lo que hay alrededor de donde estoy parado y su coordenada.
*/
struct camino {
char alrededor[4];//-- Almaceno lo que hay alrededor 0=Ar 1=Ab 2=Izq 3=Der --
int coordenada [2];//-- Donde estoy parado 0=fila 1=columna --
};

//-----------------
//-- Protototype --
//-----------------
char * mapaVacioCrear (int filas, int columnas);
struct mapa_S * mapaInicializar (int filas, int columnas);
int mapaImprimir (struct mapa_S *p);
int mapaLiberar (struct mapa_S *p);
int mapaEscribir (char * nombre, struct mapa_S *p);
struct mapa_S * mapaLeer (char * nombre);
int mapaMarcar (struct mapa_S *p, int direccion);
struct mapa_S* laberintoResolver (struct mapa_S *p, int *cant);
int mapaDesmarcar(int *ptrNf, int *ptrNc,int n,int *Cf, int*Cc,int c, struct mapa_S *p);

#endif
