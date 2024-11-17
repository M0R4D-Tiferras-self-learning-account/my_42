#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


int	main(void)
{
	int	fd;
	size_t bsize = 100000;
	char buffer[bsize];
	int n = -1;

	if (buffer[0] == '\0')
	{
		printf("buff[0] is null terminated\n");
	}

	fd = open("./text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erorr in fd, fd = %d \n", fd);
		exit(3);
	}

	n = read(fd, buffer, bsize);
	if (n < 0)
	{
		printf("Error in reading file\n");
		exit(3); 
	}

	if (buffer[0] == '\0')
	{
		printf("The file is empty\n");
		exit(3);
	}

	printf("%s", buffer);
	return (0);
}
