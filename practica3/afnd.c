/********************************************************************************

	AUTLEN - Practica 1
	Blanca Abella y Maria Barroso
	Pareja 3

*********************************************************************************/
#include "afnd.h"

struct _AFND {
	char* nombre; /* nombre de nuestro automata */

	Alfabeto* alf; /* alfabeto de nuestro automata*/
	int talf; /* numero de simbolos */

	Estado** est; /* estados de nuestro automata */
	int nest; /* numero estados */

	Palabra* palabra; /* palabra a procesar de nuestro automata */

	char** actuales; /* estados actuales a procesar por nuestro automata */
	int nact; /* numero de estados actuales a procesar por nuestro automata */

	Lambda* lambda; /* matriz de transiciones lambda*/
};
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

	afnd->est = (Estado **)malloc(num_estados*sizeof(Estado*));
	if(!afnd->est){
		eliminar_alfabeto(afnd->alf);
		free(afnd);
		return NULL;
	}
	for(i = 0; i<num_estados; i++)
		afnd->est[i] = NULL;

	afnd->nombre = (char*)malloc(TAM*sizeof(char));
	if(!afnd->nombre){
		free(afnd->est);
		eliminar_alfabeto(afnd->alf);
		free(afnd);
		return NULL;
	}
	strcpy(afnd->nombre, nombre);

	afnd->palabra = crear_palabra();
	if(!afnd->palabra){
		free(afnd->nombre);
		free(afnd->est);
		eliminar_alfabeto(afnd->alf);
		free(afnd);
		return NULL;
	}

	afnd->talf = num_simbolos;
	afnd->nest = num_estados;

	afnd->actuales = NULL;
	afnd->nact = 0;

	/* Matriz transiciones lambda */
	afnd->lambda = inicializa_lambda(num_estados);
	if(!afnd->lambda){
		free(afnd->nombre);
		free(afnd->est);
		eliminar_alfabeto(afnd->alf);
		eliminar_palabra(afnd->palabra);
		free(afnd);
		return NULL;
	}
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
		return;

	for(i = 0; i < p_afnd->nest; i++)
		eliminar_estado(p_afnd->est[i]);
    free(p_afnd->est);

    for(i = 0; i < p_afnd->nact; i++)
		free(p_afnd->actuales[i]);
	free(p_afnd->actuales);

	eliminar_alfabeto(p_afnd->alf);
	eliminar_palabra(p_afnd->palabra);
	free(p_afnd->nombre);
	elimina_lambda(p_afnd->lambda);
	free(p_afnd);
	return;
}

 /********************************************************************************
	Funcion: AFNDImprime
  	Descripcion: imprime un afnd
	Argumentos:
				- FILE * fd = fichero donde lo imprime
        		  AFND* p_afnd = afnd a imprimir


 *********************************************************************************/
void AFNDImprime(FILE * fd, AFND* p_afnd){
	int i =0, k=0, j= 0, nfinales;
	char * valor, *inicial, **finales;

	if(!p_afnd || !fd){
		return;
	}

	fprintf(fd, "%s={\n", p_afnd->nombre);
	imprime_alfabeto(fd, p_afnd->alf);
	imprime_estados(fd, p_afnd);
	imprime_lambda(fd, p_afnd->lambda);

	fprintf(fd,  "\tFuncion de Transición = {\n");
	for(i=0; i<p_afnd->nest; i++){
		inicial = get_nombre(p_afnd->est[i]);
		for(k = 0; k<p_afnd->talf; k++){
			valor = get_simbolo_pos(k, p_afnd->alf);
			finales = funcion_transicion(p_afnd->est[i], valor);
			if(!finales)
				fprintf(fd, "\t\tf(%s,%s)={ }\n",inicial,valor);
			else{
				nfinales = get_nfinales_transicion(p_afnd->est[i],valor);
				fprintf(fd, "\t\tf(%s,%s)={",inicial,valor);
				for(j = 0;j<nfinales;j++)
					fprintf(fd, " %s", finales[j]);
				fprintf(fd, " }\n");
			}
		}
	}
	fprintf(fd, "\t}\n");
	fprintf(fd, "}\n");
}

 /********************************************************************************
	Funcion: imprime_estados
  	Descripcion: funcion auxiliar para imprimir los estados de un afnd
	Argumentos:
				- FILE * fd = fichero donde lo imprime
        		  AFND* p_afnd = afnd a imprimir


 *********************************************************************************/
