

  /* Array_Modul.c: Modul zum scannen, invertieren und sortieren von Arrays. */
  
  #include <stdio.h>
  #include "./Array_Modul.h"
  


int scanArray(int arr1[], int length) {
  int i;
  char k;
  printf("\n  --------------------- Array-Eingabe -------------------- \n\n");

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
  printf("  Array: {");
  for(i = 0; i < length; i++) {
    if(i == 0) {
	printf("%d", arr1[i]);
    } else {
	printf(", %d", arr1[i]);
    }
  }
  printf("}\n");
  printf("  Korrekt? (J/n): ");
  scanf(" %c", &k);
  switch(k) {
    case 'J': 
      printf("\n  -------------------------------------------------------- \n");
      return(0); break;
    case 'n':
      scanArray(arr1, length); break;
    default:
      printf("  Ungueltig. Dein Problem.\n");
      printf("\n  -------------------------------------------------------- \n");
      return(0);
  }
}

int invertArray(int arr1[], int length) {
  int i;
  int arr_inv[256];
  printf("\n  ------------------ Array-Invertierung ------------------ \n\n");
  printf("  Invertierter Array: {");
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
  printf("\n  -------------------------------------------------------- \n");
  return(0);
}

int sortArray(int arr1[], int length) {
  int i;
  int j;
  int zw;
  printf("\n  ------------------- Array-Sortierung ------------------- \n\n");
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
      printf("  Sortierter Array: {%d", arr1[i]);
    } else if(i < (length - 1)) {
      printf(", %d", arr1[i]);
    } else {
      printf(", %d}\n", arr1[i]);
    }
  }
  printf("\n  -------------------------------------------------------- \n");
  return(0);  
}

int halb(int i, int j, int length, int par[], int arr1[], int x) {
  if (arr1[par[0]] > x || arr1[par[1]] < x) {
    printf("  Die %d befindet sich nicht in diesem Array.\n", x);
  } else if(arr1[i] > x && arr1[j] != x) {
    par[1] = i;    
    length = par[1] - par[0] + 1;
    int i = par[0] + ((length) / 2) - 1;
    int j = par[0] + ((length) / 2);
    halb(i, j, length, par, arr1, x);      
  } else if(arr1[j] < x && arr1[i] != x) {
    par[0] = j;
    length = par[1] - par[0] + 1;
    int i = par[0] + ((length) / 2) - 1;
    int j = par[0] + ((length) / 2);
    halb(i, j, length, par, arr1, x);
  } else if(arr1[i] == x) {
    printf("  Die %d befindet sich an der Stelle %d!\n", x, i);
  } else if(arr1[j] == x) {
    printf("  Die %d befindet sich an der Stelle %d!\n", x, j);
  }
  return(0);
}


int binSearchArray(int arr1[], int length) {  
  int i = ((length + 1) / 2) - 1;
  int j = ((length + 1) / 2);
  int par[2];
  int x;
  char k;
  par[0] = 0;
  par[1] = length - 1;
  printf("\n  -------------------- Binaere Suche --------------------- \n\n");
  printf("  Nach welcher Zahl soll gesucht werden?\n\n  ");
  scanf("%d", &x);
  printf("  \n");
  halb(i, j, length, par, arr1, x);
  printf("\n  Moechten Sie eine weitere Zahl suchen? (J/n): ");
  scanf(" %c", &k);
  switch(k) {
    case 'n': 
      printf("\n  -------------------------------------------------------- \n");
      return(0); break;
    case 'J':
      binSearchArray(arr1, length); break;
    default:
      printf("  Ungueltig. Dein Problem.\n");
      printf("\n  -------------------------------------------------------- \n");
      return(0);
  }
}
  
  
  
  
  
  
  
  
  
  