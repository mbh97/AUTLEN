/********************************************************************************

	AUTLEN - Practica 1
	Blanca Abella y Maria Barroso
	Pareja 3

*********************************************************************************/
#include "lambda.h"

struct Lambda {
	int ** matriz; /*matriz para las transiciones lambda */
	int size; /* size de la matriz (binaria) */
};


/********************************************************************************
Funcion: inicializa_lambda
Descripcion: Inicializa matriz lambda binaria
Argumentos:
      -int size =  size de la matriz binaria
Salida:
      - *Lambda si se ha podido crear correctamente
      - NULL si ha habido algun problema a la hora de crearlo



 *********************************************************************************/
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

 /********************************************************************************
	Funcion: elimina_lambda
	Descripcion: elimina y libera memoria reservada para una matriz lambda y lo que hay dentro de esta
	Argumentos:
				- Lambda * lambda = lambda a eliminar
	Salida:
				void


 *********************************************************************************/
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
void insertaLTransicion(Lambda*lambda, int i, int f){
	lambda->matriz[i][f] = 1;
}

 /********************************************************************************
	Funcion: cierraLReflexiva
	Descripcion: Modifica a 1 el valor de la diaginal de la matriz de lambda (reflexiva)
	Argumentos:
				- Lambda*lambda = lambda a insertar transiciones reflexivas

	Salida:
				void



 *********************************************************************************/
void cierraLReflexiva(Lambda*lambda){
	int i;
	for(i = 0; i<lambda->size; i++){
		insertaLTransicion(lambda, i,i);
	}
}

 /********************************************************************************
	Funcion: cierraLTransitiva
	Descripcion: Modifica a 1 el valor para aquellas posiciones de la matriz de
				lambda en las ue se cumple la propiedad transitiva
	Argumentos:
				- Lambda*lambda = lambda a insertar transiciones transitivas

	Salida:
				void



 *********************************************************************************/
void cierraLTransitiva(Lambda* lambda){
	int i=0,j=0,z=0;
	for(i = 0; i<lambda->size; i++){
		for(j = 0; j<lambda->size; j++){
			if(lambda->matriz[i][j] == 1){
				for(z = 0; z<lambda->size; z++){
					if(lambda->matriz[j][z] == 1){
						if(lambda->matriz[i][z] != 1){
							insertaLTransicion(lambda, i,z);
							j=0;
						}
					}
				}

			}
		}
	}
}

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
int getLvalor(Lambda * lambda, int i, int j){
	return lambda->matriz[i][j];
}

 /********************************************************************************
	Funcion: imprime_lambda
	Descripcion: imprime una matriz de transicions lambda
	Argumentos:
				- FILE *fd
				- Lambda* lambda
	Salida:
				void



 *********************************************************************************/
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
