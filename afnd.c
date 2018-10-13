
#include "afnd.h"
#include "transicion.h"
#include "estado.h"


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
	if(num_estados < 1 || num_simbolos < 1 || !nombre)
		return NULL;

	afnd=(AFND *)malloc(sizeof(AFND));
	if(!afnd)
		return NULL;
	afnd->alf = crear_alfabeto(num_simbolos);
	if(!afnd->alf){
		free(afnd);
		return NULL;
	}

	afnd->est = (Estado **)malloc(num_estados*sizeof(Estado*))
	if(!afnd->est){
		eliminar_alfabeto(afnd->alf);
		free(afnd);
		return NULL;
	}

	afnd->nombre = (char*)malloc(TAM*sizeof(char));
	if(!afnd->nombre){
		free(afnd->est);
		eliminar_alfabeto(afnd->alf);
		free(afnd);
		return NULL;
	}
	afnd->palabra = crear_palabra();
	if(!afnd->palabra){
		free(afnd->nombre)
		free(afnd->est);
		eliminar_alfabeto(afnd->alf);
		free(afnd);
		return NULL;
	}
	afnd->talf = num_simbolos;
	afnd->nest = num_estados;
	strcpy(afnd->nombre, nombre);
	afnd->actuales = NULL;
	afnd->nact = 0;

	return afnd;
	}

 /********************************************************************************
	Funcion: AFNDElimina
	Descripcion: elimina y libera memoria reservada para un afnd y lo que hay dentro de este
	Argumentos:
				-AFND * p_afnd = afnd a eliminar
	Salida:
				- OK si todo ha ido bien
				- ERROR en otro caso



 *********************************************************************************/
 void AFNDElimina(AFND * p_afnd){
	int i = 0;
	if(!p_afnd)
		return ERROR;
	for(i = 0; i < p_afnd->nest; i++)
		if(!eliminar_estado(p_afnd->est[i])){
      return ERROR;
    }
    free(p_afnd->est);
    for(i = 0; i < p_afnd->nact; i++)
		free(p_afnd->actuales[i])
	free(p_afnd->actuales);
	if(!eliminar_alfabeto(p_afnd->alf))
		return ERROR;
	free(p_afnd->nombre);
	eliminar_palabra(p_afnd->palabra);
	free(p_afnd);
	return OK;
}

 /********************************************************************************
	Funcion: AFNDImprime
  Descripcion: imprime un afnd
	Argumentos:
				- FILE * fd = fichero donde lo imprime
        AFND* p_afnd = afnd a imprimir


 *********************************************************************************/
void AFNDImprime(FILE * fd, AFND* p_afnd){
  int i =0;
	if(!p_afnd || !fd){
    		return ERROR;
  }
  fprintf(fd, "%s={\n", p_afnd->nombre);
  imprime_alfabeto(fd, p_afnd->alf);
  fprintf(fd, "num_estados = %d\n", p_afnd->nest);

  fprintf(fd, "Q={ ");
  while(i<p_afnd->nest){
    if(get_tipo(p_afnd->est[i]) == INICIAL){
      fprintf(fd, "->%s ",a->simbolos[i]);
    }else if (get_tipo(p_afnd->est[i]) == FINAL) {
      fprintf(fd, "%s* ",a->simbolos[i]);
    }else{
      fprintf(fd, "%s ",a->simbolos[i]);
    }
    i+=1;
  }
  fprintf(fd, "}\n");
  fprintf(fd,  "Funcion de Transición = {\n");
  //cosassss de TRANSICIONES
  fprintf(fd, "}\n");
  fprintf(fd, "}\n");
}

 /********************************************************************************
	Funcion: insertar_simbolo
	Descripcion: inserta un simbolo en un alfabeto
	Argumentos:
				-char* simbolo = simbolo a insertar
				- AFND * p_afnd = afnd en cuyo alfabeto insertamos simbolo
	Salida:
				- OK si todo ha ido bien
				- ERROR en otro caso



 *********************************************************************************/
