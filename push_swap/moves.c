/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:33:57 by moutifer          #+#    #+#             */
/*   Updated: 2025/04/15 04:37:46 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sa: swap the first 2 elements of stack a */
void	sa(t_stack *stack_a, int print)
{
	int	temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->array[0];
	stack_a->array[0] = stack_a->array[1];
	stack_a->array[1] = temp;
	if (print)
		ft_putstr_fd("sa\n", 1);
}

/* sb: swap the first 2 elements of stack b */
void	sb(t_stack *stack_b, int print)
{
	int	temp;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->array[0];
	stack_b->array[0] = stack_b->array[1];
	stack_b->array[1] = temp;
	if (print)
		ft_putstr_fd("sb\n", 1);
}

/* ss: sa and sb at the same time */
void	ss(t_stack *stack_a, t_stack *stack_b, int print)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print)
		ft_putstr_fd("ss\n", 1);
}

/* pa: push top element from b to a */
void	pa(t_stack *stack_a, t_stack *stack_b, int print)
{
	int	i;

	if (stack_b->size == 0)
		return ;
	i = stack_a->size;
	while (i > 0)
	{
		stack_a->array[i] = stack_a->array[i - 1];
		i--;
	}
	stack_a->array[0] = stack_b->array[0];
	stack_a->size++;
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->array[i] = stack_b->array[i + 1];
		i++;
	}
	stack_b->size--;
	if (print)
		ft_putstr_fd("pa\n", 1);
}

/* pb: push top element from a to b */
void	pb(t_stack *stack_a, t_stack *stack_b, int print)
{
	int	i;

	if (stack_a->size == 0)
		return ;
	i = stack_b->size;
	while (i > 0)
	{
		stack_b->array[i] = stack_b->array[i - 1];
		i--;
	}
	stack_b->array[0] = stack_a->array[0];
	stack_b->size++;
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->array[i] = stack_a->array[i + 1];
		i++;
	}
	stack_a->size--;
	if (print)
		ft_putstr_fd("pb\n", 1);
}
