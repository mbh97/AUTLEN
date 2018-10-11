#include "palabra.h"

int main(int argc, char const *argv[]){
	Palabra* a = NULL;
	char* s1 = "1", *s2="2";
	int salida;
	printf("Creando palabra..\n");
	a = crear_palabra();
	if(!a){
		printf("ERROR");
		return -1;
	}
	printf("Insertar simbolo..\n");
	salida = insertar_simbolo(s1, a);
	if(salida == -1){
		printf("ERROR");
		eliminar_palabra(a);
		return -1;
	}
	printf("Insertar simbolo..\n");
	salida = insertar_simbolo(s2, a);
	if(salida == -1){
		printf("ERROR");
		eliminar_palabra(a);
		return -1;
	}
	printf("Imprime palabra..\n");
	imprime_palabra(a);
	printf("Elimina simbolo..\n");
	salida = eliminar_simbolo(a);
	if(salida == -1){
		printf("ERROR");
		return -1;
	}
	printf("Imprime palabra..\n");
	imprime_palabra(a);
	printf("Elimina palabra..\n");
	salida = eliminar_palabra(a);
	if(salida == -1){
		printf("ERROR");
		return -1;
	}
	return OK;
}
