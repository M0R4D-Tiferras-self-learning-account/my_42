/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:23:06 by moutifer          #+#    #+#             */
/*   Updated: 2025/03/12 14:34:51 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	g_count;

void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		g_count++;
	}
	else if (signum == SIGUSR2)
	{
		printf("%c", g_count);
		g_count = 0;
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
	ft_putstr("Waiting for messages ...\n");
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		//pause();
	}
	return (0);
}
