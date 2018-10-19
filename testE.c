#include "estado.h"
#include "transicion.h"
int main(int argc, char const *argv[]){
	Estado* estado;
	int salida;
	
	printf("Creando estado..\n");
	estado = crear_estado("q0", 0);
	if(!estado){
		printf("ERROR");
		return -1;
	}

	printf("Imprime estado..\n");
	imprime_estado(estado);

	printf("Creando transicion..\n");
	salida = inserta_transicion(estado, "0", "q0");
	if(salida == -1){
		printf("ERROR");
		eliminar_estado(estado);
		return -1;
	}

	printf("Imprime estado..\n");
	imprime_estado(estado);

	printf("Creando transicion..\n");
	salida = inserta_transicion(estado, "0", "q1");
	if(salida == -1){
		printf("ERROR");
		eliminar_estado(estado);
		return -1;
	}
	printf("Creando transicion..\n");
	salida = inserta_transicion(estado, "1", "q2");
	if(salida == -1){
		printf("ERROR");
		eliminar_estado(estado);
		return -1;
	}

	printf("Imprime estado..\n");
	imprime_estado(estado);

	printf("Eliminando estado...\n");
	eliminar_estado(estado);

}	
