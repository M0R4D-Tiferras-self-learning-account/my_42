/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:48:01 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/01 18:00:08 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		idx;

	result = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (result == NULL)
		return (NULL);
	idx = 0;
	while (s1[idx] != '\0')
	{
		result[idx] = s1[idx];
		idx++;
	}
	result[idx] = '\0';
	return (result);
}
