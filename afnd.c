
#include "afnd.h"

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
 AFND * AFNDNuevo(char* nombre, int num_estados, int num_simbolos){
	AFND* afnd = NULL;
	int i = 0;
  if(!nombre)
    return NULL;
	if(num_estados < 1 && num_simbolos < 1)
		return NULL;

	a=(Alfabeto *)malloc(sizeof(Alfabeto));
	if(!a)
		return NULL;
	a->simbolos = (char **)malloc(size*sizeof(char *));
	if(!a->simbolos){
		free(a);
		return NULL;
	}
	for(i = 0; i < size; i++)
		a->simbolos[i] = (char *)malloc(TAM*sizeof(char));
	a->size = size;
	return a;
 }

 /********************************************************************************
	Funcion: eliminar_alfabeto
	Descripcion: elimina y libera memoria reservada para un alfabeto y lo que hay dentro de este
	Argumentos:
				-Alfabeto* alfabeto = alfabeto a eliminar
	Salida:
				- OK si todo ha ido bien
				- ERROR en otro caso



 *********************************************************************************/
int eliminar_alfabeto(Alfabeto* alfabeto){
	int i = 0;
	if(!alfabeto)
		return ERROR;
	for(i = 0; i < alfabeto->size; i++)
		free(alfabeto->simbolos[i]);

	free(alfabeto);
	return OK;
}

 /********************************************************************************
	Funcion: get_size
	Descripcion: consigue el tamanno de un alfabeto
	Argumentos:
				-Alfabeto* alfabeto:
	Salida:
				- tammano del alfabeto
				- ERROR en otro caso



 *********************************************************************************/
int get_size(Alfabeto* alfabeto){
	if(!alfabeto)
		return ERROR;
	return alfabeto->size;
}

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
int insertar_simbolo(char* simbolo, Alfabeto* a){
	int i = 0;
	if(!a || !simbolo)
		return ERROR;
	while(a->simbolos[i]){
		i+=1;
		if(i==a->size)
			return ERROR; // alfabeto completo
	}
	a->simbolos[i]= simbolo;
	return OK;
}

 /********************************************************************************
	Funcion: imprime_alfabeto
	Descripcion: imprime un alfabeto
	Argumentos:
				- Alfabeto* a
	Salida:
				- OK si todo ha salido bien
				- ERROR en otro caso



 *********************************************************************************/
int imprime_alfabeto(Alfabeto* a, char* n){
	int i = 0;
	if(!a)
		return ERROR;

	printf("num_simbolos = %d\n", a->size);

	printf("%s={ ", n);
	while(a->simbolos[i])
		printf("%s ",a->simbolos[i]);
	printf("}\n");
}
