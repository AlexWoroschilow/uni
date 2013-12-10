/* Aufgabe 4.3 */


#include <stdio.h>
#include <stdlib.h>





float betrag(float n) {
  
  if(n < 0) {
    return(0 - (n));					/* gibt den Betrag einer Fliesspunktzahl zurueck */
  } else {
    return(n);
  }
  
  return(0);
}




int buildMaxHeap(float Arr[], long unsigned size) {	/* buildMaxHeap mit den Betraegen der Array Elemente als Kriterium */

  int y, j, k;
  int i = size - 1;
  float x;
  
  for(y = 0; y < size; y++) {
    while(i > 0) {
      
      i = (i % 2 ? i : i - 1);				/* i immer ungerade und damit am zweiten Kind des binaeren Heaps */
      j = (i - 1) / 2;
      k = i - 1;
    
      if(j > 0 && betrag(Arr[k]) > betrag(Arr[j])) {
        if(i < size && betrag(Arr[i]) > betrag(Arr[k])) {
          x = Arr[j];
          Arr[j] = Arr[i];
          Arr[i] = x;
          i -= 2;
          continue; 
        }
        x = Arr[j];
        Arr[j] = Arr[k];
        Arr[k] = x;
        i -= 2;
        continue;
      } else if (j > 0 && i < size && betrag(Arr[i]) > betrag(Arr[j])) {
        x = Arr[j];
        Arr[j] = Arr[i];
        Arr[i] = x;
        i -= 2;
        continue;
      } else {
        i -= 2;
        continue;
      }
    }
  }
  
  return(0);
}




int findsizeof(float n) {
  
  int i = 0;
  
  while(betrag(n) >= 1) {				/* Gibt die Anzahl der Stellen vor dem Komma zurueck */
    
    n /= 10;
    i++;
    
  }
  
  return(i);
}
  

  
  
  
int main (int argc, char *argv[]) {
  
  int i, laenge;
  float Arr[6];
  long unsigned size = sizeof(Arr)/sizeof(float);
  
  printf("\n");
  
  if(argc != 6) {
    fprintf(stderr, "\tBitte Syntax beachten: %s <Zahl1> <Zahl2> <Zahl3> <Zahl4> <Zahl5>\n\n", argv[0]);
    exit(EXIT_FAILURE);
  }											/* Fehler interceptione */
  
  Arr[0] = 0;
  
  for(i = 1; i < size; i++) {
    if(!(sscanf(argv[i], "%f", &Arr[i]))) {
      fprintf(stderr, "\tBitte 5 Zahlen eingeben.\n\n");
      exit(EXIT_FAILURE);
    }
  }
  
  
  buildMaxHeap(Arr, size);
  
  laenge = findsizeof(Arr[1]) + 4 + 1 + 1;						/* +4 fuer die Nachkommastellen, +1 fuer den Punkt, +1 fuer das Vorzeichen */
  
  printf("\tDie Zahlen lauten:\n");
  
  for(i = 1; i < size; i++) {
    printf("\n\t%+0*.4f\n", laenge, Arr[i]);
  }
  printf("\n\n");    
    
  return(EXIT_SUCCESS);
}