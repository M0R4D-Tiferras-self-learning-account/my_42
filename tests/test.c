#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

int	_power(int num, int pow)
{
	int	it;
	int	result;

	it = 1;
	result = 1;
	if (pow == 0)
		return (1);
	while (it <= pow)
	{
		result = result * num;
		it++;
	}
	return (result);
}

int	*char_con(char c)
{
	static int	bin[8];
	int			idx;

	idx = 0;
	while (idx < 8)
	{
		bin[idx] = 0;
		idx++;
	}
	idx = 7;
	while (c > 0)
	{
		bin[idx] = c % 2;
		c = c / 2;
		idx--;
	}
	return (bin);
}

char	bin_to_decimal(int *bin)
{
	int	idx;
	int	result;
	int	pow;

	idx = 7;
	pow = 0;
	while (idx >= 0)
	{
		if (*(bin + idx) != 0)
			result = result + _power(2, pow);
		idx--;
		pow++;
	}
	return (result);
}

int main(int argc, char **argv)
{
    // int pid = atoi(argv[1]);


    // kill(pid, SIGINT);
    // printf("SIGINT sent to %d\n", pid);

	int *bin;
	int idx = 0;
	bin = char_con('A');
	
	char c = bin_to_decimal(bin);
	printf("%c\n", c);

    return 0;
}