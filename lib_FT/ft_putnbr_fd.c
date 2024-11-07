/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:18:12 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/07 20:38:06 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	handle_more(int n, int fd)
{
	int		div;
	char	result;

	div = 10;
	while ((n / div) >= 10)
	{
		div = div * 10;
	}
	while (div > 0)
	{
		result = (((n / div)) + '0');
		write(fd, &result, 1);
		n = n % div;
		div = div / 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

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
		write(fd, "-", 1);
	}
	if (n <= 9)
	{
		c = n + '0';
		write(fd, &c, 1);
		return ;
	}
	handle_more(n, fd);
}
