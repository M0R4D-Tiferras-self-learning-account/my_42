/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:05:36 by moutifer          #+#    #+#             */
/*   Updated: 2024/10/29 15:56:51 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_over(size_t res, int s)
{
	if ((res >= 9223372036854775807) && s == 1)
		return (-1);
	if ((res == 9223372036854775807) && s == -1)
		return (1);
	if ((res > 9223372036854775807))
		return (0);
	else
		return (8);
}

int	ft_atoi(const char *str)
{
	int		idx;
	int		sign;
	size_t	result;

	idx = 0;
	sign = 1;
	result = 0;
	while ((str[idx] <= 32) && str[idx] != '\0')
	{
		idx++;
	}
	if ((str[idx] == '-'))
	{
		sign = -1;
		idx++;
	}
	while ((str[idx] != '\0') && (str[idx] >= '0' && (str[idx] <= '9')))
	{
		result = (result * 10) + (str[idx] - 48);
		if ((check_over(result, sign) == 1) || (check_over(result, sign) == -1)
			|| (check_over(result, sign) == 0))
			return (check_over(result, sign));
		idx++;
	}
	return (result * sign);
}
