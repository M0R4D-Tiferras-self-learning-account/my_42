/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:20:59 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/10 16:21:08 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		idx;
	char		*result;

	if (s == NULL || f == NULL)
		return (NULL);
	idx = 0;
	result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (result == NULL)
		return (NULL);
	while (idx < ft_strlen(s))
	{
		result[idx] = (*f)(idx, s[idx]);
		idx++;
	}
	result[idx] = '\0';
	return (result);
}