void imprime_estados(FILE * fd, AFND* p_afnd){
	int i = 0;
	fprintf(fd, "\tnum_estados = %d\n", p_afnd->nest);

	fprintf(fd, "\tQ={ ");
	while(i<p_afnd->nest){
		if(get_tipo(p_afnd->est[i]) == INICIAL){
			fprintf(fd, "->%s ",get_nombre(p_afnd->est[i]));
		}else if (get_tipo(p_afnd->est[i]) == FINAL) {
			fprintf(fd, "%s* ",get_nombre(p_afnd->est[i]));
		}else if (get_tipo(p_afnd->est[i]) == INICIAL_Y_FINAL){
			fprintf(fd, "->%s* ",get_nombre(p_afnd->est[i]));
		}else{
			fprintf(fd, "%s ",get_nombre(p_afnd->est[i]));
		}
		i+=1;
	}
	printf("}\n");
}

 /********************************************************************************
	Funcion: AFNDInsertaSimbolo
	Descripcion: inserta un simbolo en un alfabeto
	Argumentos:
				-char* simbolo = simbolo a insertar
				- AFND * p_afnd = afnd en cuyo alfabeto insertamos simbolo
	Salida:
				- OK si todo ha ido bien
				- ERROR en otro caso



 *********************************************************************************/
AFND * AFNDInsertaSimbolo(AFND * p_afnd, char * simbolo){
	if(!p_afnd || !simbolo)
		return NULL;
	if(insertar_simbolo(simbolo, p_afnd->alf) == OK)
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
	if(!p_afnd || !nombre){
		return NULL;
	}
	if(!p_afnd->est[i]){
		p_afnd->est[i]= crear_estado(nombre, tipo);
		return p_afnd;
	}
	while(p_afnd->est[i]){
		i+=1;
		if(i==p_afnd->nest){
			return NULL; /* si llega aqui ==> alfabeto completo */
		}
	}
	p_afnd->est[i]= crear_estado(nombre, tipo);
	return p_afnd;
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
	if(!p_afnd || !letra){
		return NULL;
	}
	if(!letraValida(letra, p_afnd)){
		printf("La letra %s no pertenece al alfabeto. No ha sido insertada.\n");
		return p_afnd;
	}
	if(insertar_letra(letra, p_afnd->palabra) == OK){
		return p_afnd;
	}
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
	int i = 0;
	Estado * estado;
	if(!fd || !p_afnd)
		return;
	fprintf(fd, "ACTUALMENTE EN {");
	for(i=0; i<p_afnd->nact; i++){
		estado = buscar_estado(p_afnd, p_afnd->actuales[i]);
		if(get_tipo(estado) == INICIAL)
			fprintf(fd, "->%s ", p_afnd->actuales[i]);
		if(get_tipo(estado) == FINAL)
			fprintf(fd, "%s* ", p_afnd->actuales[i]);
		if(get_tipo(estado) == INICIAL_Y_FINAL)
			fprintf(fd, "->%s* ", p_afnd->actuales[i]);
		if(get_tipo(estado) == NORMAL)
			fprintf(fd, "%s ", p_afnd->actuales[i]);
	}
	fprintf(fd, "}\n");
	return;
}

