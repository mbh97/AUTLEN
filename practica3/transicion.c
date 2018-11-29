/********************************************************************************

	AUTLEN - Practica 1 
	Blanca Abella y Maria Barroso
	Pareja 3

*********************************************************************************/

#include "transicion.h"

struct Transicion {
	char* valor; /* valor de la transicion */
	char ** finales; /* estados finales de la transicion */
	int nfinales; /* numero de estados finales de la transicion */
};

/********************************************************************************
	Funcion: crear_transicion
	Descripcion: crea una transicion con valor y un estado final
	Argumentos:
				- char* valor: valor de la transicion
				- char * estado: estado final de la transicion
	Salida:
				- *Transicion si se ha podido crear correctamente
				- NULL si ha habido algun problema a la hora de crearlo



 *********************************************************************************/
 Transicion* crear_transicion(char* valor, char * final){
 	Transicion* transicion = NULL;
	if(!valor || !final)
		return NULL;

	transicion = (Transicion*)malloc(sizeof(Transicion));
	if(!transicion)
		return NULL;
	
	transicion->finales = (char **)malloc(sizeof(char *));
	if (!transicion->finales) {
		free(transicion);
		return NULL;
	}
	transicion->nfinales = 1;
	transicion->finales[0] = (char *)malloc(TAM*sizeof(char));
	strcpy(transicion->finales[0], final);
	
	transicion->valor = (char *)malloc(TAM*sizeof(char));
	if(!transicion->valor){
		free(transicion->finales);
		free(transicion);
		return NULL;
	}
	strcpy(transicion->valor, valor);
	
	return transicion;
 }
 
  /********************************************************************************
	Funcion: eliminar_transicion
	Descripcion: elimina y libera memoria reservada para una transicion y lo que hay dentro de esta
	Argumentos: 
				-Transicion* transicion = transicion a eliminar
	Salida:
				- OK si todo ha ido bien
				- ERROR en otro caso



 *********************************************************************************/
int eliminar_transicion(Transicion* transicion){
	int i = 0;
	if(!transicion)
		return ERROR;
	for(i=0; i<transicion->nfinales; i++){
		free(transicion->finales[i]);
	}
	free(transicion->finales);
	free(transicion->valor);
	free(transicion);
	return OK;
}

/********************************************************************************
	Funcion: get_valor
	Descripcion: consigue el valor de una transicion
	Argumentos: 
				-Transicion* transicion: 
	Salida:
				- valor de una transicion
				- ERROR en otro caso



 *********************************************************************************/
char* get_valor(Transicion* transicion){
	if(!transicion)
		return NULL;
	return transicion->valor;
}

/********************************************************************************
	Funcion: get_finales
	Descripcion: consigue el estado final de una transicion
	Argumentos: 
				-Transicion* transicion: 
	Salida:
				- simbolos finales de una transicion
				- ERROR en otro caso



 *********************************************************************************/
char** get_finales(Transicion* transicion){
	if(!transicion)
		return NULL;
	return transicion->finales;
}

/********************************************************************************
	Funcion: get_nfinales
	Descripcion: consigue el numero de estado final de una transicion
	Argumentos: 
				-Transicion* transicion: 
	Salida:
				- numero de simbolos finales de una transicion
				- ERROR en otro caso



 *********************************************************************************/
int get_nfinales(Transicion* transicion){
	if(!transicion)
		return ERROR;
	return transicion->nfinales;
}

/********************************************************************************
	Funcion: insertar_estadoFinal
	Descripcion: inserta un estado final a una transicion
	Argumentos: 
				-Transicion* transicion
				- char* final
	Salida:
				


 *********************************************************************************/
void insertar_estadoFinal(Transicion* transicion, char* final){
	char** aux= NULL;
	if(!transicion || !final)
		return;

	transicion->nfinales += 1;
	aux = (char **)realloc(transicion->finales, transicion->nfinales*(sizeof(char *)));
	if (!aux) {
		transicion->nfinales -= 1;
		return;
	}
	transicion->finales=aux;
	transicion->finales[transicion->nfinales-1] = (char*)malloc(TAM*sizeof(char));
	strcpy(transicion->finales[transicion->nfinales-1], final);
	return;
}
