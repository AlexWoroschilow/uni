/* Aufgabe 5.2 */


#include <stdio.h>
#include <stslib.h>
#include "./Array_Modul"

#define NUMOFBITS 32


int invertarray(char *arr, int length) {
  
    int i;
    char x;
    
    for(i = 0; i < length / 2; i++) {
        x = arr[i];
        arr[i] = arr[length - i];
        arr[length - i] = x;      
    }
  
    return(0);
}


void decimal2bitvector(char *bitvector, unsigned int n) {

      for(i = 0; i < NUMOFBITS; i++) {
          bitvector[i] = (n % 2 ? '1' : '0');
      }
      
    invertarray(bitvector, NUMOFBITS);  
   
}


unsigned int bitvector2decimal(constchar *bitvector) {
    
    
    
    
    
}



int main(int argc, char *argv[]) {
    
    int zahl, zahl2;
    char bitvector(NUMOFBITS);
    
    if(argc != 2) {
        fprintf(stderr, "\tBitte Syntax beachten: %s <Zahl>\n", argv[1]);
        exit(EXIT_SUCCESS);
    }
    
    if(!(sscanf(argv[1], "%d", zahl) {
        fprintf(stderr, "\tDies ist keien Zahl.\n");
        exit(EXIT_SUCCESS);
    }
    
    decimal2bitvector(bitvector, zahl);
    
    printf("\tDer Bitvector lautet: %s\n", bitvector);
    
    zahl2 = bitvector2decimal(bitvector);
    
    printf("\tDie eingebene Zahl lautet: %d\n", zahl2);
    
    return(EXIT_SUCCESS);
}