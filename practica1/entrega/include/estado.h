#ifndef ESTADO
#define ESTADO

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "transicion.h"


#define OK 0
#define ERROR -1
#define TAM 256

enum TIPO{
	INICIAL = 0,
	NORMAL = 1,
	FINAL = 2,
	INICIAL_Y_FINAL = 3
};

typedef struct Estado Estado;


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
 Estado* crear_estado(char * nombre, enum TIPO tipo);

 /********************************************************************************
	Funcion: eliminar_estado
	Descripcion: elimina y libera memoria reservada para un estado y lo que hay dentro de este
	Argumentos: 
				- Estado* estado = estado a eliminar
	Salida:
				- OK si todo ha ido bien
				- ERROR en otro caso



 *********************************************************************************/
int eliminar_estado(Estado* estado);


 /********************************************************************************
	Funcion: get_nombre
	Descripcion: consigue el nombre de un estado
	Argumentos: 
				- Estado* estado
	Salida:
				- nombre del estado
				- ERROR en otro caso



 *********************************************************************************/
char* get_nombre(Estado* estado);

 /********************************************************************************
	Funcion: get_tipo
	Descripcion: consigue el tipo de un estado
	Argumentos: 
				- Estado* estado
	Salida:
				- tipo del estado
				- ERROR en otro caso



 *********************************************************************************/
enum TIPO get_tipo(Estado* estado);

 /********************************************************************************
	Funcion: get_transiciones
	Descripcion: devuelve las transiciones de un estado
	Argumentos: 
				- Estado* estado
	Salida:
				- Tranciones de un estado
				- NULL en otro caso



 *********************************************************************************/
Transicion** get_transiciones(Estado* estado);

 /********************************************************************************
	Funcion: get_ntran
	Descripcion: devuelve el numero de transiciones de un estado
	Argumentos: 
				- Estado* estado
	Salida:
				- numero de transiciones de un estado
				- ERROR en otro caso



 *********************************************************************************/
int get_ntran(Estado* estado);

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
int inserta_transicion(Estado* estado, char* valor, char*final);

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
char** funcion_transicion(Estado* e, char* valor);

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
char** buscar_transicion(Estado* estado, char* valor);

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
int get_nfinales_transicion(Estado* estado, char* valor);



#endif
