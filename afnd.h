#ifndef AFND
#define AFND

#include <stdio.h>
#include <string.h>
#include "alfabeto.h"
#include "estado.h"

//CONSTANTES
#define OK 0
#define ERROR -1
#define TAM 256


typedef struct AFND {
	char* nombre;
	Alfabeto* alf;
	int talf; //numero de simbolos
	int nest; //numero estados
	Estado** est;
	Palabra* palabra;
	char** actuales;
	int nact;
} AFND;


/********************************************************************************
	Funcion: AFNDNuevo
	Descripcion: INICIALIZACIÓN DE UN NUEVO AFND DE NOMBRE af1 Y CON 3 ESTADOS Y 2 SÍMBOLOS EN SU ALFABETO
	Argumentos:
        -char* nombre = nombre del afnd
				-int num_estados =  numero de estados
        -int num_simbolos =  numro de simbolos en el alfabeto
	Salida:
				- *AFND si se ha podido crear correctamente
				- NULL si ha habido algun problema a la hora de crearlo



 *********************************************************************************/
 AFND * AFNDNuevo(char* nombre, int num_estados, int num_simbolos);

/********************************************************************************
	Funcion: AFNDElimina
	Descripcion: elimina y libera memoria reservada para un afnd y lo que hay dentro de este
	Argumentos:
				-AFND * p_afnd = afnd a eliminar
	Salida:
				- OK si todo ha ido bien
				- ERROR en otro caso



 *********************************************************************************/
 void AFNDElimina(AFND * p_afnd);{

 /********************************************************************************
	Funcion: AFNDImprime
  Descripcion: imprime un afnd
	Argumentos:
				- FILE * fd = fichero donde lo imprime
        AFND* p_afnd = afnd a imprimir


 *********************************************************************************/
void AFNDImprime(FILE * fd, AFND* p_afnd);

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




#endif //AFND
