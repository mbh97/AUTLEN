#ifndef ALFABETO
#define ALFABETO

#include <stdio.h>
#include <string.h>

//CONSTANTES
#define OK 0;
#define ERROR -1;
#define TAM 256;


typedef struct Alfabeto {
	char ** simbolos; // array de simbolos
	int size; // tamanno del alfabeto
} Alfabeto;


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
	Funcion: get_size
	Descripcion: consigue el tamanno de un alfabeto
	Argumentos: 
				-Alfabeto* alfabeto: 
	Salida:
				- tammano del alfabeto
				- ERROR en otro caso



 *********************************************************************************/
int get_size(Alfabeto* alfabeto);

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
int insertar_simbolo(char* simbolo);

 /********************************************************************************
	Funcion: imprime_alfabeto
	Descripcion: imprime un alfabeto
	Argumentos: 
				- Alfabeto* a
	Salida:
				- OK si todo ha salido bien
				- ERROR en otro caso



 *********************************************************************************/
int imprime_alfabeto(Alfabeto* a);




#endif //ALFABETO

