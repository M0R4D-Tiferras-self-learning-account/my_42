/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:50:14 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/10 16:03:52 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*sentence;
	size_t	idx;

	sentence = (char *) s;
	idx = 0;
	while ((idx < n))
	{
		sentence[idx] = 0;
		idx++;
	}
}
