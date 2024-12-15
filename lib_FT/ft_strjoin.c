/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:23:21 by moutifer          #+#    #+#             */
/*   Updated: 2024/12/15 14:41:29 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	result_idx;
	size_t	idx;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	result_idx = 0;
	while (s1[result_idx] != '\0')
	{
		result[result_idx] = s1[result_idx];
		result_idx++;
	}
	idx = 0;
	while (s2[idx] != '\0')
	{
		result[result_idx] = s2[idx];
		result_idx++;
		idx++;
	}
	result[result_idx] = '\0';
	return (result);
}
