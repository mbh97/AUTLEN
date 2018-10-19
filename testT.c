#include "transicion.h"

int main(int argc, char const *argv[]){
	Transicion* t = NULL;
	char* valor = "1", *estado="q0";
	int salida;
	printf("Creando transicion..\n");
	t = crear_transicion(valor, estado);
	if(!t){
		printf("ERROR");
		return -1;
	}
	insertar_estadoFinal(t, "q1");
	printf("inserta estado final..\n");

	imprimir_transicion(t);
	printf("Elimina transicion..\n");
	salida = eliminar_transicion(t);
	if(salida == -1){
		printf("ERROR");
		return -1;
	}
	return OK;
}
