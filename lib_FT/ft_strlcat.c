/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:24:42 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/01 16:38:03 by moutifer         ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	source_idx;
	size_t	dst_idx;
	size_t	restore_dst_len;

	if (((my_len(dst) >= dstsize)))
		return (my_len(dst) + my_len(src));
	source_idx = 0;
	dst_idx = my_len(dst);
	restore_dst_len = my_len(dst);
	while (src[source_idx] != '\0' && (dst_idx < dstsize - 1))
	{
		dst[dst_idx] = src[source_idx];
		dst_idx++;
		source_idx++;
	}
	dst[dst_idx] = '\0';
	return (restore_dst_len + my_len(src));
}
