/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:41:46 by moutifer          #+#    #+#             */
/*   Updated: 2025/04/22 22:10:29 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_closest_element(t_stack *stack, int *sorted, int chunk_start,
		int chunk_end)
{
	int	i;
	int	j;
	int	min_dist;
	int	current_dist;
	int	closest_value;
	int	position;

	min_dist = stack->size;
	closest_value = -1;
	j = chunk_start;
	while (j < chunk_end && j < stack->size)
	{
		i = 0;
		while (i < stack->size)
		{
			if (stack->array[i] == sorted[j])
			{
				if (i <= stack->size / 2)
					current_dist = i;
				else
					current_dist = stack->size - i;
				if (current_dist < min_dist)
				{
					min_dist = current_dist;
					closest_value = sorted[j];
					position = i;
				}
				break ;
			}
			i++;
		}
		j++;
	}
	return (closest_value);
}

void	move_element_to_top(t_stack *stack, int value, void (*rotate)(t_stack *,
			int), void (*rev_rotate)(t_stack *, int))
{
	int	i;
	int	position;

	position = -1;
	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] == value)
		{
			position = i;
			break ;
		}
		i++;
	}
	if (position == -1)
		return ;
	if (position <= stack->size / 2)
	{
		while (position > 0)
		{
			rotate(stack, 1);
			position--;
		}
	}
	else
	{
		while (position < stack->size)
		{
			rev_rotate(stack, 1);
			position++;
		}
	}
}

void	push_chunks_to_b(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int	*sorted;
	int	chunk;
	int	total_chunks;
	int	chunk_start;
	int	chunk_end;
	int	target;
	int	original_size;

	sorted = malloc(sizeof(int) * stack_a->size);
	if (!sorted)
		return ;
	original_size = stack_a->size;
	create_sorted_array(stack_a, sorted);
	total_chunks = (original_size + chunk_size - 1) / chunk_size;
	chunk = 0;
	while (chunk < total_chunks && stack_a->size > 0)
	{
		chunk_start = chunk * chunk_size;
		chunk_end = (chunk + 1) * chunk_size;
		if (chunk_end > original_size)
			chunk_end = original_size;
		while (stack_a->size > 0 && chunk_start < chunk_end)
		{
			target = find_closest_element(stack_a, sorted, chunk_start,
					chunk_end);
			if (target == -1)
				break ;
			move_element_to_top(stack_a, target, &ra, &rra);
			pb(stack_a, stack_b, 1);
			for (int i = chunk_start; i < chunk_end; i++)
			{
				if (sorted[i] == target)
				{
					sorted[i] = INT_MIN;
					chunk_start++;
					break ;
				}
			}
		}
		chunk++;
	}
	free(sorted);
}

int	find_best_element_to_push(t_stack *stack_b)
{
	int	i;
	int	max;
	int	min;
	int	best_cost;
	int	current_cost;
	int	best_value;
	int	position;

	get_min_max(stack_b, &min, &max);
	best_cost = stack_b->size;
	best_value = max;
	i = 0;
	while (i < stack_b->size)
	{
		position = i;
		if (position > stack_b->size / 2)
			current_cost = stack_b->size - position;
		else
			current_cost = position;
		if (current_cost < best_cost)
		{
			best_cost = current_cost;
			best_value = stack_b->array[i];
		}
		else if (current_cost == best_cost && stack_b->array[i] > best_value)
		{
			best_value = stack_b->array[i];
		}
		i++;
	}
	return (best_value);
}

void	push_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	target;
		int min;
		int max;

	while (stack_b->size > 0)
	{
		target = find_best_element_to_push(stack_b);
		move_element_to_top(stack_b, target, &rb, &rrb);
		pa(stack_a, stack_b, 1);
		if (stack_a->size > 1
			&& stack_a->array[0] > stack_a->array[stack_a->size - 1]
			&& stack_a->array[0] > stack_a->array[1])
		{
			ra(stack_a, 1);
		}
	}
	if (!is_sorted(stack_a))
	{
		get_min_max(stack_a, &min, &max);
		move_element_to_top(stack_a, min, &ra, &rra);
	}
}

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;

	if (stack_a->size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	push_chunks_to_b(stack_a, stack_b, chunk_size);
	push_back_to_a(stack_a, stack_b);
}
