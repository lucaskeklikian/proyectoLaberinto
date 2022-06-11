/**
	\file matriz.h
	\brief Archivo que contiene la informacion para las matrices.
	\author Lucas Hernan Keklikian (lucaskeklikian@gmail.com)
	\date 2018.09.28
*/
#ifndef MATRIZ_H
#define MATRIZ_H


//-- MATRIZ --
#define FILAS				((int)10)	//!< Numero de filas.
#define COLUMNAS				((int)10)	//!< Numero de columnas.


//-----------------
//-- Protototype --
//-----------------
void matrizImprimir (char *p, int filas, int columnas);
char* matrizCrear (int filas, int columnas, char valor);



#endif
