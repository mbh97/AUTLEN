#include "estado.h"
#include "transicion.h"
int main(int argc, char const *argv[]){
	Estado* estado;
	Transicion* t1, *t2;
	int salida;
	char* trans;
	printf("Creando estado..\n");
	estado = crear_estado("q0", 0);
	if(!estado){
		printf("ERROR");
		return -1;
	}

	printf("Imprime estado..\n");
	imprime_estado(estado);

	printf("Creando transicion..\n");
	t1 = crear_transicion("1", "q1");
	if(!t1){
		printf("ERROR");
		eliminar_estado(estado);
		return -1;
	}
	salida = inserta_transicion(estado, t1);
	if(salida == -1){
		printf("ERROR");
		eliminar_estado(estado);
		return -1;
	}
	printf("Creando transicion..\n");
	t2 = crear_transicion("0", "q0");
	if(!t2){
		printf("ERROR");
		eliminar_estado(estado);
		return -1;
	}
	salida = inserta_transicion(estado, t2);
	if(salida == -1){
		printf("ERROR");
		eliminar_estado(estado);
		return -1;
	}
	trans = funcion_transicion(estado, "0");
	if(!trans)
		printf("No hay transicion para 0\n");
	else{
		printf("Transicion a %s\n", trans);
	}
	trans = funcion_transicion(estado, "1");
	if(!trans)
		printf("No hay transicion para 1\n");
	else{
		printf("Transicion a %s\n", trans);
	}
	trans = funcion_transicion(estado, "2");
	if(!trans)
		printf("No hay transicion para 2\n");
	else{
		printf("Transicion ERROR!\n");
	}
	printf("Eliminando estado...\n");
	eliminar_estado(estado);

}	
