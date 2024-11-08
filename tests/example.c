#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static size_t	_len(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	needle_idx;
	size_t	restore_idx;

	idx = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while ((idx < len) && (haystack[idx] != '\0'))
	{
		needle_idx = 0;
		restore_idx = idx;
		while (haystack[restore_idx] == needle[needle_idx])
		{
			if (needle[_len(needle) - 1] == haystack[restore_idx])
				return ((char *)(haystack + idx));
			needle_idx++;
			restore_idx++;
		}
		idx++;
	}
	return (NULL);
}


int main()
{
    char *s1 = "hello";
    char *s2 = "ll";
    //printf("%s\n", ft_strnstr(s1, s2, 0));
    printf("%s\n", strstr(s1, s2, 3));
    return 0;
}