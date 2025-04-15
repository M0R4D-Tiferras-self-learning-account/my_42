/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:58:41 by moutifer          #+#    #+#             */
/*   Updated: 2025/04/13 20:52:34 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	if (stack && stack->array)
		free(stack->array);
	stack->size = 0;
}

int	init_stack(t_stack *stack, int size)
{
	stack->array = malloc(sizeof(int) * size);
	if (!stack->array)
		return (0);
	stack->size = 0;
	return (1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	get_min_max(t_stack *stack, int *min, int *max)
{
	int	i;

	*min = stack->array[0];
	*max = stack->array[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->array[i] < *min)
			*min = stack->array[i];
		if (stack->array[i] > *max)
			*max = stack->array[i];
		i++;
	}
}
