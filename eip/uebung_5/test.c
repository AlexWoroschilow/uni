
  /* Test des Array_Moduls */
  
#include <stdio.h>
#include <string.h>
#include "./Array_Modul.h"


int main() {
  int array[30];
  int array_length;
  array_length = sizeof(array) / sizeof(int);
  scanarray(array, array_length);
  invertarray(array, array_length);
  sortarray(array, array_length);
  return(0);
}