/********************************************************************************
 Funcion: AFNDInsertaTransicion
 Descripcion: inserta una transicion en el automata
 Argumentos:
       - AFND * p_afnd
       - char * nombre_estado_i
       - char * nombre_simbolo_entrada
       - char * nombre_estado_f

 Salida:
       - AFND* si todo ha salido bien
       - NULL en otro caso



*********************************************************************************/
AFND * AFNDInsertaTransicion(AFND * p_afnd, char * nombre_estado_i, char * nombre_simbolo_entrada, char * nombre_estado_f ){
	Estado* estado_i  = NULL;
	if(!p_afnd||!nombre_estado_i ||!nombre_simbolo_entrada||!nombre_estado_f)
		return NULL;
	estado_i = buscar_estado(p_afnd, nombre_estado_i);
	if(!estado_i)
		return NULL;
	if(inserta_transicion(estado_i,nombre_simbolo_entrada, nombre_estado_f) == OK){
		return NULL;
	}
	return p_afnd;
}

 /********************************************************************************
	Funcion: AFNDInsertaEstado(AFND * p_afnd, char * nombre, int tipo)
	Descripcion: inserta un estado
	Argumentos:
				- AFND * p_afnd
		        -char * nombre
		        -int tipo
	Salida:
       			- AFND * p_afnd
				- NULL otro caso



 *********************************************************************************/
AFND * AFNDInsertaActuales(AFND * p_afnd, char * nombre){
	char ** aux;
	if(!p_afnd || !nombre)
		return NULL;
	p_afnd->nact += 1;
	aux = (char **)realloc(p_afnd->actuales, p_afnd->nact*(sizeof(char *)));
	if (!aux) {
		p_afnd->nact -= 1;
		return NULL;
	}
	p_afnd->actuales=aux;
	p_afnd->actuales[p_afnd->nact-1] = (char*)malloc(TAM*sizeof(char));
	strcpy(p_afnd->actuales[p_afnd->nact-1], nombre);
	return p_afnd;
}

 /********************************************************************************
	Funcion: AFNDeliminaActuales
	Descripcion: elimina un estado actual
	Argumentos:
				- AFND * p_afnd

	Salida:
       			- AFND * p_afnd
				- NULL otro caso



 *********************************************************************************/
AFND * AFNDeliminaActuales(AFND * p_afnd){
	int i = 0;
	if(!p_afnd)
		return NULL;
	for(i=0; i<p_afnd->nact;i++)
		free(p_afnd->actuales[i]);
	p_afnd->nact = 0;
	return p_afnd;
}

 /********************************************************************************
	Funcion: AFNDImprimeCadenaActual
	Descripcion: imprime cadena actual a procesar
	Argumentos:
				- FILE *fd
				- AFND * p_afnd




 *********************************************************************************/
void AFNDImprimeCadenaActual(FILE *fd, AFND * p_afnd){
	if(!fd || !p_afnd)
		return;
	imprime_palabra(fd,p_afnd->palabra);
	return;
}

 /********************************************************************************
	Funcion: AFNDInicializaEstado
	Descripcion: inicializa el estado actual del autonoma a aquellos que sea de tipo INICIAL o
				INICIAL_Y_FINAL
	Argumentos:
				- AFND * p_afnd

	Salida:
       			- AFND * p_afnd
				- NULL otro caso



 *********************************************************************************/
AFND * AFNDInicializaEstado (AFND * p_afnd){
	int i = 0, j;
	char * nombre;
	if(!p_afnd)
		return NULL;
	for(i=0;i<p_afnd->nest;i++){
		if(get_tipo(p_afnd->est[i])==INICIAL || get_tipo(p_afnd->est[i])==INICIAL_Y_FINAL){
			AFNDInsertaActuales(p_afnd, get_nombre(p_afnd->est[i]));
			for(j = 0; j<p_afnd->nest; j++){
				if(getLvalor(p_afnd->lambda, i, j) == 1){
					nombre = get_nombre(p_afnd->est[j]);
					if(!es_repeticion(nombre, p_afnd->actuales, p_afnd->nact)){
						AFNDInsertaActuales(p_afnd, nombre);
					}
				}
			}
		}
	}
	return p_afnd;

}

 /********************************************************************************
	Funcion: AFNDProcesaEntrada
	Descripcion: funcion recursiva que procesa una palabra
	Argumentos:
				- FILE *fd
				- AFND * p_afnd




 *********************************************************************************/
