#ifndef ESTADO
#define ESTADO

#include <stdio.h>
#include <string.h>

//CONSTANTES
#define OK 0;
#define ERROR -1;

enum TIPO{
	INICIAL = 0,
	NORMAL = 1,
	FINAL = 2
};

typedef struct Estado {
	char * nombre; // nombre del estado
	enum TIPO tipo; // tipo de estado
} Estado;




#endif ESTADO
