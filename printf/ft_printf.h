/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:47:17 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/24 17:53:45 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <libc.h>

int		_strlen(const char *s);
int		_putchar(char c);
int		_putstr(char *s);
int		_putnbr(int n);
int		print_unsigned(unsigned int n);
int		hexa_lower(int num);
int		hexa_upper(int num);
int		hexa_address(unsigned long int num);
int		ft_printf(const char *format, ...);
