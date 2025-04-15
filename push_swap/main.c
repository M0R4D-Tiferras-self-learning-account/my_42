/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:58:35 by moutifer          #+#    #+#             */
/*   Updated: 2025/04/15 04:46:46 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sort_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 1 || is_sorted(stack_a))
		return ;
	else if (stack_a->size == 2)
	{
		if (stack_a->array[0] > stack_a->array[1])
			sa(stack_a, 1);
	}
	else if (stack_a->size == 3)
		sort_three(stack_a, stack_b);
	else if (stack_a->size <= 5)
		sort_five(stack_a, stack_b);
	else
		sort_large(stack_a, stack_b);
}

int	calculate_stack_size(int argc, char **argv)
{
	int		i;
	int		count;
	char	*str;

	if (argc == 2)
	{
		str = argv[1];
		count = 0;
		i = 0;
		while (str[i])
		{
			while (str[i] && str[i] == ' ')
				i++;
			if (str[i])
				count++;
			while (str[i] && str[i] != ' ')
				i++;
		}
		return (count);
	}
	return (argc - 1);
}

int	init_stacks(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	success;

	success = init_stack(stack_a, size);
	success = success && init_stack(stack_b, size);
	return (success);
}

int	handle_error(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(stack_a);
	free_stack(stack_b);
	return (1);
}

int	process_input(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	if (!parse_args(argc, argv, stack_a) || !check_duplicates(stack_a))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	
	stack_size = calculate_stack_size(argc, argv);
	if (stack_size == 0)
		return (0);
		
	if (!init_stacks(&stack_a, &stack_b, stack_size))
		return (handle_error(&stack_a, &stack_b));
	
	if (!process_input(argc, argv, &stack_a, &stack_b))
		return (handle_error(&stack_a, &stack_b));
	
	choose_sort_algorithm(&stack_a, &stack_b);
	
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
