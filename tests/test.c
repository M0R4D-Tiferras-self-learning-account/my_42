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
<<<<<<< HEAD
    int n = 88;


    printf(" %d \n", &n);
    printf(" %lu \n", &n);

=======
	// int r = 0, r2 = 0;
	// r = printf("%s", NULL);
	// printf("\n");
	// r2 = ft_printf("%s", NULL);
	// printf("\nOriginal return; %d\nMine        %d\n", r, r2);


	int r;

	r = -1 * -2147483648;
	printf("%d\n", r);
>>>>>>> 52091a791f898e81e6ccccc428c3ce2c42884ded
	return 0;
}
