

  /* Array_Modul.c: Modul zum scannen, invertieren und sortieren von Arrays. */
  
  #include <stdio.h>
  #include "./Array_Modul.h"
  


int scanarray(int arr1[], int length) {
  int i;
  printf("  Bitte geben sie %d Zahlen ein:\n", length);
  printf("  ");
  for(i = 0; i < length; i++) {
    if(!(scanf("%d", &arr1[i]))) {
      printf("ERRORRR!\n");
      return(0);
    }
    printf("  ");
  }
  printf("\n");
  printf("  arr1 = {");
  for(i = 0; i < length; i++) {
    if(i == 0) {
	printf("%d", arr1[i]);
    } else {
	printf(", %d", arr1[i]);
    }
  }
  printf("}\n");
  return(0);
}

int invertarray(int arr1[], int length) {
  int i;
  int arr_inv[256];
  printf("  arr_inv = {");
  for(i = 0; i < length; i++) {
    arr_inv[i] = arr1[length - 1 - i];
    if(i == 0) {
      printf("%d", arr_inv[i]);
    } else {
      printf(", %d", arr_inv[i]);
    }
  }
  for(i = 0; i < length; i++) {
    arr_inv[i] = arr1[i];
  }
  printf("}\n");
  return(0);
}

int sortarray(int arr1[], int length) {
  int i;
  int j;
  int zw;
  for(i = 1; i < length; i++) {
    j = i;
    while((arr1[j] < arr1[j - 1]) && (j > 0)) {
      zw = arr1[j];
      arr1[j] = arr1[j - 1];
      arr1[j - 1] = zw;
      j--;
    }
  }
  for(i = 0; i < length; i++) {
    if(i == 0) {
      printf("  arr1 sortiert: {%d", arr1[i]);
    } else if(i < (length - 1)) {
      printf(", %d", arr1[i]);
    } else {
      printf(", %d}\n", arr1[i]);
    }
  }
  return(0);  
}