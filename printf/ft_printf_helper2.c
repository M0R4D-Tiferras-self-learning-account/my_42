/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 02:37:21 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/23 03:36:10 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	_putchar(char c)
{
	write(1, &c, 1);
}

void	_putstr(char *s)
{
	int	idx;

	idx = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (s[idx] != '\0')
	{
		write(1, &s[idx], 1);
		idx++;
	}
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

void	_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -1 * n;
		write(1, "-", 1);
	}
	if (n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
		return ;
	}
	handle_more(n);
}