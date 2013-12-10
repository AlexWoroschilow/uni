/* ASCII Tabelle */

#include <stdio.h>
#include <limits.h>


int main()
{
  int i;
  
  printf("\n\t\t\t\t\t\t\tASCII Tabelle\n");
  for(i = 0; i <= UCHAR_MAX; i++) {
    if(i % 7 == 0) {
      printf("\n\t__________________________________________________________________________________________________________\n\n");
    }
    
    if(i < 34) {
      if(i == 7) {
	printf("\t%.3d |   \\b", i);
      } else if(i == 8) {
	printf("\t%.3d |   \\b", i);
      } else if(i == 9) {
	printf("\t%.3d |   \\t", i);
      } else if(i == 10) {
	printf("\t%.3d |   \\n", i);
      } else if(i == 11) {
	printf("\t%.3d |   \\v", i);
      } else if(i == 12) {
	printf("\t%.3d |   \\f", i);
      } else if(i == 13) {
	printf("\t%.3d |   \\r", i);
      } else {
	if(i < 10) {
	  printf("\t%.3d |   \\%-3d", i, i);
	} else {
	  printf("\t%.3d |  \\%-3d", i, i);
	}
      }
    } else if(i > 126) {
      printf("\t%.3d | \\%3d", i, i);
    } else {
      printf("\t%.3d | %3c", i, i);
    }
  }
  printf("\n\n");
  return(0);
}