void AFNDProcesaEntrada(FILE * fd, AFND * p_afnd){
	char *actual, **siguientes, *valor, *nombre;
	Estado * estado_actual;
	char ** aux = NULL;
	int naux = 0, i, j, nsiguientes, pos;
	/* caso base de la funcion recursiva */
	if(es_vacia(p_afnd->palabra) || p_afnd->nact == 0){
		AFNDImprimeConjuntoEstadosActual(fd, p_afnd);
		imprime_palabra(fd, p_afnd->palabra);
		AFNDeliminaActuales(p_afnd);
		return;
	}

	AFNDImprimeConjuntoEstadosActual(fd, p_afnd);
	imprime_palabra(fd, p_afnd->palabra);

	for(i=0; i<p_afnd->nact; i++){
		actual = p_afnd->actuales[i];
		estado_actual = buscar_estado(p_afnd, actual);
		valor = get_primer(p_afnd->palabra);
		siguientes = funcion_transicion(estado_actual, valor);
		if(siguientes){
			nsiguientes = get_nfinales_transicion(estado_actual,valor);
			for(j=0; j<nsiguientes; j++){
				/* si hay mas de un estado final de la transicion,
					entonces guardamos los estados finales en una variable
					auxiliar para despues copiarla en los estados actuales */
				if(naux != 0){
					if(!es_repeticion(siguientes[j], aux, naux)){
						naux +=1;
						aux = (char **)realloc(aux, naux*(sizeof(char *)));
						aux[naux-1] = (char*)malloc(TAM*sizeof(char));
						strcpy(aux[naux-1], siguientes[j]);
					}
				}
				else{
					naux +=1;
					aux = (char **)realloc(aux, naux*(sizeof(char *)));
					aux[naux-1] = (char*)malloc(TAM*sizeof(char));
					strcpy(aux[naux-1], siguientes[j]);
				}
			}
		}
	}
	AFNDeliminaActuales(p_afnd);
	for(i =0; i<naux; i++){
		pos = get_posicion_estado(p_afnd,aux[i]);
		AFNDInsertaActuales(p_afnd, aux[i]);
		/*aplicamos las transiciones lambda a los nuevos estados actuales*/
		for(j = 0; j<p_afnd->nest; j++){
			if(getLvalor(p_afnd->lambda, pos, j) == 1){
				nombre = get_nombre(p_afnd->est[j]);
				if(!es_repeticion(nombre, p_afnd->actuales, p_afnd->nact)){
					AFNDInsertaActuales(p_afnd, nombre);
				}
			}
		}
		free(aux[i]);
	}

	free(aux);
	AFNDTransita(p_afnd); /* Elimina de la palabra el simbolo que se acaba de procesar */
	AFNDProcesaEntrada(fd,p_afnd);
}

 /********************************************************************************
	Funcion: AFNDTransita
	Descripcion: elimina una letra de la palabra porque ya se ha procesado
	Argumentos:
				- AFND * p_afnd




 *********************************************************************************/
void AFNDTransita(AFND * p_afnd){
	eliminar_letra(p_afnd->palabra);
	return;
}

/********************************************************************************
 Funcion: buscar_estado
 Descripcion: busca un estado a partir de un nombre
 Argumentos:
       - AFND * p_afnd
       - char* nombre
 Salida:
       - Estado encontrado
       - NULL en otro caso



*********************************************************************************/
Estado* buscar_estado(AFND * p_afnd, char* nombre){
	int i = 0;
	if(!nombre||!p_afnd)
		return NULL;
	for(i = 0; i<p_afnd->nest; i++){
		if(!strcmp(get_nombre(p_afnd->est[i]), nombre))
			return p_afnd->est[i];
	}
	return NULL;
}

/********************************************************************************
	Funcion: es_repeticion
  	Descripcion: funcion auxiliar para comprobar si un simbolo ya pertenece
  				al conjunto de simbolos que se convertiran en actuales
  				para ser procesados por el automata
	Argumentos:
				- char* siguiente
        		- char**aux
        		- int naux
	Salida:
				- 1 si es repeticion
				- 0 en caso contrario

 *********************************************************************************/
