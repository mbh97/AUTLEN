/********************************************************************************

	AUTLEN - Practica 1 
	Blanca Abella y Maria Barroso
	Pareja 3

*********************************************************************************/
#ifndef LAMBDA
#define LAMBDA

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Lambda Lambda;

/********************************************************************************
Funcion: inicializa_lambda
Descripcion: Inicializa matriz lambda binaria
Argumentos:
      -int size =  size de la matriz binaria
Salida:
      - *Lambda si se ha podido crear correctamente
      - NULL si ha habido algun problema a la hora de crearlo



 *********************************************************************************/
Lambda * inicializa_lambda(int size);

 /********************************************************************************
	Funcion: elimina_lambda
	Descripcion: elimina y libera memoria reservada para una matriz lambda y lo que hay dentro de esta
	Argumentos:
				- Lambda * lambda = lambda a eliminar
	Salida:
				void


 *********************************************************************************/
void elimina_lambda(Lambda * lambda);

 /********************************************************************************
	Funcion: insertaLTransicion
	Descripcion: Modifica a 1 el valor de una determinada posicion de la matriz de lambda
	Argumentos:
				- Lambda*lambda = lambda a insertar transicion
				- int i = fila de la matriz
				- int f = columna de la matriz
	Salida:
				void



 *********************************************************************************/
void insertaLTransicion(Lambda*lambda, int i, int f);

 /********************************************************************************
	Funcion: cierraLReflexiva
	Descripcion: Modifica a 1 el valor de la diaginal de la matriz de lambda (reflexiva)
	Argumentos:
				- Lambda*lambda = lambda a insertar transiciones reflexivas

	Salida:
				void



 *********************************************************************************/
void cierraLReflexiva(Lambda*lambda);

 /********************************************************************************
	Funcion: cierraLTransitiva
	Descripcion: Modifica a 1 el valor para aquellas posiciones de la matriz de 
				lambda en las ue se cumple la propiedad transitiva
	Argumentos:
				- Lambda*lambda = lambda a insertar transiciones transitivas

	Salida:
				void



 *********************************************************************************/
void cierraLTransitiva(Lambda* lambda);

 /********************************************************************************
	Funcion: getLvalor
	Descripcion: devuelve el valor de la matriz de lambda dada una posicion
	Argumentos:
				- Lambda*lambda
				- int i = fila de la matriz
				- int f = columna de la matriz
	Salida:
				void



 *********************************************************************************/
int getLvalor(Lambda * lambda, int i, int j);

 /********************************************************************************
	Funcion: imprime_lambda
	Descripcion: imprime una matriz de transicions lambda
	Argumentos: 
				- FILE *fd
				- Lambda* lambda
	Salida:
				void



 *********************************************************************************/
void imprime_lambda(FILE* fd, Lambda* lambda);

#endif