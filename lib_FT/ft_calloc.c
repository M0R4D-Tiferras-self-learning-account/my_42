/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:14:43 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/10 16:31:16 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			idx;
	char			*result;

	idx = 0;
	if (size != 0 && ((count * size) / size) != count)
		return (NULL);
	result = malloc(size * count);
	if (result == NULL)
		return (NULL);
	while (idx < (count * size))
	{
		result[idx] = 0;
		idx++;
	}
	return ((void *) result);
}
