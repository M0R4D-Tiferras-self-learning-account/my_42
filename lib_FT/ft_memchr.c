/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:37:15 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/01 13:09:50 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				idx;
	unsigned char		to_find;
	const unsigned char	*str;

	idx = 0;
	to_find = (unsigned char) c;
	str = (const unsigned char *) s;
	while (idx < n)
	{
		if (str[idx] == to_find)
			return ((void *)(s + idx));
		idx++;
	}
	return (NULL);
}
