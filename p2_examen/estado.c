/********************************************************************************

	AUTLEN - Practica 1
	Blanca Abella y Maria Barroso
	Pareja 3

*********************************************************************************/

#include "estado.h"

struct Estado {
	char * nombre; /* Nombre del estado */
	enum TIPO tipo; /* Tipo de estado */
	Transicion** transiciones; /* Transiciones de un estado */
	int ntran; /* Numero de transiciones de un estado */
};

/********************************************************************************
	Funcion: crear_estado
	Descripcion: crea un estado sin transiciones
	Argumentos:
				- char * nombre
				- enum TIPO tipo
	Salida:
				- *Estado si se ha podido crear correctamente
				- NULL si ha habido algun problema a la hora de crearlo



 *********************************************************************************/
 Estado* crear_estado(char * nombre, enum TIPO tipo){
 	if(!nombre)
 		return NULL;

 	Estado* estado = NULL;
 	estado = (Estado*)malloc(sizeof(Estado));
 	if(!estado)
 		return NULL;

 	estado->nombre=(char*)malloc(TAM*sizeof(char));
 	if(!estado->nombre){
 		free(estado);
 		return NULL;
 	}
 	strcpy(estado->nombre,nombre);

 	estado->transiciones = NULL;
 	estado->ntran = 0;
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
	int i;
	if(!estado)
		return ERROR;
	if(estado->nombre)
		free(estado->nombre);
	if(estado->ntran > 0){
		for(i = 0; i < estado->ntran; i++)
			if(estado->transiciones[i])
				eliminar_transicion(estado->transiciones[i]);
		free(estado->transiciones);
	}
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
				- NULL en otro caso



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
enum TIPO get_tipo(Estado* estado){
	if(!estado)
		return ERROR;
	return estado->tipo;
}

 /********************************************************************************
	Funcion: get_transiciones
	Descripcion: devuelve las transiciones de un estado
	Argumentos:
				- Estado* estado
	Salida:
				- Tranciones de un estado
				- NULL en otro caso



 *********************************************************************************/
Transicion** get_transiciones(Estado* estado){
	if(!estado)
		return NULL;
	return estado->transiciones;
}

 /********************************************************************************
	Funcion: get_ntran
	Descripcion: devuelve el numero de transiciones de un estado
	Argumentos:
				- Estado* estado
	Salida:
				- numero de transiciones de un estado
				- ERROR en otro caso



 *********************************************************************************/
int get_ntran(Estado* estado){
	if(!estado)
		return ERROR;
	return estado->ntran;
}

 /********************************************************************************
	Funcion: inserta_transicion
	Descripcion: inserta una transicion creada a partir de un valor y un estado final
	Argumentos:
				- Estado* estado
				- char * valor
				- char* final
	Salida:
				- OK si todo ha salido bien
				- ERROR en otro caso



 *********************************************************************************/
int inserta_transicion(Estado* estado, char* valor, char* final){
	Transicion ** aux= NULL, **tran =  NULL;
	int i = 0, ntran;
	if(!valor || !estado || !final){
		return ERROR;
	}
	ntran = get_ntran(estado);
	if(ntran>0){ /*Si no es la primera transicion, comprobamos que exista un valor para esa transicion*/
		tran = get_transiciones(estado);
		for(i = 0; i<ntran;i++){
			if(!strcmp(valor,get_valor(tran[i]))){
				insertar_estadoFinal(tran[i], final);
				return OK;
			}
		}
	}
	/*Si es la primera transicion del estado
	o lo es para un determinado valor,
	entonces la creamos directamente*/
	estado->ntran += 1;
	aux = (Transicion **)realloc(estado->transiciones, estado->ntran*(sizeof(Transicion*)));
	if (!aux) {
		estado->ntran -= 1;
		return ERROR;
	}
	estado->transiciones=aux;
	estado->transiciones[estado->ntran-1] = crear_transicion(valor, final);
	return OK;
}

 /********************************************************************************
	Funcion: funcion_transicion
	Descripcion: devuelve el resultado de aplicar la funcion de transicion a un estado
	Argumentos:
				- Estado* estado
				- char* valor
	Salida:
				- estados resultado de la funcion
				- NULL en otro caso



 *********************************************************************************/
char** funcion_transicion(Estado* e, char* valor){
	int i = 0, ntran;
	Transicion**transiciones;
	ntran = get_ntran(e);
	if(ntran == 0)
		return NULL;
	transiciones = get_transiciones(e);
	for(i=0; i<ntran; i++)
		if(!strcmp(valor,get_valor(transiciones[i])))
			return get_finales(transiciones[i]);
	return NULL;
}


 /********************************************************************************
	Funcion: buscar_transicion
	Descripcion: devuelve los estados finales de la transicion de un
				 estado para un determinado valor

	Argumentos:
				- Estado* estado
				- char * valor
	Salida:
				- estados finales
				- NULL en otro caso



 *********************************************************************************/
char** buscar_transicion(Estado* estado, char* valor){
	int ntran, i;
	Transicion **trans;
	if(!estado || !valor)
		return NULL;
	ntran = get_ntran(estado);
	if(ntran==0){
		return NULL;
	}
	trans = get_transiciones(estado);
	for(i = 0; i<ntran; i++){
		if(!strcmp(get_valor(trans[i]),valor))
			return get_finales(trans[i]);
	}
	return NULL;
}
 /********************************************************************************
	Funcion: get_nfinales_transicion
	Descripcion: devuelve el numero de estados finales de la transicion de un
				 estado para un determinado valor

	Argumentos:
				- Estado* estado
				- char * valor
	Salida:
				- numero de estados finales
				- ERROR en otro caso



 *********************************************************************************/
int get_nfinales_transicion(Estado* estado, char* valor){
	int ntran, i;
	Transicion **trans;
	if(!estado || !valor)
		return ERROR;
	ntran = get_ntran(estado);
	if(ntran==0){
		return ERROR;
	}
	trans = get_transiciones(estado);
	for(i = 0; i<ntran; i++){
		if(!strcmp(get_valor(trans[i]),valor))
			return get_nfinales(trans[i]);
	}
	return ERROR;
}
