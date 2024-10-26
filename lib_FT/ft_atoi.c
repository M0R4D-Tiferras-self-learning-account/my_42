/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:05:36 by moutifer          #+#    #+#             */
/*   Updated: 2024/10/26 17:21:18 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	idx;
	int	sign;
	int	result;

	idx = 0;
	sign = 1;
	result = 0;
	while ((str[idx] <= 32) && str[idx] != '\0')
	{
		idx++;
	}
	if ((str[idx] == '+') || (str[idx] == '-'))
	{
		if (str[idx] == '-')
		{
			sign = -1;
		}
		idx++;
	}
	while ((str[idx] != '\0') && (str[idx] >= '0' && (str[idx] <= '9')))
	{
		result = (result * 10) + (str[idx] - 48);
		idx++;
	}
	return (result * sign);
}
