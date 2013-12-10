#include <stdlib.h>
#include <stdio.h>



int scann()
{								/* einscannen einer beliebigen Zahl x */
  int x;
  printf("  input number\n");
  if(scanf("%d",&x) != 1) {
  fprintf(stderr,"  wrong input\n");
  exit(EXIT_FAILURE);
  }
  return(x);
}
  
// static int							/* Nicht mehr noetig dank scann() */
// ask()
// {
//   printf("input number\n");
//   d=a;
//   if(scanf("%d",&b) != 1 || b <= 0) {
//   fprintf(stderr,"wrong input\n");
//   return( 1000 );
//   }
//   return( 4 );
// }

int exp(int var1, int var2)
{
  int res = var1;						/* Resultat */
  int i;							/* Schleifenzaehler */
  for(i = 1; i < var2; i++){ 
    res *= var1; 
  }
  return(res);
}

int main ()
{
  int var1;
  int var2;
  var1 = scann();
  var2 = scann();
  if(var2 < 1) {
    printf("  Not possible with this program.\n");
    return(EXIT_FAILURE);					/* Bedie Variablen werden ueberprueft ob > 0*/
  }
  printf("  result is %d\n", exp(var1, var2));
  return(EXIT_SUCCESS);
}
