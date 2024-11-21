#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>



int main(int argc, char **argv)
{
	// printf("Hello l3alaam");
	// write(1, "12345678", 8);

	int n = 0;
	char *s = NULL;
	n = printf("%s", s);
	printf("\n%d\n", n);


	return 0;
}