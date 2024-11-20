/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:58:54 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/20 11:15:26 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_return(char *str)
{
	int	idx;
	int	count;

	count = 0;
	idx = 0;
	while (*(str + idx) != '\0')
	{
		if (str[idx] == '%')
			idx++;
		else if (str[idx] != '%')
			count++;
		idx++;
	}
	return (count);
}

size_t	_strlen(const char *s)
{
	size_t	count;

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

	count = 1;
	if (num == -2147483648)
		return (11);
	if (num == 2147483647)
		return (10);
	if (num < 0)
	{
		num = num * -1;
		count++;
	}
	if (num <= 9)
		return (count);
	div = 10;
	while ((num / div) > 0)
	{
		count++;
		div = div * 10;
	}
	return (count);
}
int main()
{
	printf("%d\n", _num_len(2147483646));
	return (0);
}