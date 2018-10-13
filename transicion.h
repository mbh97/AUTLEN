#ifndef TRANSICION
#define TRANSICION

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//CONSTANTES
#define OK 0
#define ERROR -1
#define TAM 256

typedef struct Transicion {
	char* valor; // valor de la transicion
	char * estado; // estado final de la transicion
} Transicion;

/********************************************************************************
	Funcion: crear_transicion
	Descripcion: crea una transicion
	Argumentos:
				- char* valor: valor de la transicion
				- Estado * estado: estado final de la transicion
	Salida:
				- *Transicion si se ha podido crear correctamente
				- NULL si ha habido algun problema a la hora de crearlo



 *********************************************************************************/
 Transicion* crear_transicion(char* valor, Estado * estado);
 
  /********************************************************************************
	Funcion: eliminar_transicion
	Descripcion: elimina y libera memoria reservada para una transicion y lo que hay dentro de esta
	Argumentos: 
				-Transicion* transicion = transicion a eliminar
	Salida:
				- OK si todo ha ido bien
				- ERROR en otro caso



 *********************************************************************************/
int eliminar_transicion(Transicion* transicion);

/********************************************************************************
	Funcion: get_valor
	Descripcion: consigue el valor de una transicion
	Argumentos: 
				-Transicion* transicion: 
	Salida:
				- valor de una transicion
				- ERROR en otro caso



 *********************************************************************************/
char* get_valor(Transicion* transicion);

/********************************************************************************
	Funcion: get_estado
	Descripcion: consigue el estado final de una transicion
	Argumentos: 
				-Transicion* transicion: 
	Salida:
				- estado de una transicion
				- ERROR en otro caso



 *********************************************************************************/
Estado* get_estado(Transicion* transicion);



 
 

#endif
