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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				idx;
	unsigned char		*d;
	const unsigned char	*s;

	idx = 0;
	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	d = (unsigned char *)(dst);
	s = (const unsigned char *)(src);
	while (idx < n)
	{
		d[idx] = s[idx];
		idx++;
	}
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	dst_idx;

	idx = 0;
	dst_idx = 0;
	if (my_len(src) + 1 <= dstsize)
		ft_memcpy(dst, src, my_len(src) + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (my_len(src));
}

int main()
{
	char *s = NULL;
	char *d = NULL;

	printf("%zu\n", ft_strlcpy(d, s, 0));
	return 0;
}
