/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:44:06 by moutifer          #+#    #+#             */
/*   Updated: 2025/03/12 14:00:01 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		write(1, &str[idx], 1);
		idx++;
	}
}

static int	check_over(size_t res, int s)
{
	if ((res >= 9223372036854775807) && s == 1)
		return (-1);
	if ((res == 9223372036854775807) && s == -1)
		return (1);
	if ((res > 9223372036854775807))
		return (0);
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
	while (str[idx] == ' ' || (str[idx] >= 9 && str[idx] <= 13))
	{
		idx++;
	}
	if ((str[idx] == '-' || str[idx] == '+'))
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while ((str[idx] != '\0') && (str[idx] >= '0' && (str[idx] <= '9')))
	{
		result = (result * 10) + (str[idx] - 48);
		if ((check_over(result, sign)) != 8)
			return (check_over(result, sign));
		idx++;
	}
	return (result * sign);
}
