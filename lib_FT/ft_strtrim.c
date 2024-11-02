/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:49:23 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/02 17:20:33 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	trim_count_Size(char const *str, char const *to_remove, size_t len)
{
	size_t	idx;
	size_t	count;
	size_t	checker;

	idx = 0;
	count = 0;
	checker = 1;
	while (str[idx] != '\0')
	{
		if (str[idx] != to_remove)
			count++;
		if (str[idx] <= 32)
			break ;
		idx++;
	}
	while ((len - 1) != idx)
	{
		if (str[len - 1] != to_remove)
			count++;
		if (str[len - 1] <= 32)
			break ;
		len--;
	}
	return ((count + 1 + 1));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	idx;
	char	*result;

	idx = 0;
	result = malloc(sizeof(char) * );
}