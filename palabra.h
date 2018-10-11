#ifndef PALABRA
#define PALABRA

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//CONSTANTES
#define OK 0
#define ERROR -1
#define TAM 256


typedef struct Palabra {
	char ** simbolos; // array de simbolos
	int size; // tamanno de la palabra
} Palabra;


/********************************************************************************
	Funcion: crear_palabra
	Descripcion: crea una palabra
	Argumentos: -
	Salida:
				- *Palabra si se ha podido crear correctamente
				- NULL si ha habido algun problema a la hora de crearlo



 *********************************************************************************/
 Palabra* crear_palabra();

 /********************************************************************************
	Funcion: eliminar_palabra
	Descripcion: elimina y libera memoria reservada para una palabra y lo que hay dentro de esta
	Argumentos:
				-Palabra* palabra = palabra a eliminar
	Salida:
				- OK si todo ha ido bien
				- ERROR en otro caso



 *********************************************************************************/
int eliminar_palabra(Palabra* palabra);

 /********************************************************************************
	Funcion: get_size
	Descripcion: consigue el tamanno de una palabra
	Argumentos:
				-Palabra* palabra:
	Salida:
				- tammano del palabra
				- ERROR en otro caso



 *********************************************************************************/
int get_size(Palabra* palabra);

 /********************************************************************************
	Funcion: insertar_letra
	Descripcion: inserta un simbolo en un palabra
	Argumentos:
				-char* simbolo = simbolo a insertar
				- Palabra* palabra = palabra
	Salida:
				- OK si todo ha ido bien
				- ERROR en otro caso



 *********************************************************************************/
int insertar_letra(char* simbolo, Palabra* palabra);

 /********************************************************************************
	Funcion: eliminar_simbolo
	Descripcion: elimina un simbolo en un palabra
	Argumentos:
				-char* simbolo = simbolo a eliminar
				- Palabra* palabra = palabra
	Salida:
				- OK si todo ha ido bien
				- ERROR en otro caso



 *********************************************************************************/
int eliminar_letra(Palabra* palabra);

 /********************************************************************************
	Funcion: imprime_palabra
	Descripcion: imprime un palabra
	Argumentos: 
				- Palabra* a
	Salida:
				- OK si todo ha salido bien
				- ERROR en otro caso



 *********************************************************************************/
int imprime_palabra(Palabra* a);


#endif //PALABRA
