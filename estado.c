#include "estado.h"

/********************************************************************************
	Funcion: crear_estado
	Descripcion: crea un estado
	Argumentos: 
				- char * nombre
				- enum TIPO tipo
	Salida:
				- *Estado si se ha podido crear correctamente
				- NULL si ha habido algun problema a la hora de crearlo



 *********************************************************************************/
 Estado* crear_estado(char * nombre, TIPO tipo){
 	if(!nombre || !tipo)
 		return NULL;

 	Estado* estado = NULL;
 	estado = (Estado*)malloc(sizeof(Estado));
 	if(!estado)
 		return NULL
 	estado->nombre=(char*)malloc(TAM*sizeof(char));
 	if(!estado->nombre){
 		free(estado);
 		return NULL;
 	}
 	estado->nombre = nombre;
 	estado->tipo = tipo;
 	return estado;
 }

 /********************************************************************************
	Funcion: eliminar_estado
	Descripcion: elimina y libera memoria reservada para un estado y lo que hay dentro de este
	Argumentos: 
				- Estado* estado = estado a eliminar
	Salida:
				- OK si todo ha ido bien
				- ERROR en otro caso



 *********************************************************************************/
int eliminar_estado(Estado* estado){
	if(!estado)
		return ERROR;
	if(estado->nombre)
		free(estado->nombre);
	free(estado);
	return OK;
}


 /********************************************************************************
	Funcion: get_nombre
	Descripcion: consigue el nombre de un estado
	Argumentos: 
				- Estado* estado
	Salida:
				- nombre del estado
				- ERROR en otro caso



 *********************************************************************************/
char* get_nombre(Estado* estado){
	if(!estado)
		return NULL;
	return estado->nombre;
}

 /********************************************************************************
	Funcion: get_tipo
	Descripcion: consigue el tipo de un estado
	Argumentos: 
				- Estado* estado
	Salida:
				- tipo del estado
				- ERROR en otro caso



 *********************************************************************************/
TIPO get_tipo(Estado* estado){
	if(!estado)
		return ERROR;
	return estado->tipo;
}

 /********************************************************************************
	Funcion: set_tipo
	Descripcion: modifica el tipo de un estado
	Argumentos: 
				- Estado* estado
				- TIPO newTipo
	Salida:
				- OK si todo ha salido bien
				- ERROR en otro caso



 *********************************************************************************/
int set_tipo(Estado* estado, TIPO newTipo){
	if(!estado)
		return ERROR;
	estado->tipo = newTipo;
	return OK;
}