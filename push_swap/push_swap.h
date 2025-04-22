/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:58:25 by moutifer          #+#    #+#             */
/*   Updated: 2025/04/22 22:06:23 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*array;
	int	size;
}		t_stack;

void	sa(t_stack *stack_a, int print);
void	sb(t_stack *stack_b, int print);
void	ss(t_stack *stack_a, t_stack *stack_b, int print);
void	pa(t_stack *stack_a, t_stack *stack_b, int print);
void	pb(t_stack *stack_a, t_stack *stack_b, int print);
void	ra(t_stack *stack_a, int print);
void	rb(t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b, int print);
void	rra(t_stack *stack_a, int print);
void	rrb(t_stack *stack_b, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b, int print);
int		ft_atoi(const char *str, int *error);
void	ft_putstr_fd(char *s, int fd);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack *stack);
int		init_stack(t_stack *stack, int size);
char	**ft_split(char const *s);
char	*ft_strdup(const char *s);
void	free_split(char **split);
int		parse_args(int argc, char **argv, t_stack *stack_a);
int		check_duplicates(t_stack *stack);
int		parse_string_args(char *str, t_stack *stack_a);
void	sort_three(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	sort_large(t_stack *stack_a, t_stack *stack_b);
void	push_chunks_to_b(t_stack *stack_a, t_stack *stack_b, int chunk_size);
void	get_min_max(t_stack *stack, int *min, int *max);
int		get_best_move(t_stack *stack, int target);
int		find_position(t_stack *stack, int num, int *pos);
void	push_back_to_a(t_stack *stack_a, t_stack *stack_b);
void	create_sorted_array(t_stack *stack, int *sorted);
int		find_closest_element(t_stack *stack, int *sorted, int chunk_start,
			int chunk_end);
void	move_element_to_top(t_stack *stack, int value, void (*rotate)(t_stack *,
				int), void (*rev_rotate)(t_stack *, int));
int		find_best_element_to_push(t_stack *stack_b);

#endif
