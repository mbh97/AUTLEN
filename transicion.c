#include "transicion.h"

/********************************************************************************
	Funcion: crear_transicion
	Descripcion: crea una transicion
	Argumentos:
				- char* valor: valor de la transicion
				- char * estado: estado final de la transicion
	Salida:
				- *Transicion si se ha podido crear correctamente
				- NULL si ha habido algun problema a la hora de crearlo



 *********************************************************************************/
 Transicion* crear_transicion(char* valor, char * estado){
	if(!valor || !estado)
		return NULL;
	Transicion* transicion = NULL;
	transicion = (Transicion*)malloc(sizeof(Transicion));
	if(!transicion)
		return NULL;
	transicion->estado = (char *)malloc(TAM*sizeof(char));
	if(!transicion->estado){
		free(transicion);
		return NULL;
	}
	strcpy(transicion->estado, estado);
	transicion->valor = (char *)malloc(TAM*sizeof(char));
	if(!transicion->valor){
		free(transicion->estado);
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
	if(!transicion)
		return ERROR;
	free(transicion->estado);
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
	Funcion: get_estado
	Descripcion: consigue el estado final de una transicion
	Argumentos: 
				-Transicion* transicion: 
	Salida:
				- estado de una transicion
				- ERROR en otro caso



 *********************************************************************************/
char* get_estado(Transicion* transicion){
	if(!transicion)
		return NULL;
	return transicion->estado;
}

Transicion* copiar_transicion(Transicion * transicion){
	Transicion* copia = NULL;
	if(!transicion)
		return NULL;

	copia = crear_transicion(get_valor(transicion),get_estado(transicion));
	if(!copia)
		return NULL;
	return copia;
}