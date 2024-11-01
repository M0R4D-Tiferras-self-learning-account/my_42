/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 03:39:40 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/01 11:35:23 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				idx;
	unsigned char		*d;
	const unsigned char	*s;

	idx = 0;
	d = (unsigned char *)(dst);
	s = (const unsigned char *)(src);
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
		return (dst);
	}
	while (idx < len)
	{
		d[idx] = s[idx];
		idx++;
	}
	return (dst);
}
