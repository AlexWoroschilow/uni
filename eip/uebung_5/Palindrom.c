

  /* Palindrom.c */
  
#include <stdio.h>
#include <string.h>

char string[256];
int string_length;

int is_palindrom(char string[]) {
  int i;
  for(i = 0; i < string_length / 2; i++) {
    if(tolower(string[i]) != tolower(string[string_length - i - 1])) {
      return(0);
    }
  }
  return(1);
}
    

    
int main() {
  printf("\n");
  printf("  Bitte geben Sie eine Zeichenkette ein: ");
  scanf("%[^\n]254s", string);
  printf("\n");
  string_length = strlen(string);
  printf("  \"%s\"\n", string);
  printf("\n");
  if(is_palindrom(string)) {
    printf("  Die eingegebene Zeichenkette ist ein Palindrom.\n");
  } else {
    printf("  Die eingegebene Zeichenkette ist kein Palindrom.\n");
  }
  printf("\n");
  return(0);
}