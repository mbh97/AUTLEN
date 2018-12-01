
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alfabeto.h"
#include "estado.h"
#include "afnd.h"
#include "palabra.h"

int main(int argc, char ** argv)
{
AFND * p_afnd_l0;
AFND * p_afnd_l1;
AFND * p_afnd_l2;
AFND * p_afnd_l3;
AFND * p_afnd_l4;
AFND * p_afnd_l5;
AFND * p_afnd_l6;
/* SE CREA UN AUTÓMATA FINITO PARA LA EXPRESION REGULAR “1” */
p_afnd_l1 = AFND1ODeSimbolo("1");
p_afnd_l5 = AFND1OEstrella(p_afnd_l1);
 p_afnd_l1 = AFNDCierraLTransicion(p_afnd_l1);
 p_afnd_l5 = AFNDCierraLTransicion(p_afnd_l5);
/********************************************************/
fprintf(stdout,"EJEMPLO DE AUTÓMATA DE UNA EXPRESIÓN CORRESPONDIENTE A UN SÍMBOLO: 1\n");
AFNDImprime(stdout,p_afnd_l1);
fprintf(stdout,"SE MUESTRA EL AUTÓMATA FINITO CORRESPONDIENTE A LA EXPRESION 1 * A PARTIR DEL AUTÓMATA ASOCIADO CON 1 QUE YA SE MOSTRÓ ANTERIORMENTE\n");
AFNDImprime(stdout,p_afnd_l5);

/********************************************************/
AFNDElimina(p_afnd_l1);
AFNDElimina(p_afnd_l5);
/********************************************************************************/
return 0;
}
