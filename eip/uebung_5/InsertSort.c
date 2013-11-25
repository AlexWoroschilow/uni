  
  
  /* InsertSort.c */
  
#include <stdio.h>

int arr1[10];

void fehlermeldung() {
  printf("ERRORRR!\n");
}

int sortarray(int arr1[]) {
  int i;
  int j;
  int zw;
  for(i = 1; i < 10; i++) {
    j = i;
    while((arr1[j] < arr1[j - 1]) && (j > 0)) {
      zw = arr1[j];
      arr1[j] = arr1[j - 1];
      arr1[j - 1] = zw;
      j--;
    }
  }
  for(i = 0; i < 10; i++) {
    if(i == 0) {
      printf("  Der sortierte Array lautet: {%d", arr1[i]);
    } else if(i < 9) {
      printf(", %d", arr1[i]);
    } else {
      printf(", %d}\n", arr1[i]);
    }
  }
  return(0);  
}

int scanarray(int arr1[]) {
  int i;
  printf("  Bitte geben sie 10 Zahlen ein:\n");
  printf("  ");
  for(i = 0; i < 10; i++) {
    if(!(scanf("%d", &arr1[i]))) {
      fehlermeldung();
      return(0);
    }
    printf("  ");
  }
  printf("\n");
  printf("  arr1 = {");
  for(i = 0; i < 10; i++) {
    if(i == 0) {
	printf("%d", arr1[i]);
    } else {
	printf(", %d", arr1[i]);
    }
  }
  printf("}\n");
  return(0);
}

int main() {
  scanarray(arr1);
  sortarray(arr1);
  return(0);
}