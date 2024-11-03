/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:49:23 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/03 13:29:11 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim_check(char const *set, char caracter)
{
	size_t	idx;

	idx = 0;
	while (set[idx] != '\0')
	{
		if (set[idx] == caracter)
			return (1);
		idx++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (trim_check(set, s1[start]) == 1)
	{
		start++;
	}
	while (trim_check(set, s1[end]) == 1)
	{
		end--;
	}
	return (ft_substr(s1, start, (end - start + 1)));
}
