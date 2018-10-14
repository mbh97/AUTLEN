#ifndef AFND
#define AFND

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alfabeto.h"
#include "estado.h"
#include "palabra.h"

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
 AFND* AFNDNuevo(char* nombre, int num_estados, int num_simbolos);

/********************************************************************************
	Funcion: AFNDElimina
	Descripcion: elimina y libera memoria reservada para un afnd y lo que hay dentro de este
	Argumentos:
				-AFND * p_afnd = afnd a eliminar
	Salida:
				- OK si todo ha ido bien
				- ERROR en otro caso



 *********************************************************************************/
 void AFNDElimina(AFND * p_afnd);

 /********************************************************************************
	Funcion: AFNDImprime
  Descripcion: imprime un afnd
	Argumentos:
				- FILE * fd = fichero donde lo imprime
        AFND* p_afnd = afnd a imprimir


 *********************************************************************************/
void AFNDImprime(FILE * fd, AFND* p_afnd);

 /********************************************************************************
	Funcion: AFNDInsertaSimbolo
	Descripcion: inserta un simbolo en un alfabeto
	Argumentos:
				- AFND * p_afnd
				-char* simbolo = simbolo a insertar
	Salida:
				- OK si todo ha ido bien
				- ERROR en otro caso



 *********************************************************************************/
int AFNDInsertaSimbolo(AFND * p_afnd, char* simbolo);

/********************************************************************************
	Funcion: AFNDInsertaEstado(AFND * p_afnd, char * nombre, int tipo)
	Descripcion: inserta un estado
	Argumentos:
				- Alfabeto* aAFND * p_afnd
        -char * nombre
        -int tipo
	Salida:
        - OK si todo ha salido bien
				- ERROR en otro caso



 *********************************************************************************/
AFND * AFNDInsertaEstado(AFND * p_afnd, char * nombre, int tipo);

/********************************************************************************
 Funcion: AFNDInsertaLetra(AFND * p_afnd, char * letra)
 Descripcion: inserta una letra
 Argumentos:
       - AFND * p_afnd
       -char * letra
 Salida:
       - AFND* si todo ha salido bien
       - NULL en otro caso



*********************************************************************************/
AFND * AFNDInsertaLetra(AFND * p_afnd, char * letra);

/********************************************************************************
 Funcion: AFNDImprimeConjuntoEstadosActual(FILE * fd, AFND * p_afnd)
 Descripcion: imprime el conjunto de estados actual
 Argumentos:
       - FILE * fd
       - AFND * p_afnd
*********************************************************************************/

void AFNDImprimeConjuntoEstadosActual(FILE * fd, AFND * p_afnd);

 /********************************************************************************
	Funcion: imprime_alfabeto
	Descripcion: imprime un alfabeto
	Argumentos:
				- FILE* file
				- Alfabeto* a
	Salida:
				- OK si todo ha salido bien
				- ERROR en otro caso



 *********************************************************************************/
int imprime_alfabeto(FILE* file, Alfabeto* a);


AFND * AFNDInsertaTransicion(AFND * p_afnd, char * nombre_estado_i, char * nombre_simbolo_entrada, char * nombre_estado_f);
AFND * AFNDInsertaActuales(AFND * p_afnd, char * nombre);
AFND * AFNDeliminaActuales(AFND * p_afnd);
void AFNDImprimeCadenaActual(FILE *fd, AFND * p_afnd);
AFND * AFNDInicializaEstado (AFND * p_afnd);
void AFNDProcesaEntrada(FILE * fd, AFND * p_afnd);
void AFNDTransita(AFND * p_afnd);


#endif //AFND
