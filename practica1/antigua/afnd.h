#ifndef _AFND_
#define _AFND_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alfabeto.h"
#include "estado.h"
#include "palabra.h"

#define OK 0
#define ERROR -1
#define TAM 256

typedef struct _AFND AFND;


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
AFND * AFNDInsertaSimbolo(AFND * p_afnd, char* simbolo);

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
 Funcion: AFNDInsertaTransicion
 Descripcion: inserta una transicion en el automata
 Argumentos:
       - AFND * p_afnd
       - char * nombre_estado_i
       - char * nombre_simbolo_entrada
       - char * nombre_estado_f

 Salida:
       - AFND* si todo ha salido bien
       - NULL en otro caso



*********************************************************************************/
AFND * AFNDInsertaTransicion(AFND * p_afnd, char * nombre_estado_i, char * nombre_simbolo_entrada, char * nombre_estado_f);

 /********************************************************************************
	Funcion: AFNDInsertaEstado(AFND * p_afnd, char * nombre, int tipo)
	Descripcion: inserta un estado
	Argumentos:
				- AFND * p_afnd
		        -char * nombre
		        -int tipo
	Salida:
       			- AFND * p_afnd
				- NULL otro caso



 *********************************************************************************/
AFND * AFNDInsertaActuales(AFND * p_afnd, char * nombre);

 /********************************************************************************
	Funcion: AFNDeliminaActuales
	Descripcion: elimina un estado actual
	Argumentos:
				- AFND * p_afnd
		        
	Salida:
       			- AFND * p_afnd
				- NULL otro caso



 *********************************************************************************/
AFND * AFNDeliminaActuales(AFND * p_afnd);

 /********************************************************************************
	Funcion: AFNDInicializaEstado
	Descripcion: inicializa el estado actual del autonoma a aquellos que sea de tipo INICIAL o 
				INICIAL_Y_FINAL
	Argumentos:
				- AFND * p_afnd
		        
	Salida:
       			- AFND * p_afnd
				- NULL otro caso



 *********************************************************************************/
AFND * AFNDInicializaEstado (AFND * p_afnd);

 /********************************************************************************
	Funcion: AFNDImprimeCadenaActual
	Descripcion: imprime cadena actual a procesar
	Argumentos:
				- FILE *fd
				- AFND * p_afnd




 *********************************************************************************/
void AFNDImprimeCadenaActual(FILE *fd, AFND * p_afnd);

 /********************************************************************************
	Funcion: AFNDProcesaEntrada
	Descripcion: funcion recursiva que procesa una palabra
	Argumentos:
				- FILE *fd
				- AFND * p_afnd




 *********************************************************************************/
void AFNDProcesaEntrada(FILE * fd, AFND * p_afnd);

 /********************************************************************************
	Funcion: AFNDTransita
	Descripcion: elimina una letra de la palabra porque ya se ha procesado
	Argumentos:
				- AFND * p_afnd




 *********************************************************************************/
void AFNDTransita(AFND * p_afnd);


/********************************************************************************
	Funcion: imprime_estados
  	Descripcion: funcion auxiliar para imprimir los estados de un afnd
	Argumentos:
				- FILE * fd = fichero donde lo imprime
        		  AFND* p_afnd = afnd a imprimir


 *********************************************************************************/
void imprime_estados(FILE * fd, AFND* p_afnd);

/********************************************************************************
 Funcion: buscar_estado
 Descripcion: busca un estado a partir de un nombre
 Argumentos:
       - AFND * p_afnd
       - char* nombre
 Salida:
       - Estado encontrado
       - NULL en otro caso



*********************************************************************************/
Estado* buscar_estado(AFND * p_afnd, char* nombre);

/********************************************************************************
	Funcion: es_repeticion
  	Descripcion: funcion auxiliar para comprobar si un simbolo ya pertenece
  				al conjunto de simbolos que se convertiran en actuales
  				para ser procesados por el automata
	Argumentos:
				- char* siguiente
        		- char**aux
        		- int naux
	Salida:
				- 1 si es repeticion
				- 0 en caso contrario

 *********************************************************************************/
int es_repeticion(char* siguiente, char**aux, int naux);

#endif
