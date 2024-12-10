/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:47:17 by moutifer          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/11/28 12:07:36 by moutifer         ###   ########.fr       */
=======
/*   Updated: 2024/11/27 19:50:12 by moutifer         ###   ########.fr       */
>>>>>>> 52091a791f898e81e6ccccc428c3ce2c42884ded
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		_strlen(const char *s);
int		_putchar(char c);
int		_putstr(char *s);
int		_putnbr(int n);
int		print_unsigned(unsigned int n);
int		hexa_lower(int num);
int		hexa_upper(int num);
int		hexa_address(unsigned long int num);
int		ft_printf(const char *format, ...);

#endif
