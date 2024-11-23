/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:48:28 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/23 05:28:27 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_handler(char c, va_list args)
{
	int		return_sum;
	char	*str;
	int		n;

	return_sum = 0;
	n = 0;
	if (c == 'c')
	{
		_putchar((char) va_arg(args, int));
		return_sum++;
	}
	else if (c == 's')
	{
		str = va_arg(args, char *);
		_putstr(str);
		return_sum += _strlen(str);
	}
	else if (c == 'd')
	{
		n = va_arg(args, int);
		_putnbr(n);
		return_sum += _num_len(n);
	}
	else if (c == '%')
	{
		_putchar('%');
		return_sum++;
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
			_putchar(format[idx]);
		idx++;
	}
	va_end(args);
	return_sum += printf_return(format);
	return (return_sum);
}

int main()
{
	int r;
	r = ft_printf("%c%s%d%%\n", 'A', NULL, -1985);
	printf("\n%d\n", r);
	return 0;
}
