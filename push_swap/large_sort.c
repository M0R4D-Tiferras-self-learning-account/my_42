/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:41:46 by moutifer          #+#    #+#             */
/*   Updated: 2025/04/15 04:39:34 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Create a sorted copy of the stack for indexing */
void	create_sorted_array(t_stack *stack, int *sorted)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < stack->size)
	{
		sorted[i] = stack->array[i];
		i++;
	}
	i = 0;
	while (i < stack->size - 1)
	{
		j = 0;
		while (j < stack->size - i - 1)
		{
			if (sorted[j] > sorted[j + 1])
			{
				temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

/* Move stack elements to match a specific value */
void	move_element_to_top(t_stack *stack, int value, void (*rotate)(t_stack *, int),
                         void (*rev_rotate)(t_stack *, int))
{
	int	move;

	move = get_best_move(stack, value);
	if (move >= 0)
	{
		while (move-- > 0)
			rotate(stack, 1);
	}
	else
	{
		while (move++ < 0)
			rev_rotate(stack, 1);
	}
}

/* Push elements to stack B in chunks */
void	push_chunks_to_b(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int	*sorted;
	int	i;
	int	chunk;
	int	total_chunks;

	sorted = malloc(sizeof(int) * stack_a->size);
	if (!sorted)
		return ;
	create_sorted_array(stack_a, sorted);
	total_chunks = stack_a->size / chunk_size;
	if (stack_a->size % chunk_size != 0)
		total_chunks++;
	chunk = 0;
	while (chunk < total_chunks && stack_a->size > 0)
	{
		i = chunk * chunk_size;
		while (i < (chunk + 1) * chunk_size && i < stack_a->size && stack_a->size > 0)
		{
			move_element_to_top(stack_a, sorted[i], &ra, &rra);
			if (stack_a->size > 0 && stack_a->array[0] == sorted[i])
			{
				pb(stack_a, stack_b, 1);
				i++;
			}
		}
		chunk++;
	}
	free(sorted);
}

/* Push elements back from B to A in correct order */
void	push_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	max;
	int	min;

	while (stack_b->size > 0)
	{
		get_min_max(stack_b, &min, &max);
		move_element_to_top(stack_b, max, &rb, &rrb);
		pa(stack_a, stack_b, 1);
	}
}

/* Sort large stack using chunk method */
void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;

	if (stack_a->size <= 100)
		chunk_size = 20;
	else
		chunk_size = 40;
	push_chunks_to_b(stack_a, stack_b, chunk_size);
	push_back_to_a(stack_a, stack_b);
}
