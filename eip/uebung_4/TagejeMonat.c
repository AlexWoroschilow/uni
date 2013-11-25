
/* Programm: TageProMonat.c        September 2008, Version 1
   Ziel: Berechnet die Anzahl der Tage pro Monat */

#include <stdio.h>

int sj;

static int schaltjahr( int jahreszahl ){
  
  if(jahreszahl % 4 == 0) {
    if(jahreszahl % 100 == 0) {
      if(jahreszahl % 400 == 0) {
	sj = 1;
      } else {
	sj = 0;
      }
    } else {
      sj = 1;
    }
  } else {
    sj = 0;
  }
  return(sj);
}

void fehlermeldung() {
  printf("ERRORRRR!\n");
}

int main()
{ int monat, jahr;            /* Monat, fuer den die #Tage */
  int tage;                /* berechnet werden soll    */
  printf(" >> Bestimmung der Tage pro Monat\n");
  printf("    Monat: "); 
  if(!scanf("%d", &monat) || monat > 12 || monat < 0) {
    fehlermeldung();
  } else {
    printf("    Jahr:  ");
  }
  if(!scanf("%4d", &jahr) || jahr < 1582) {
    fehlermeldung();
  } else {
    switch( monat )
    { case  2: tage = ( schaltjahr(jahr) ? 29 : 28 );
	      break;
      case  4:
      case  6:
      case  9:
      case 11: tage = 30;
	      break;
      default: tage = 31;
    }
    printf("    Der Monat %d im Jahr %d hat %d Tage.\n", monat, jahr, tage);
  }
    return(0);
 }

