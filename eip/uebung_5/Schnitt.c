  
  
  
  /* Programm Schnitt.c */
  
  #include <stdio.h>

void vergl(int arr1[5], int arr2[5]) {
  int i;
  int j;
  int c = 0;
  printf("  arr1 und arr2 stimmen in den Zahlen {");
  for(i = 0; i < 5; i++) {
    for(j = 0; j < 5; j++) {
      if(arr1[i] == arr2[j]) {
	c++;
	if(c == 1) {
	  printf("%d", arr1[i]);
	} else {
	  printf(", %d", arr1[i]);
	}
      }
    }
  }
  printf("} ueberein.\n");
}
	
  
int main() {
  
  int arr1[5] = {1,2,3,4,5};
  int arr2[5] = {4,5,6,7,8};
  
  vergl(arr1, arr2);
  
  return(0);
}