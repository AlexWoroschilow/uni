

  /* Quersummenberechnung */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int q_sum(int zahl, int len)
{
  int i;
  int qsum = 0;
  
  for(i = 0; i < len; i++) {
  qsum += zahl % 10;
  zahl = zahl / 10;
  }
  
  return(qsum);
}


int main(int argc, char *argv[]) 
{
  int zahl, len;
  
  if(argc != 2) {
    printf("\t Bitte Syntax beachten: ./quersumme.x <Zahl>\n");
    exit(EXIT_FAILURE);
  }
  
  len = strlen(argv[1]);

  if((sscanf(argv[1], "%d", &zahl)) != 1) {
    printf("\t Bitte eine ZAHL eingeben.\n");
    exit(EXIT_FAILURE);
  }
  
  printf("\t Die Quersumme lautet: %d\n", q_sum(zahl, len));
  
  return(EXIT_SUCCESS);
}