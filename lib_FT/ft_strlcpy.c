/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:20:39 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/01 15:22:47 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_len(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	dst_idx;

	idx = 0;
	dst_idx = 0;
	while ((src[idx] != '\0') && (dst_idx < dstsize - 1))
	{
		dst[dst_idx] = src[idx];
		idx++;
		dst_idx++;
	}
	dst[dst_idx] = '\0';
	return (my_len(src));
}
