/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:53:34 by moutifer          #+#    #+#             */
/*   Updated: 2025/04/16 09:25:38 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Get best move to bring a value to the top of the stack */
int	get_best_move(t_stack *stack, int target)
{
	int	i;
	int	position;

	position = -1;
	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] == target)
		{
			position = i;
			break;
		}
		i++;
	}
	
	if (position == -1)
		return (0);
		
	if (position <= stack->size / 2)
		return (position);
	else
		return (position - stack->size);
}

/* Find position where num should be inserted in sorted stack */
int	find_position(t_stack *stack, int num, int *pos)
{
	int	i;
	int	min;
	int	max;
	int	min_pos;

	get_min_max(stack, &min, &max);
	
	// If number is outside the min-max range
	if (num < min || num > max)
	{
		// Find position of min value
		i = 0;
		while (i < stack->size)
		{
			if (stack->array[i] == min)
			{
				min_pos = i;
				break;
			}
			i++;
		}
		*pos = min_pos;
		return (1);
	}
	
	// Find position where num should be inserted
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
	
	// Handle edge case
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] > stack->array[i + 1])
		{
			if (num > stack->array[i] || num < stack->array[i + 1])
			{
				*pos = i + 1;
				return (1);
			}
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
