#ifndef ESTADO
#define ESTADO

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//CONSTANTES
#define OK 0
#define ERROR -1
#define TAM 256

enum TIPO{
	INICIAL = 0,
	NORMAL = 1,
	FINAL = 2,
	INICIAL_Y_FINAL = 3
};

typedef struct Estado {
	char * nombre; // nombre del estado
	enum TIPO tipo; // tipo de estado
} Estado;

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
	Funcion: set_tipo
	Descripcion: modifica el tipo de un estado
	Argumentos: 
				- Estado* estado
				- enum TIPO newTipo
	Salida:
				- OK si todo ha salido bien
				- ERROR en otro caso



 *********************************************************************************/
int set_tipo(Estado* estado, enum TIPO newTipo);


 /********************************************************************************
	Funcion: imprime_estado
	Descripcion: imprime un estado
	Argumentos: 
				- Estado* estado
	Salida:
				- OK si todo ha salido bien
				- ERROR en otro caso



 *********************************************************************************/
int imprime_estado(Estado* estado);





#endif //ESTADO
