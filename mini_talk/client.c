/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:02:55 by moutifer          #+#    #+#             */
/*   Updated: 2025/03/13 11:45:49 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

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

void	sender(char c, int pid)
{
	int	idx;
	int	*bin;

	idx = 0;
	bin = char_con(c);
	while (idx <= 7)
	{
		if (bin[idx] == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		idx++;
	}
}

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
		sender(argv[2][idx], pid);
		idx++;
	}
	ft_putstr("\n   Message sent\n");
	return (0);
}
