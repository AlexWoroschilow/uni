#include <stdio.h>



int main()
{
	char string[] = "-3";
	signed int x;

	sscanf(string, "%i", &x);

	printf("%i\n", x);

	return 0;
}