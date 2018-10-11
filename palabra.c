
#include "palabra.h"


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
		free(palabra->simbolos);
	}
	free(palabra);
	return OK;
		
}

 /********************************************************************************
	Funcion: get_size
	Descripcion: consigue el tamanno de una palabra
	Argumentos: 
				-Palabra* palabra: 
	Salida:
				- tammano del palabra
				- ERROR en otro caso



 *********************************************************************************/
int get_size(Palabra* palabra){
	if(!palabra)
		return ERROR;
	return palabra->size;
}

 /********************************************************************************
	Funcion: insertar_simbolo
	Descripcion: inserta un simbolo en un palabra
	Argumentos: 
				-char* simbolo = simbolo a insertar
				- Palabra* palabra = palabra
	Salida:
				- OK si todo ha ido bien
				- ERROR en otro caso



 *********************************************************************************/
int insertar_simbolo(char* simbolo, Palabra* palabra){
	char ** aux =  NULL;
	if(!simbolo || !palabra)
		return ERROR;
	palabra->size += 1;
	aux = (char **)realloc(palabra->simbolos, palabra->size*(sizeof(char *)));
	if (!aux) {
		palabra->size -= 1;
		printf("1\n");
		return ERROR;
	}
	palabra->simbolos=aux;
	palabra->simbolos[palabra->size-1] = (char*)malloc(TAM*sizeof(char));
	if(!palabra->simbolos[palabra->size-1]){
		printf("2\n");
		palabra->size -= 1;
		aux = (char **)realloc(palabra->simbolos, palabra->size); //revisar!!!!
		return ERROR;
	}
	palabra->simbolos[palabra->size-1] = simbolo;
	return OK;
}

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
int eliminar_simbolo(Palabra* palabra){
	int i = 0;
	if(!palabra)
		return ERROR;
	if(palabra->size == 1)
		return eliminar_palabra(palabra);
	for(i = 1; i< palabra->size; i++){
		palabra->simbolos[i-1] = palabra->simbolos[i];
	}
	free(palabra->simbolos[i-1]);
	palabra->size -=1;
	return OK;
}
 /********************************************************************************
	Funcion: imprime_palabra
	Descripcion: imprime un palabra
	Argumentos: 
				- Palabra* a
	Salida:
				- OK si todo ha salido bien
				- ERROR en otro caso



 *********************************************************************************/
int imprime_palabra(Palabra* a){
	int i = 0;
	if(!a)
		return ERROR;

	printf("num_simbolos = %d\n", a->size);
	
	printf("P=[ ");
	while(i<a->size){
		printf("%s ",a->simbolos[i]);
		i+=1;
	}
	printf("]\n");
	return OK;
}
