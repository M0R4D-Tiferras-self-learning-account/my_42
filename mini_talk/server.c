/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:23:06 by moutifer          #+#    #+#             */
/*   Updated: 2025/03/13 12:01:22 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	_putchar(char c)
{
	write(1, &c, 1);
}

static void	_reset(int *binary)
{
	int	idx;

	idx = 0;
	while (idx < 8)
	{
		*(binary + idx) = 0;
		idx++;
	}
}

void	handler(int signum)
{
	static int	bin[8];
	static int	idx = 0;
	char		c;

	if (signum == SIGUSR1)
		bin[idx] = 1;
	else if (signum == SIGUSR2)
		bin[idx] = 0;
	idx++;
	if (idx == 8)
	{
		c = bin_to_decimal(bin);
		_putchar(c);
		_reset(bin);
		idx = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 1)
	{
		ft_putstr("Wrong Execution Format\n No argument needed for the server\n");
		exit(1);
	}
	pid = getpid();
	printf("====================\n The Server PID = %d\n", pid);
	ft_putstr("\n====================\n");
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	ft_putstr("Waiting for messages ...\n");
	while (1)
	{
		pause();
	}
	return (0);
}
