#include "alfabeto.h"

int main(int argc, char const *argv[]){
	Alfabeto* a = NULL;
	char* s1 = "1", *s2="2";
	int salida;
	printf("Creando alfabeto..\n");
	a = crear_alfabeto(2);
	if(!a){
		printf("ERROR");
		return -1;
	}
	printf("Insertar simbolo..\n");
	salida = insertar_simbolo(s1, a);
	if(salida == -1){
		printf("ERROR");
		eliminar_alfabeto(a);
		return -1;
	}
	printf("Insertar simbolo..\n");
	salida = insertar_simbolo(s2, a);
	if(salida == -1){
		printf("ERROR");
		eliminar_alfabeto(a);
		return -1;
	}
	printf("Elimina alfabeto..\n");
	salida = eliminar_alfabeto(a);
	if(salida == -1){
		printf("ERROR");
		return -1;
	}
	return OK;
}
