
/* Programm: Mittelwert.c			September 2008, Version 1
   Ziel: berechnet Mittelwert und Standardabweichung */

#include <stdio.h>
#include <math.h>

void fehlermeldung() {
  printf("ERRORRRRRRR\n");
  printf("\n");
}

int main()
{ int n;			/* Anzahl Datenpunkte */
  double v;			/* aktueller Datenpunkt */
  double summe= 0;              /* Summe der Datenpunkte */
  double summe2= 0;		/* Summe der Datenpunktquadrate */
  int i;			/* Schleifenvariable */
  double mw, std;		/* Mittelwert und Standardabweichung */
  int operation;
  double max;
  double min;	
  
  printf(" >> Berechnung von Mittelwert und Std-Abweichung\n");
  
    
  printf("  Berechnen von Mittelwerten und Standardabweichungen (0), Maximum (1), Minimum (2)?:  ");
  if(scanf("%d", &operation) != 1) {
    fehlermeldung();
  } else if(operation == 0) {
    printf("    Anzahl Werte: "); 
    scanf("%d", &n);
    printf("\n");
    for( i=1; i <= n; i++ ) {
      printf("   %d. Wert: ",i); 
      scanf("%lf", &v);
      summe += v;
      summe2 += (v*v);
    }
    mw = summe / n;
    std = sqrt( (summe2 / n - mw*mw) );
    printf("    Mittelwert: %lf   Standardabweichung: %lf\n", mw, std);
    printf("\n");
  } else if(operation == 1) {
    printf("    Anzahl Werte: "); 
    scanf("%d", &n);
    printf("\n");
    for(i = 1; i <= n; i++) {
      printf("   %d. Wert: ",i); 
      if(scanf("%lf", &v) != 1) {
	fehlermeldung();
      } else {
	if(i == 1) {
	  max = v;
	}
	else if(v > max) {
	  max = v;
	}
	
      }
    }
     printf("   Maximum: %lf\n", max);
  } else if(operation == 2){
    printf("    Anzahl Werte: "); 
    scanf("%d", &n);
    printf("\n");
    i = 0;
    while(i++ < n) {
      printf("   %d. Wert: ",i);
      if(scanf("%lf", &v) != 1) {
	fehlermeldung();
      } else if(i == 1) {
	min = v;
      } else if(v < min) {
	min = v;
      }
    }
    printf("   Minimum: %lf\n", min);
    printf("\n");
  } else {
    fehlermeldung();
  }
  return(0);
}

