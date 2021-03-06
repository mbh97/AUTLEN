/********************************************************************************

	AUTLEN - Practica 1
	Blanca Abella y Maria Barroso
	Pareja 3

*********************************************************************************/

#include "palabra.h"

struct Palabra {
	char ** simbolos; /* array de simbolos (letras) */
	int size; /* tamanno de la palabra */
};

/********************************************************************************
	Funcion: crear_palabra
	Descripcion: crea una palabra
	Argumentos: -
	Salida:
				- *Palabra si se ha podido crear correctamente
				- NULL si ha habido algun problema a la hora de crearlo



 *********************************************************************************/
 Palabra* crear_palabra(){
	Palabra* palabra = NULL;
	palabra = (Palabra *)malloc(sizeof(Palabra));
	if(!palabra)
		return NULL;
	palabra->simbolos = NULL; //A la espera de insertar simbolos
	palabra->size = 0;
	return palabra;
 }

 /********************************************************************************
	Funcion: eliminar_palabra
	Descripcion: elimina y libera memoria reservada para una palabra y lo que hay dentro de esta
	Argumentos:
				-Palabra* palabra = palabra a eliminar
	Salida:
				- OK si todo ha ido bien
				- ERROR en otro caso



 *********************************************************************************/
int eliminar_palabra(Palabra* palabra){
	int i = 0;
	if(!palabra)
		return ERROR;
	if(palabra->size > 0){
		for(i = 0; i < palabra->size; i++)
			if(palabra->simbolos[i])
				free(palabra->simbolos[i]);
	}
	free(palabra->simbolos);
	palabra->size = 0;
	free(palabra);
	return OK;

}

 /********************************************************************************
	Funcion: size_palabra
	Descripcion: consigue el tamanno de una palabra
	Argumentos:
				-Palabra* palabra:
	Salida:
				- tammano del palabra
				- ERROR en otro caso



 *********************************************************************************/
int size_palabra(Palabra* palabra){
	if(!palabra)
		return ERROR;
	return palabra->size;
}

 /********************************************************************************
	Funcion: get_primer
	Descripcion: devuelve el primer elemento de la palabra
	Argumentos:
				- Palabra* a
	Salida:
				- primer elemento de la cadena
				- NULL en otro caso



 *********************************************************************************/
char* get_primer(Palabra* palabra){
	if(!palabra)
		return NULL;
	return palabra->simbolos[0];
}

 /********************************************************************************
	Funcion: es_vacia
	Descripcion: comprueba que una palabra esta vacia
	Argumentos:
				- Palabra* a
	Salida:
				- 1 si es vacia
				- 0 en otro caso

 *********************************************************************************/
int es_vacia(Palabra* palabra){
	if(!palabra)
		return 0;
	if(palabra->size == 0)
		return 1;
	return 0;
}
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
int insertar_letra(char* simbolo, Palabra* palabra){
	char ** aux =  NULL;
	if(!simbolo || !palabra)
		return ERROR;
	palabra->size += 1;
	aux = (char **)realloc(palabra->simbolos, palabra->size*(sizeof(char *)));
	if (!aux) {
		palabra->size -= 1;
		return ERROR;
	}
	palabra->simbolos=aux;
	palabra->simbolos[palabra->size-1] = (char*)malloc(TAM*sizeof(char));
	strcpy(palabra->simbolos[palabra->size-1], simbolo);
	return OK;
}

 /********************************************************************************
	Funcion: eliminar_letra
	Descripcion: elimina un simbolo en un palabra
	Argumentos:
				-char* simbolo = simbolo a eliminar
				- Palabra* palabra = palabra
	Salida:
				- OK si todo ha ido bien
				- ERROR en otro caso



 *********************************************************************************/
int eliminar_letra(Palabra* palabra){
	int i = 0;
	if(!palabra)
		return ERROR;
	if(palabra->size == 1){
		free(palabra->simbolos[0]);
		palabra->size = 0;
		return OK;
	}
	for(i = 1; i< palabra->size; i++){
		strcpy(palabra->simbolos[i-1], palabra->simbolos[i]);
	}
	free(palabra->simbolos[i-1]);
	palabra->size -=1;
	return OK;
}
 /********************************************************************************
	Funcion: imprime_palabra
	Descripcion: imprime un palabra
	Argumentos:
				- FILE *fd
				- Palabra* a
	Salida:
				- OK si todo ha salido bien
				- ERROR en otro caso



 *********************************************************************************/
int imprime_palabra(FILE *fd,Palabra* a){
	int i = 0;
	if(!a)
		return ERROR;
	fprintf(fd,"[(%d)",a->size);
	while(i<a->size){
		fprintf(fd, " %s",a->simbolos[i]);
		i+=1;
	}
	fprintf(fd,"]\n");
	return OK;
}
