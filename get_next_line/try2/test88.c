# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>

int main()
{
    int fd = open("test.txt", O_RDWR);
    int byte;
    char *b;
    b = malloc(3 * sizeof(char));
    while (1)
    {
        byte = read(fd, b, 2);
        printf("\nreadit = %d\n buff = %s\n", byte, b);
        if (byte == 0 || byte == -1)
            break;
    }
    return 0;
}