AFND * AFNDInsertaSimbolo(AFND * p_afnd, char * simbolo){
	int i = 0;
	if(!p_afnd || !simbolo)
		return NULL;
	if(insertar_simbolo(simbolo, p_afnd->alf)
    	return p_afnd;
  	return NULL;
}

/********************************************************************************
	Funcion: AFNDInsertaEstado(AFND * p_afnd, char * nombre, int tipo)
	Descripcion: inserta un estado
	Argumentos:
				- Alfabeto* aAFND * p_afnd
        -char * nombre
        -int tipo
	Salida:
        - OK si todo ha salido bien
				- ERROR en otro caso



 *********************************************************************************/
AFND * AFNDInsertaEstado(AFND * p_afnd, char * nombre, int tipo){
  int i = 0;
	if(!p_afnd || !nombre)
		return ERROR;
	if(!p_afnd->est[i]){
		p_afnd->est[i]= crear_estado(nombre, tipo);
		return OK;
	}
	while(p_afnd->est[i]){
		i+=1;
		if(i==p_afnd->nest)
			return ERROR; //  completo
	}
	p_afnd->est[i]= crear_estado(nombre, tipo);
	return OK;
}
/********************************************************************************
 Funcion: AFNDInsertaLetra(AFND * p_afnd, char * letra)
 Descripcion: inserta una letra
 Argumentos:
       - AFND * p_afnd
       -char * letra
 Salida:
       - AFND* si todo ha salido bien
       - NULL en otro caso



*********************************************************************************/



AFND * AFNDInsertaLetra(AFND * p_afnd, char * letra){
  	int i = 0;
	if(!p_afnd || !letra)
		return NULL;
	if(insertar_letra(letra, p_afnd->palabra))
		return p_afnd;
	return NULL;
}

/********************************************************************************
 Funcion: AFNDImprimeConjuntoEstadosActual(FILE * fd, AFND * p_afnd)
 Descripcion: imprime el conjunto de estados actual
 Argumentos:
       - FILE * fd
       - AFND * p_afnd
*********************************************************************************/

void AFNDImprimeConjuntoEstadosActual(FILE * fd, AFND * p_afnd){


}

Estado* buscar_estado(AFND * p_afnd, char* nombre){
	int i = 0;
	if(!nombre||!p_afnd)
		return NULL;
	for(i = 0; i<p_afnd->nest; i++){
		if(!strcmp(getname(p_afnd->est[i]), nombre))
			return p_afnd->est[i]
	}
	return NULL;
}

AFND * AFNDInsertaTransicion(AFND * p_afnd, char * nombre_estado_i, char * nombre_simbolo_entrada, char * nombre_estado_f ){
	Estado* estado_i  = NULL;
	Transicion* tran = NULL;
	if(!p_afnd||!nombre_estado_i ||!nombre_simbolo_entrada||!nombre_estado_f)
		return NULL;
	estado_i = buscar_estado(p_afnd, nombre_estado_i);
	if(!estado_i)
		return NULL;
	tran = crear_transicion(nombre_simbolo_entrada, nombre_estado_f);
	if(!inserta_transicion(estado_i, tran))
		return NULL;
	return p_afnd;
}

 /********************************************************************************
	Funcion: AFNDInsertaEstado(AFND * p_afnd, char * nombre, int tipo)
	Descripcion: inserta un estado
	Argumentos:
				- Alfabeto* aAFND * p_afnd
        -char * nombre
        -int tipo
	Salida:
        - OK si todo ha salido bien
				- ERROR en otro caso



 *********************************************************************************/
AFND * AFNDInsertaActuales(AFND * p_afnd, char * nombre){
	int i = 0;
	char ** aux;
	if(!p_afnd || !nombre)
		return ERROR;
	estado->nact += 1;
	aux = (char **)realloc(estado->actuales, estado->nact*(sizeof(char *)));
	if (!aux) {
		estado->nact -= 1;
		return ERROR;
	}
	estado->actuales=aux;
	estado->actuales[estado->nact-1] = (char*)malloc(TAM*sizeof(char));
	strcpy(estado->actuales[estado->nact-1], nombre);
	return OK;
}

AFND * AFNDeliminaActuales(AFND * p_afnd){
	int i = 0;
	if(!p_afnd)
		return NULL;
	for(i=0; i<p_afnd->nact;i++)
		free(p_afnd->actuales[i]);
	free(p_afnd->actuales);
}


Estado* copiar_estado(Estado * estado){
	Estado* copia = NULL;
	int i = 0;
	if(!estado)
		return NULL;
	copia = crear_estado(getname(estado),get_tipo(estado));
	if(!copia)
		return NULL;
	for(i=0; i<get_ntran(estado); i++)
		inserta_transicion(copia, copia_transicion(get_transiciones(estado)[i]));
	return copia;
}