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
	printf("Elimina transicion..\n");
	salida = eliminar_transicion(t);
	if(salida == -1){
		printf("ERROR");
		return -1;
	}
	return OK;
}
