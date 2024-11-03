/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:53:17 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/03 13:22:51 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	idx;
	char	*result;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	idx = 0;
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	while (idx < len)
	{
		result[idx] = s[start];
		idx++;
		start++;
	}
	result[idx] = '\0';
	return (result);
}
