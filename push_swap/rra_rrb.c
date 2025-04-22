/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:37:53 by moutifer          #+#    #+#             */
/*   Updated: 2025/04/22 22:06:33 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *stack_a, t_stack *stack_b, int print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
