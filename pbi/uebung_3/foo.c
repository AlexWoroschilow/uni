#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int number, error;
  if (argc != 2) {
    /* print some error code and exit */
    fprintf(stderr, "please give one parameter\n");
    exit(1);
  }
  printf("%s\n", argv[0]);
  printf("%s\n", argv[1]);

  error = sscanf(argv[1], "%d", &number);

  if (error != 1) {
    fprintf(stderr, "that was no number! %s\n", argv[1]);
    exit(2);
  }

  printf("%20d\n", number);
  return 0;
}
