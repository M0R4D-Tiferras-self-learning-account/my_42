#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static size_t	my_len(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	source_idx;
	size_t	dst_idx;
	size_t	restore_dst_len;

	if (dst == src)
		return (0);
	if (dstsize == 0 && dst == NULL && src)
		return (my_len(src));
	if (((my_len(dst) >= dstsize)))
		return (dstsize + my_len(src));
	source_idx = 0;
	dst_idx = my_len(dst);
	restore_dst_len = my_len(dst);
	while (src[source_idx] != '\0' && (dst_idx < dstsize - 1))
	{
		dst[dst_idx] = src[source_idx];
		dst_idx++;
		source_idx++;
	}
	dst[dst_idx] = '\0';
	return (restore_dst_len + my_len(src));
}

int main()
{
	char *s = "hi";
	char *d = NULL;

	printf("%lu\n", ft_strlcat(0, s, 0));
	return 0;
}
