/********************************************************************************

	AUTLEN - Practica 1 
	Blanca Abella y Maria Barroso
	Pareja 3

*********************************************************************************/

#ifndef ALFABETO
#define ALFABETO

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OK 0
#define ERROR -1
#define TAM 256

typedef struct Alfabeto Alfabeto;

/********************************************************************************
	Funcion: crear_alfabeto
	Descripcion: crea un alfabeto
	Argumentos:
				-int size =  tamanno del alfabeto
	Salida:
				- *Alfabeto si se ha podido crear correctamente
				- NULL si ha habido algun problema a la hora de crearlo



 *********************************************************************************/
 Alfabeto* crear_alfabeto(int size);
 
 /********************************************************************************
	Funcion: eliminar_alfabeto
	Descripcion: elimina y libera memoria reservada para un alfabeto y lo que hay dentro de este
	Argumentos:
				-Alfabeto* alfabeto = alfabeto a eliminar
	Salida:
				- OK si todo ha ido bien
				- ERROR en otro caso



 *********************************************************************************/
int eliminar_alfabeto(Alfabeto* alfabeto);

 /********************************************************************************
	Funcion: size_alfabeto
	Descripcion: consigue el tamanno de un alfabeto
	Argumentos:
				-Alfabeto* alfabeto:
	Salida:
				- tammano del alfabeto
				- ERROR en otro caso



 *********************************************************************************/
int size_alfabeto(Alfabeto* alfabeto);

 /********************************************************************************
	Funcion: devuelve simbolo de un alfabeto dada una posicion
	Descripcion: consigue el simbolo de un alfabeto
	Argumentos:
				-Alfabeto* alfabeto
				- int posicion
	Salida:
				- simbolo del alfabeto
				- ERROR en otro caso



 *********************************************************************************/
char* get_simbolo_pos(int posicion, Alfabeto* alf);

 /********************************************************************************
	Funcion: insertar_simbolo
	Descripcion: inserta un simbolo en un alfabeto
	Argumentos:
				-char* simbolo = simbolo a insertar
				- Alfabeto* a = alfabeto
	Salida:
				- OK si todo ha ido bien
				- ERROR en otro caso



 *********************************************************************************/
int insertar_simbolo(char* simbolo, Alfabeto* a);

 /********************************************************************************
	Funcion: imprime_alfabeto
	Descripcion: imprime un alfabeto
	Argumentos:
				- FILE* fd
				- Alfabeto* a
	Salida:
				- OK si todo ha salido bien
				- ERROR en otro caso



 *********************************************************************************/

int imprime_alfabeto(FILE* fd,  Alfabeto* a);




#endif

