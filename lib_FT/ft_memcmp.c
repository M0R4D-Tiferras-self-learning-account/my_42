/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:12:12 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/01 13:27:04 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				idx;
	const unsigned char	*str1;
	const unsigned char	*str2;

	idx = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (idx < n)
	{
		if (str1[idx] != str2[idx])
			return ((int)(str1[idx] - str2[idx]));
		idx++;
	}
	return (0);
}
