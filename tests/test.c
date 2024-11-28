#include <stdio.h>
#include <unistd.h>
#include "../printf/ft_printf.h"


// 3284 -> 205R4 -> 12R13 -> 0R12 == 0xCD4


int	main(void)
{
	// int r = 0, r2 = 0;
	// r = printf("%s", NULL);
	// printf("\n");
	// r2 = ft_printf("%s", NULL);
	// printf("\nOriginal return; %d\nMine        %d\n", r, r2);


	int r;

	r = -1 * -2147483648;
	printf("%d\n", r);
	return 0;
}