int es_repeticion(char* siguiente, char**aux, int naux){
	int i;
	if(!siguiente || !aux){
		return 1;
	}
	for(i=0; i<naux;i++){
		if(!strcmp(siguiente,aux[i]))
			return 1;
	}
	return 0;
}

/********************************************************************************
 Funcion: get_posicion_estado
 Descripcion: obtiene la posicion de un estado en la lista de estados del afnd dado su nombre
 Argumentos:
			 -AFND * p_afnd = afnd
			 -char * nombre_estado = nombre del estado del que se quiere saber la posicion
 Salida:
			 - numero de la posicion si todo ha ido bien
			 - -1 en otro caso

*********************************************************************************/
int get_posicion_estado(AFND * p_afnd, char * nombre_estado){
	int i;
	if(!p_afnd || !nombre_estado)
		return -1;
	for(i=0; i<p_afnd->nest; i++){
		if(!strcmp(get_nombre(p_afnd->est[i]), nombre_estado))
			return i;
	}
	return -1;
}
/********************************************************************************
 Funcion: AFNDInsertaLTransicion
 Descripcion: inserta una transicion lambda en un afnd para dos estados dados
 Argumentos:
			 -AFND * p_afnd = afnd
			 -char * nombre_estado_i = nombre de un estado
			 -char* nombre_estado_f = nombre del otro estado
 Salida:
			 - p_afnd modificado

*********************************************************************************/
AFND* AFNDInsertaLTransicion(AFND* p_afnd, char* nombre_estado_i, char* nombre_estado_f){
	int i,f;
	i = get_posicion_estado(p_afnd, nombre_estado_i);
	f = get_posicion_estado(p_afnd, nombre_estado_f);
	insertaLTransicion(p_afnd->lambda,i,f);
	return p_afnd;
}
/********************************************************************************
 Funcion: AFNDCierraLTransicion
 Descripcion: completa la matriz de transiciones lambda aplicando las propiedades reflexiva y transitiva
 Argumentos:
			 -AFND * p_afnd = afnd
 Salida:
			 - p_afnd modificado

*********************************************************************************/
AFND* AFNDCierraLTransicion(AFND * p_afnd){
	cierraLReflexiva(p_afnd->lambda);
	cierraLTransitiva(p_afnd->lambda);
	return p_afnd;
}
/********************************************************************************
 Funcion: AFNDInicializaCadenaActual
 Descripcion: vacia la palabra que acaba de ser procesada
 Argumentos:
			 -AFND * p_afnd = afnd
 Salida:
			 - p_afnd modificado

*********************************************************************************/
AFND * AFNDInicializaCadenaActual (AFND * p_afnd ){
	int i;
	if(!es_vacia(p_afnd->palabra)){
		for(i = 0; i<size_palabra(p_afnd->palabra); i++){
			eliminar_letra(p_afnd->palabra);
		}
	}
	return p_afnd;
}

int letraValida(char * letra, AFND * p_afnd){
	int i;
	for(i = 0; i<p_afnd->talf; i++){
		if(!strcmp(letra, p_afnd->alf[i])){
			return 1;
		}
	}
	return 0;
}


/* Para la creación de los AFND1Os básicos */

