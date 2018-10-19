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
 	estado->transiciones = NULL;
 	estado->ntran = 0;
 	strcpy(estado->nombre,nombre);
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
	Funcion: funcion_transicion
	Descripcion: devuelve el resultado de aplicar la funcion de transicion a un estado
	Argumentos: 
				- Estado* estado
				- char* valor 
	Salida:
				- nombre del siguiente estado
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
		if(!strcmp(valor,get_valor(transiciones[i]))){
			return get_finales(transiciones[i]);
		}
	return NULL;
}


 /********************************************************************************
	Funcion: imprime_estado
	Descripcion: imprime un estado
	Argumentos: 
				- Estado* estado
	Salida:
				- OK si todo ha salido bien
				- ERROR en otro caso



 *********************************************************************************/
int imprime_estado(Estado* estado){
	int i =0;
	if(!estado)
		return ERROR;
 	if(estado->tipo==INICIAL)
		printf("E = { %s, INICIAL }\n", estado->nombre);
	if(estado->tipo==NORMAL)
		printf("E = { %s, NORMAL }\n", estado->nombre);
	if(estado->tipo==FINAL)
		printf("E = { %s, FINAL }\n", estado->nombre);
	if(estado->tipo==INICIAL_Y_FINAL)
		printf("E = { %s, INICIAL_Y_FINAL }\n", estado->nombre);
	printf("Transiciones: \n");
	for(i=0; i<estado->ntran; i++){
		imprimir_transicion(estado->transiciones[i]);
	}
	return OK;
}

 /********************************************************************************
	Funcion: inserta_transicion
	Descripcion: inserta transicion
	Argumentos: 
				- Estado* estado
				- Transicion * tran
	Salida:
				- OK si todo ha salido bien
				- ERROR en otro caso



 *********************************************************************************/
int inserta_transicion(Estado* estado, char* valor, char*final){
	Transicion ** aux= NULL, **tran =  NULL;
	int i = 0, ntran;
	if(!valor || !estado || !final){
		return ERROR;
	}
	ntran = get_ntran(estado);
	if(ntran>0){
		tran = get_transiciones(estado);
		for(i = 0; i<ntran;i++){
			if(!strcmp(valor,get_valor(tran[i]))){
				insertar_estadoFinal(tran[i], final);
				return OK;
			}
		}
	}
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

int get_nfinales_transicion(Estado* estado, char* valor){
	int ntran, i;
	Transicion **trans;
	if(!estado || !valor)
		return -1;
	ntran = get_ntran(estado);
	if(ntran==0){
		return -1;
	}
	trans = get_transiciones(estado);
	for(i = 0; i<ntran; i++){
		if(!strcmp(get_valor(trans[i]),valor))
			return get_nfinales(trans[i]);
	}
	return -1;
}

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