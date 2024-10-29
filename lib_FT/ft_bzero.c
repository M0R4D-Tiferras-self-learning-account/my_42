/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:50:14 by moutifer          #+#    #+#             */
/*   Updated: 2024/10/29 17:08:56 by moutifer         ###   ########.fr       */
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
		sentence[idx] = '\0';
		idx++;
	}
}
