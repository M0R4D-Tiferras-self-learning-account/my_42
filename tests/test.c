#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


void print_strings(const char *separator, const unsigned int n, ...)
{
	if (separator == NULL)
		return ;
	int arg_num = 0;
	va_list ptr;

	va_start(ptr, n);
	int i = 0;
	while(i < n)
	{
		printf("%s", va_arg(ptr, char *));
		if (i < (n-1))
			printf("%s", separator);
		i++;
	}
	printf("\n");
	va_end(ptr);
}

int main(void)
{
	// print_strings(", ", 2, "Jay", "Django");
	// printf("%s\n", NULL);

	printf("%i\n", 88);
	return 0;
}