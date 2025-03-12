/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:02:55 by moutifer          #+#    #+#             */
/*   Updated: 2025/03/12 14:33:42 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	main(int argc, char **argv)
{
	int	pid;
	int	idx;
	int	ascii_value;

	if (argc != 3)
	{
		ft_putstr("+++Error+++\n./client [PID] MESSAGE\n");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	idx = 0;
	ascii_value = 1;
	while (argv[2][idx] != '\0')
	{
		while (ascii_value <= argv[2][idx])
		{
			kill(pid, SIGUSR1);
			usleep(100);
			ascii_value++;
		}
		ascii_value = 1;
		usleep(100);
		kill(pid, SIGUSR2);
		idx++;
	}
	ft_putstr("\n   Message sent\n");
	return (0);
}
