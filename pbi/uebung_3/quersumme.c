/* Berechnung einer Quersumme */

  #include <stdio.h>
  #include <ctype.h>
  #include <string.h>
  #include <stdlib.h>
  
  
  int main(int argc, char *argv[])
  {
    int i, num;
    int qs = 0;
    if(argc != 2) {
      printf("\t Bitte das folgende Schema beachten: ./quersumme.x <Zahl> \n");
      exit(EXIT_FAILURE);
    }
    if((sscanf(argv[1], "%d", &num)) != 1) {
      printf("\t Bitte eine Zahl eingeben.\n");
      exit(EXIT_FAILURE);
    }
    for(i = 0; i < strlen(argv[1]); i++) {
      qs += (num % 10);
      num /= 10;
    }
    printf("\t Die Quersumme lautet: %d\n", qs);      
    return(EXIT_SUCCESS);
  }
    