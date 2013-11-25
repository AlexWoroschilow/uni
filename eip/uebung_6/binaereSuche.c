

//	Binaere Suche!

#include <stdio.h>
#include "./Array_Modul.h"

main() {
  int array[10];
  int array_length;
  int x;
  printf("\n\n  ----------------------- Wilkommen ---------------------- \n\n");
  printf("  Dies ist eine binaere Suchmaschine fuer int Arrays.\n\n");
  printf("  Zunaechst wird ein Array benoetigt...\n");
  array_length = sizeof(array) / sizeof (int);
  scanArray(array, array_length);
  printf("\n  Der Array muss nun sortiert werden...\n");
  sortArray(array, array_length);
  binSearchArray(array, array_length);
  printf("  ----------- Danke und bis zum naechsten mal! ----------- \n");
  printf("  -------------------------------------------------------- \n\n");
  return(0);
}