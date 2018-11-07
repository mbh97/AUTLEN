/********************************************************************************

	AUTLEN - Practica 1 
	Blanca Abella y Maria Barroso
	Pareja 3

*********************************************************************************/
#include "../include/lambda.h"

struct Lambda {
	int ** matriz; /*matriz para las transiciones lambda */
	int size; /* size de la matriz (binaria) */
};

Lambda * inicializa_lambda(int size){
	int i, j;
	Lambda * lambda = NULL;
	lambda = (Lambda*)malloc(sizeof(Lambda));
	if(!lambda){
		return NULL;
	}

	lambda->matriz = (int **)malloc(size*sizeof(int *));
	if(!lambda->matriz){
		free(lambda);
		return NULL;
	}
	for(i = 0; i < size; i++){
		lambda->matriz[i] = (int *)malloc(size*sizeof(int));
	}
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			lambda->matriz[i][j] = 0;
		}
	}
	lambda->size = size;
	return lambda;
}


void elimina_lambda(Lambda * lambda){
	int i;
	if(!lambda)
		return;
	for(i = 0; i < lambda->size; i++){
		free(lambda->matriz[i]);
	}
	free(lambda->matriz);
	free(lambda);
}

void insertaLTransicion(Lambda*lambda, int i, int f){
	lambda->matriz[i][f] = 1;
}

void cierraLReflexiva(Lambda*lambda){
	int i;
	for(i = 0; i<lambda->size; i++){
		insertaLTransicion(lambda, i,i);
	}
}

void cierraLTransitiva(Lambda* lambda){
	int i,j,z;
	for(i = 0; i<lambda->size; i++){
		for(j = 0; j<lambda->size; j++){
			if(lambda->matriz[i][j] == 1){
				for(z = 0; z<lambda->size; z++){
					if(lambda->matriz[j][z] == 1){
						insertaLTransicion(lambda, i,z);
					}
				}
				
			}
		}
	}
}

int getLvalor(Lambda * lambda, int i, int j){
	return lambda->matriz[i][j];
}

void imprime_lambda(FILE* fd, Lambda* lambda){
	int i, j;
	fprintf(fd, "\tRL++*={\n");
	fprintf(fd, "\t\t");
	for(i = 0; i<lambda->size; i++){
		fprintf(fd, "\t[%d]", i);
	}
	fprintf(fd, "\n");
	for(i = 0; i<lambda->size; i++){
		fprintf(fd, "\t\t[%d]",i);
		for(j=0; j<lambda->size; j++){
			fprintf(fd, "\t%d", lambda->matriz[i][j]);
		}
		fprintf(fd, "\n");
	}
	printf("\t}\n");
}