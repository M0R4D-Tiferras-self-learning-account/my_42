/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:29:13 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/23 22:55:11 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_num_len(int num)
{
	int	count;
	int	div;

	count = 0;
	if (num == -2147483648)
		return (11);
	if (num < 0)
	{
		num = num * -1;
		count++;
	}
	if (num <= 9)
	{
		count++;
		return (count);
	}
	div = 10;
	while (num > 0)
	{
		count++;
		num = num / div;
	}
	return (count);
}

static void	handle_more(int n)
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
		write(1, &result, 1);
		n = n % div;
		div = div / 10;
	}
}

int	_putnbr(int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (n < 0)
	{
		n = -1 * n;
		write(1, "-", 1);
		count++;
	}
	if (n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
		count++;
		return (count);
	}
	handle_more(n);
	return (_num_len(n));
}
