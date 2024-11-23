#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


// void print_strings(const char *separator, const unsigned int n, ...)
// {
// 	if (separator == NULL)
// 		return ;
// 	int arg_num = 0;
// 	va_list ptr;

// 	va_start(ptr, n);
// 	int i = 0;
// 	while(i < n)
// 	{
// 		printf("%s", va_arg(ptr, char *));
// 		if (i < (n-1))
// 			printf("%s", separator);
// 		i++;
// 	}
// 	printf("\n");
// 	va_end(ptr);
// }

int	_strlen(const char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
		return (6);
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

int	printf_return(const char *str)
{
	int	idx;
	int	j;
	int	count;

	count = 0;
	idx = 0;
	while ((str[idx] != '\0'))
	{
		j = idx + 1;
		if (j < _strlen(str))
		{
			if (str[idx] == '%' && str[j] == '%')
			{
				count++;
				idx++;
				continue ;
			}
		}
		if (str[idx] == '%')
			idx++;
		else if (str[idx] != '%')
			count++;
		idx++;
	}
	return (count);
}

int main(void)
{
	// print_strings(", ", 2, "Jay", "Django");
	// printf("%s\n", NULL);

	int r = 0;
	r = printf_return("%%");
	printf("%d", r);
	return 0;
}