/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:22:36 by moutifer          #+#    #+#             */
/*   Updated: 2024/10/30 22:06:33 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			idx;
	unsigned char	*to_cast;

	idx = 0;
	to_cast = (unsigned char *)(b);
	while (idx < len)
	{
		to_cast[idx] = (unsigned char) c;
		idx++;
	}
	return (b);
}
