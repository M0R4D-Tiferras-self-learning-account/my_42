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

int	_putstr(char *s)
{
	int	idx;
	int	count;

	idx = 0;
	count = 0;
	if (s == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (s[idx] != '\0')
	{
		write(1, &s[idx], 1);
		count++;
		idx++;
	}
	return (count);
}

static char	*rev_str(char *str)
{
	int		idx;
	int		last_idx;
	char	tmp;

	idx = 0;
	if (str == NULL || str[0] == '\0')
		return (NULL);
	last_idx = _strlen(str) - 1;
	while (str[idx] != '\0' && (idx < last_idx))
	{
		tmp = str[idx];
		str[idx] = str[last_idx];
		str[last_idx] = tmp;
		idx++;
		last_idx--;
	}
	return (str);
}

int	hexa_address(unsigned long int num)
{
	int				idx;
	char			*hexa;
	char			buff[9];

	idx = 0;
	hexa = "0123456789abcdef";
	if (num == 0)
		return (_putstr("0x0"));
	_putstr("0x");
	while (num > 0)
	{
		buff[idx] = hexa[num % 16];
		idx++;
		num = num / 16;
	}
	buff[idx] = '\0';
	rev_str(buff);
	return (_putstr(buff) + 2);
}

int main(void)
{
	// print_strings(", ", 2, "Jay", "Django");
	// printf("%s\n", NULL);

	// int r = 0;
	// r = printf_return("%%");
	// printf("%d", r);

	// printf("Abc");
	// fflush(stdout);
	// write(1, "123\n", 4);

	char *s = "";
	printf("%p \n",s); // 7b
	hexa_address((unsigned long int)s);     // b7
	return 0;
}