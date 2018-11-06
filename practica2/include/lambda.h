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


Lambda * inicializa_lambda(int size);

void elimina_lambda(Lambda * lambda);


void insertaLTransicion(Lambda*lambda, int i, int f);

void cierraLReflexiva(Lambda*lambda);

void cierraLTransitiva(Lambda* lambda);

int getLvalor(Lambda * lambda, int i, int j);

void imprime_lambda(FILE* fd, Lambda* lambda);

#endif