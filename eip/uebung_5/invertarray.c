

  /* Programm invertarraz.c */
  
  #include <stdio.h>
  
/*  int invert(int arr1[10]) {
    int i;
    int arr_inv[10];
    for(i = 9; i >= 0; i--) {
      return(arr1[i]);    
    }
  } */
int arr1[10];
int arr_inv[10];

int invertarray(int arr1[]) {
  int i;
  printf("  arr_inv = {");
  for(i = 0; i < 10; i++) {
    arr_inv[i] = arr1[9-i];
    if(i == 0) {
      printf("%d", arr_inv[i]);
    } else {
      printf(", %d", arr_inv[i]);
    }
  }
  printf("}\n");
  return(0);
}  
  
int main() {
  int i;
  int n;
  printf("  Bitte geben sie 10 Zahlen ein:\n");
  printf("  ");
  for(i = 0; i < 10; i++) {
    scanf("%d", &arr1[i]);
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