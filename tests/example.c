#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int	count_words(char const *str, char sep)
{
	size_t	idx;
	size_t	count;
	int		check;

	idx = 0;
	count = 0;
	check = 88;
	while (str[idx] != '\0')
	{
		if ((str[idx] == sep))
		{
			check = 1;
		}
		else if ((str[idx] != sep) && (check == 1 || check == 88))
		{
			count++;
			check = -1;
		}
		idx++;
	}
	return (count);
}

int main()
{
	char *s = "1 2 3";

	printf("%d\n", count_words(s, ' '));
	return 0;
}
