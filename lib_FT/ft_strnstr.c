/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:33:25 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/01 14:44:29 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_len(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	needle_idx;
	size_t	restore_idx;

	idx = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (idx < len && (haystack[idx] != '\0'))
	{
		needle_idx = 0;
		restore_idx = idx;
		while (haystack[restore_idx] == needle[needle_idx])
		{
			if (needle[_len(needle) - 1] == haystack[restore_idx])
				return ((char *)(haystack + idx));
			needle_idx++;
			restore_idx++;
		}
		idx++;
	}
	return (NULL);
}
