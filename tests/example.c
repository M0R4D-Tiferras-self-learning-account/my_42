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

	idx = 0;
	if (haystack == NULL || needle == NULL)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while ((idx < len) && (haystack[idx] != '\0'))
	{
		needle_idx = 0;
		while (haystack[idx + needle_idx] == needle[needle_idx]
			&& (idx + needle_idx < len) && haystack[idx] != '\0')
		{
			if (needle[_len(needle) - 1] == haystack[idx + needle_idx]
				&& (needle[needle_idx + 1] == '\0'))
				return ((char *)(haystack + idx));
			needle_idx++;
		}
		idx++;
	}
	return (NULL);
}


int main()
{
    char *s1 = NULL;
    char *s2 = NULL;
    //printf("%s\n", ft_strnstr(s1, s2, 0));
    printf("%s\n", strstr(s1, s2, 3));
    return 0;
}