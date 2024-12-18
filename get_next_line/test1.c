#include <libc.h>

int	main(void)
{
	char *s;
	int b;

	int fd = open("test.txt", O_RDWR);
	b = read(fd, s, 4);
	printf("\nthe red return = %d\n", b);
	printf("%s", s);
	b = read(fd, s, 4);
	printf("\nthe red return = %d\n", b);
	printf("%s", s);
	b = read(fd, s, 4);
	printf("\nthe red return = %d\n", b);
	printf("%s", s);
	return (0);
}