/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:58:54 by moutifer          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/11/28 12:09:19 by moutifer         ###   ########.fr       */
=======
/*   Updated: 2024/11/28 00:46:14 by moutifer         ###   ########.fr       */
>>>>>>> 52091a791f898e81e6ccccc428c3ce2c42884ded
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	_strlen(const char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
		return (6);
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

int	_putchar(char c)
{
	return (write(1, &c, 1));
}

int	_putstr(char *s)
{
	int	idx;
	int	count;

	idx = 0;
	count = 0;
	if (s == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (s[idx] != '\0')
	{
		write(1, &s[idx], 1);
		count++;
		idx++;
	}
	return (count);
}
