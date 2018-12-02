
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alfabeto.h"
#include "estado.h"
#include "afnd.h"
#include "palabra.h"

int main(int argc, char ** argv)
{
AFND * p_afnd_l1;
AFND * p_afnd_l5;
/* SE CREA UN AUTÓMATA FINITO PARA LA EXPRESION REGULAR “1” */
p_afnd_l1 = AFND1ODeSimbolo("1");
/* SE CREA UN AUTÓMATA FINITO PARA LA EXPRESION REGULAR “0” */
p_afnd_l0 = AFND1ODeSimbolo("0");
/* SE CREA UN AUTÓMATA FINITO PARA LA EXPRESION REGULAR “1”.”1” */
p_afnd_l2 = AFND1OConcatena(p_afnd_l1, p_afnd_l1);
/* SE CREA UN AUTÓMATA FINITO PARA LA EXPRESION REGULAR “0”+“1” */
p_afnd_l4 = AFND1OUne(p_afnd_l0, p_afnd_l1);

/* SE CALCULA EL CIERRE REFLEXIVO-TRANSITIVO DE TODOS LOS AUTÓMATAS */
 p_afnd_l0 = AFNDCierraLTransicion(p_afnd_l0);
 p_afnd_l1 = AFNDCierraLTransicion(p_afnd_l1);
 p_afnd_l2 = AFNDCierraLTransicion(p_afnd_l2);
 p_afnd_l4 = AFNDCierraLTransicion(p_afnd_l4);
/********************************************************/
fprintf(stdout,"EJEMPLO DE AUTÓMATA DE UNA EXPRESIÓN CORRESPONDIENTE A UN SÍMBOLO: 1\n");
AFNDImprime(stdout,p_afnd_l1);
fprintf(stdout,"EJEMPLO DE AUTÓMATA DE UNA EXPRESIÓN CORRESPONDIENTE A LA CONCATENACIÓN DE OTROS DOS, JUSTAMENTE CONCATENA EL ANTERIOR CONSIGO MISMO\n");
AFNDImprime(stdout,p_afnd_l2);
fprintf(stdout,"A CONTINUACIÓN SE VA A MOSTRAR LA UNIÓN DE DOS AUTÓMATAS QUE VIENEN DE EXPRESIONES REGULARES, UNO DE ELLOS ES EL CORRESPONDIENTE A LA EXPRESION 1 QUE YA SE MOSTRÓ ANTERIORMENTE, EL OTRO ES EL DE LA EXPRESIÓN 0 QUE SE MUESTRA A CONTINUACIÓN\n");
AFNDImprime(stdout,p_afnd_l0);
fprintf(stdout, "Y ESTA ES SU UNIÓN\n");
AFNDImprime(stdout,p_afnd_l4);
/********************************************************/
AFNDElimina(p_afnd_l0);
AFNDElimina(p_afnd_l1);
AFNDElimina(p_afnd_l2);
AFNDElimina(p_afnd_l4);
/********************************************************************************/
return 0;
}
