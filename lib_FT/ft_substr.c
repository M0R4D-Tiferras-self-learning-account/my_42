/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:53:17 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/02 16:39:37 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	idx;
	char	*result;

	(void) len;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	idx = 0;
	result = malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	if (result == NULL)
		return (NULL);
	while (s[start] != '\0')
	{
		result[idx] = s[start];
		idx++;
		start++;
	}
	result[idx] = '\0';
	return (result);
}
