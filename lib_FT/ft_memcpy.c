/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:21:35 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/08 20:03:52 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				idx;
	unsigned char		*d;
	const unsigned char	*s;

	idx = 0;
	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	d = (unsigned char *)(dst);
	s = (const unsigned char *)(src);
	while (idx < n)
	{
		d[idx] = s[idx];
		idx++;
	}
	return (dst);
}
