/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:34:47 by moutifer          #+#    #+#             */
/*   Updated: 2025/04/22 22:04:37 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a, int print)
{
	int	temp;
	int	i;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->array[0];
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->array[i] = stack_a->array[i + 1];
		i++;
	}
	stack_a->array[stack_a->size - 1] = temp;
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack_b, int print)
{
	int	temp;
	int	i;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->array[0];
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->array[i] = stack_b->array[i + 1];
		i++;
	}
	stack_b->array[stack_b->size - 1] = temp;
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b, int print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print)
		ft_putstr_fd("rr\n", 1);
}

void	rra(t_stack *stack_a, int print)
{
	int	temp;
	int	i;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->array[stack_a->size - 1];
	i = stack_a->size - 1;
	while (i > 0)
	{
		stack_a->array[i] = stack_a->array[i - 1];
		i--;
	}
	stack_a->array[0] = temp;
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack_b, int print)
{
	int	temp;
	int	i;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->array[stack_b->size - 1];
	i = stack_b->size - 1;
	while (i > 0)
	{
		stack_b->array[i] = stack_b->array[i - 1];
		i--;
	}
	stack_b->array[0] = temp;
	if (print)
		ft_putstr_fd("rrb\n", 1);
}
