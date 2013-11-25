

  /* Quersummenberechnung */

#include <stdio.h>
#include <string.h>




void fehlermeldung() {
  printf("\n  ERRORRR!\n  Syntax: ./quersumme <Zahl>\n\n");
}

int q_sum(int zahl) {
  int a;
  int b;
  if(zahl < 10) {
    return(zahl);
  } else {
    a = zahl % 10;
    b = zahl / 10;
    printf("  %d", (a + q_sum(b)));
    return(a + q_sum(b));
  }
}

int fak(int zahl) {
  if(zahl > 2) {
    return(zahl * fak(zahl - 1));
  } else {
    return(zahl);
  } 
}

int main(int argc, char *argv[]) {
  int zahl;
  if(argc != 2) {
    fehlermeldung();
  } else {
    zahl = atoi(argv[1]);
    printf("\n  Die Quersumme lautet: %d\n", q_sum(zahl));
    printf("\n  Die Fakultaet lautet: %d\n\n", fak(zahl));
  }
  return(0);
}