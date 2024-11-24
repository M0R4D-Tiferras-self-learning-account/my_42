/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:58:54 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/24 19:57:59 by moutifer         ###   ########.fr       */
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
		if (write(1, &s[idx], 1) < 0)
			return (-1);
		count++;
		idx++;
	}
	return (count);
}
