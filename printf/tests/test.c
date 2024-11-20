#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int main(int argc, char **argv)
{
	// printf("Hello l3allaam");
	// write(1, "12345678", 8);
	int n = 0;
	n = printf("78%d", -54321);
	printf("\n%d\n", n);
	return 0;
}