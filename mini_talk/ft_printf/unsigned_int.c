/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:19:36 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/24 21:32:32 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	unsigmed_num_len(unsigned int num)
{
	int	count;
	int	div;

	count = 0;
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

static void	handle_more(unsigned int n)
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

int	print_unsigned(unsigned int n)
{
	char	c;

	if (n <= 9)
	{
		c = n + '0';
		return (write(1, &c, 1));
	}
	handle_more(n);
	return (unsigmed_num_len(n));
}