AFND * AFND1ODeSimbolo(char * simbolo){
	AFND * afnd = AFNDNuevo("afnd", 2, 1)
	afnd = AFNDInsertaSimbolo(afnd, simbolo)
	afnd = AFNDInsertaEstado(afnd, "q0", INICIAL)
	afnd = AFNDInsertaEstado(afnd, "qf", FINAL)
	afnd = AFNDInsertaTransicion(afnd, "q0", simbolo, "qf")
	return afnd;
}
AFND * AFND1ODeLambda(){
	AFND * afnd = AFNDNuevo("afnd", 2, 1)
	afnd = AFNDInsertaEstado(afnd, "q0", INICIAL)
	afnd = AFNDInsertaEstado(afnd, "qf", FINAL)
	afnd = AFNDInsertaLTransicion(afnd, "q0", "qf");
	return afnd;
}
AFND * AFNDAAFND1O(AFND * p_afnd){
	/* FINALES*/
	char ** aux;
	int naux, i;
	Estado * est;
	naux = get_n_estados_tipo(p_afnd, FINAL);
	if(naux == 0){
		/*NO SE VA A DAR NUNCA, IMPLEMENTACION EN EL FUTURO*/
		return NULL;
	}
	if(naux != 1){
		aux = get_estados_tipo(p_afnd, FINAL);
		p_afnd = AFNDInsertaEstado(p_afnd, "qFINAL", FINAL);
		for(i=0; i< naux; i++){
			est = buscar_estado(p_afnd, aux[i]);
			setTipo(est, NORMAL);
			p_afnd = AFNDInsertaLTransicion(p_afnd, aux[i], "qFINAL");
		}
		free_estados_tipo(aux, naux);
	}

	/* INICIALES */
	naux = get_n_estados_tipo(p_afnd, INICIAL);
	if(naux == 0){
		/*NO SE VA A DAR NUNCA, IMPLEMENTACION EN EL FUTURO*/
		return NULL;
	}
	if(naux == 1){
		return p_afnd;
	}
	aux = get_estados_tipo(p_afnd, INICIAL);
	p_afnd = AFNDInsertaEstado(p_afnd, "qINICIAL", INICIAL);
	for(i=0; i< naux; i++){
		est = buscar_estado(p_afnd, aux[i]);
		setTipo(est, NORMAL);
		p_afnd = AFNDInsertaLTransicion(p_afnd, "qINICIAL",aux[i]);
	}
	free_estados_tipo(aux, naux);
	return p_afnd;
}

/* Para la creación de los AFND1Os derivados de otros mediante operadores regulares */
AFND * AFND1OUne(AFND * p_afnd1O_1, AFND * p_afnd1O_2){
	AFND * p_afnd = AFNDNuevo("afnd_U", 2, 1)
	char * i1,*i2,*f1,*f2;
	int i;
	p_afnd = AFNDInsertaEstado(p_afnd, "UI", INICIAL);
	p_afnd = AFNDInsertaEstado(p_afnd, "UF", FINAL);
	for(i=0; i<p_afnd1O_1->nest; i++){
		setNombre(p_afnd1O_1->est[i], "U1_");
		if(get_tipo(p_afnd1O_1->est[i]) == INICIAL){
			i1= get
		}
	}


}
AFND * AFND1OConcatena(AFND * p_afnd_origen1, AFND * p_afnd_origen2);
AFND * AFND1OEstrella(AFND * p_afnd_origen);

/* Para la representación gráfica compatible con .dot de cualquier AFND */
void AFNDADot(AFND * p_afnd);

char ** get_estados_tipo(AFND * p_afnd, enum TIPO tipo){
	int i, tam = 1;
	char ** estados = (char**)realloc(estados, tam*(sizeof(char *)));
	for(i=0; i<p_afnd->nest; i++){
		if(get_tipo(p_afnd->est[i]) == tipo || get_tipo(p_afnd->est[i]) == INICIAL_Y_FINAL){
			estados = (char**)realloc(estados, tam*(sizeof(char *)));
			strcpy(estados[tam-1], get_nombre(p_afnd->est[i]));
			tam +=1;
		}
	}
	return estado;
}

int get_n_estados_tipo(AFND * p_afnd, enum TIPO tipo){
	int i, cont = 0;
	for(i=0; i<p_afnd->nest; i++){
		if(get_tipo(p_afnd->est[i]) == tipo || get_tipo(p_afnd->est[i]) == INICIAL_Y_FINAL){
			cont +=1;
		}
	}
	return cont;
}

void free_estados_tipo(char** finales, int nfinales){
	int i;
	for(i=0; i< nfinales; i++){
		free(finales[i]);
	}
	free(finales);
	return;
}
