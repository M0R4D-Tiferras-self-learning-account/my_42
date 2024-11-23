/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:48:28 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/23 23:09:13 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_handler(char c, va_list args)
{
	int		return_sum;

	return_sum = 0;
	if (c == 'c')
	{
		return_sum += _putchar((char) va_arg(args, int));
	}
	else if (c == 's')
	{
		return_sum += _putstr(va_arg(args, char *));
	}
	else if (c == 'd' || c == 'i')
	{
		return_sum += _putnbr(va_arg(args, int));
	}
	else if (c == 'u')
	{
		return_sum += print_unsigned(va_arg(args, unsigned int));
	}
	else if (c == '%')
	{
		return_sum += _putchar('%');
	}
	return (return_sum);
}

int	ft_printf(const char *format, ...)
{
	int		return_sum;
	int		idx;
	va_list	args;

	return_sum = 0;
	idx = 0;
	va_start(args, format);
	while (format[idx] != '\0')
	{
		if (format[idx + 1] != '\0' && format[idx] == '%')
		{
			return_sum += printf_handler(format[idx + 1], args);
			idx++;
		}
		else if (format[idx] != '%')
			return_sum += _putchar(format[idx]);
		idx++;
	}
	va_end(args);
	return (return_sum);
}

int main()
{
	int r;
	r = ft_printf("%d", -10);
	printf("%d\n", r);
	return 0;
}
