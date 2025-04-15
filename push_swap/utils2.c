/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:53:34 by moutifer          #+#    #+#             */
/*   Updated: 2025/04/13 20:56:50 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_best_move(t_stack *stack, int target)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] == target)
			break ;
		i++;
	}
	if (i <= stack->size / 2)
		return (i);
	else
		return (i - stack->size);
}

/* Find position where num should be inserted in sorted stack */
int	find_position(t_stack *stack, int num, int *pos)
{
	int	i;
	int	min;
	int	max;

	get_min_max(stack, &min, &max);
	if (num < min || num > max)
	{
		*pos = get_best_move(stack, min);
		return (1);
	}
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] < num && stack->array[i + 1] > num)
		{
			*pos = i + 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str, int *error)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		*error = 1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			*error = 1;
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1 && (-result < INT_MIN)))
			*error = 1;
		i++;
	}
	return ((int)(result * sign));
}
