/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:33:25 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/10 16:21:03 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	_len(const char *str)
{
	size_t	count;

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

	idx = 0;
	if (!haystack && !needle)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while ((idx < len) && (haystack[idx] != '\0'))
	{
		needle_idx = 0;
		while (haystack[idx + needle_idx] == needle[needle_idx]
			&& (idx + needle_idx < len) && haystack[idx] != '\0')
		{
			if (needle[_len(needle) - 1] == haystack[idx + needle_idx]
				&& (needle[needle_idx + 1] == '\0'))
				return ((char *)(haystack + idx));
			needle_idx++;
		}
		idx++;
	}
	return (NULL);
}
