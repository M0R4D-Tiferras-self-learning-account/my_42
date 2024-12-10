#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/errno.h>
#include <fcntl.h>
#include "../printf/ft_printf.h"


// void print_numbers(int count, ...) {
//     int copy = 0;
//     va_list args;
//     va_start(args, count);

//     for (int i = 0; i < count; i++) {
//         int num = va_arg(args, int);  // Fetch the next int argument
//         printf("%d ", num);
//     }

//     va_end(args);
//     printf("\n");
// }

int	main(void)
{
    int n = 88;


    printf(" %d \n", &n);
    printf(" %lu \n", &n);

	return 0;
}
