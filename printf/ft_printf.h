/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:47:17 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/23 05:11:46 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <libc.h>

int		printf_return(const char *str);
int		_strlen(const char *s);
int		_num_len(int num);
void	_putchar(char c);
void	_putstr(char *s);
void	_putnbr(int n);
int		ft_printf(const char *format, ...);
