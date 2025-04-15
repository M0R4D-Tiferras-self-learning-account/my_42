/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:58:32 by moutifer          #+#    #+#             */
/*   Updated: 2025/04/15 04:39:11 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Optimal sorting for exactly 3 numbers */
void	sort_three(t_stack *stack_a, t_stack *stack_b)
{
	int	a;
	int	b;
	int	c;

	(void)stack_b;
	if (is_sorted(stack_a))
		return ;
	a = stack_a->array[0];
	b = stack_a->array[1];
	c = stack_a->array[2];
	if (a > b && b < c && a < c)
		sa(stack_a, 1);
	else if (a > b && b < c && a > c)
		ra(stack_a, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a, 1);
	else if (a > b && b > c)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
}

/* Find smallest value in stack */
int	find_smallest(t_stack *stack)
{
	int	i;
	int	smallest;
	int	smallest_idx;

	smallest = stack->array[0];
	smallest_idx = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->array[i] < smallest)
		{
			smallest = stack->array[i];
			smallest_idx = i;
		}
		i++;
	}
	return (smallest_idx);
}

/* Moves the smallest value to the top of stack_a */
void	move_smallest_to_top(t_stack *stack_a)
{
	int	smallest_idx;
	int	moves;

	smallest_idx = find_smallest(stack_a);
	moves = get_best_move(stack_a, stack_a->array[smallest_idx]);
	if (moves >= 0)
	{
		while (moves--)
			ra(stack_a, 1);
	}
	else
	{
		while (moves++)
			rra(stack_a, 1);
	}
}

/* Sort exactly 5 numbers */
void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_a->size - 3;
	while (i--)
	{
		move_smallest_to_top(stack_a);
		pb(stack_a, stack_b, 1);
	}
	sort_three(stack_a, stack_b);
	while (stack_b->size > 0)
		pa(stack_a, stack_b, 1);
}
