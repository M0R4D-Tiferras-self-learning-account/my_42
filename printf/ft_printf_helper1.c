/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:58:54 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/23 05:49:29 by moutifer         ###   ########.fr       */
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

int	_num_len(int num)
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

int	printf_return(const char *str)
{
	int	idx;
	int	j;
	int	count;

	count = 0;
	idx = 0;
	while ((str[idx] != '\0'))
	{
		j = idx + 1;
		if (j < _strlen(str))
		{
			if (str[idx] == '%' && str[j] == '%')
			{
				count++;
				idx += 2;
				continue ;
			}
		}
		if (str[idx] == '%')
			idx++;
		else if (str[idx] != '%')
			count++;
		idx++;
	}
	return (count);
}

int	count_param(char *s)
{
	int	idx;
	int	count;
	int	j;

	idx = 0;
	count = 0;
	while (s[idx] != '\0' && s[idx +1] != '\0')
	{
		j = idx + 1;
		if ((s[j] == 'c' || s[j] == 's' || s[j] == 'p' || s[j] == 'd'
				|| s[j] == 'i' || s[j] == 'u' || s[j] == 'x'
				|| s[j] == 'X') && s[idx] == '%')
		{
			count++;
		}
		idx++;
	}
	return (count);
}
