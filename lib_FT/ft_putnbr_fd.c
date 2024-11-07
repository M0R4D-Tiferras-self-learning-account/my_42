/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:18:12 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/07 19:37:02 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int num)
{
	int	div;
	int	count;

	div = 10;
	count = 1;
	while (num >= 10)
	{
		count++;
		num = num / div;
	}
	return (count);
}

static void handle_more(int n, int fd)
{
	int	div;

	div = 10 ^ (num_len(n) - 1);
	while (n >= 0)
	{
		write(fd, ((n / div) + '0'), 1);
		n = n / div;
		div = div / 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -1 * n;
		write(fd, '-', 1);
	}
	if (n <= 9)
	{
		write(fd, (n + '0'), 1);
		return ;
	}
	handle_more(n, fd)
}
