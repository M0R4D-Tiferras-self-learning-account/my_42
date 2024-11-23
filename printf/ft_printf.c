/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:48:28 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/23 03:41:55 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		return_sum;
	int		idx;
	va_list	args;

	return_sum = 0;
	idx = 0;
	va_start(args, format);
	while(format[idx] != '\0')
	{
		if (format[idx + 1] != '\0' && format[idx] == '%')
		{
			if (format[idx + 1] == 'c')
				_putchar((char) va_arg(args, int));
			if (format[idx + 1] == 's')
				_putstr(va_arg(args, char *));
			if (format[idx + 1] == 'd')
				_putnbr(va_arg(args, int));
			idx++;
		}
		else if (format[idx] != '%')
			_putchar(format[idx]);
		idx++;
	}
	va_end(args);
	return (return_sum);
}

int main()
{
	ft_printf("hi hello l%calaam  %s  %d  \n", '3', NULL, 1985);
	return 0;
}
