/* Groesste Gemeinsamer Teilker Berechnen */

#include <stdio.h>
#include <stdlib.h>



int algorithmus(int z1, int z2) {
  
  int x;
  
  while(z1 % z2 != 0){
    x = z2;
    z2 = z1 % z2;
    z1 = x;
  }
  
  return(z2);  
}





int main(int argc, char *argv[]) {
  
  int z1, z2, ggt, x;
  int y = 1;
  
  printf("\n");
  
  if(argc != 3) {
    fprintf(stderr, "\tBitte Syntax beachten: %s <Zahl1> <Zahl2>\n\n", argv[0]);
    exit(EXIT_FAILURE);
  }											/* Fehler interceptione */
  
  if((sscanf(argv[1], "%d", &z1) != 1) || (sscanf(argv[2], "%d", &z2) != 1)) {
      fprintf(stderr, "\tBitte ganze Zahlen eingeben.\n\n");
      exit(EXIT_FAILURE);
  }
  
  if(z2 > z1) {			/* vertauscht ggf die Variablen fuer die spaetere Berechnung */
    x = z1;			
    z1 = z2;
    z2 = x;
    y = 0;			/* tellt fest ob eine Vertauschung der Variablen stattgefunden hat (wichtig fuer eine schoenere Ausgabe) */
  }				/* die Vertauschung haette auch in der Funktion Algorithmus stattfinden koennen aber ich wollte pruefen,
				    ob der ternaere Operator so anwendbar ist (siehe Ausgabe) */
  ggt = algorithmus(z1, z2);
  
  printf("\tDer groesste gemeinsame Teiler der Zahlen %d und %d lautet: ", (y ? z1 : z2), (y ? z2 : z1));	/* Ausgabe */
  fprintf(stdout, "%d", ggt);
  printf("\n\n");
  
  return(EXIT_SUCCESS);  
}