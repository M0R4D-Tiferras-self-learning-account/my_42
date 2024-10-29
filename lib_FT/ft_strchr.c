/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:47:45 by moutifer          #+#    #+#             */
/*   Updated: 2024/10/26 15:07:38 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	idx;

	idx = 0;
	while (*(s + idx) != '\0')
	{
		if (s[idx] == c)
		{
			return ((char *)(s + idx));
		}
		idx++;
	}
	if ((s[idx] == '\0') && (c == '\0'))
	{
		return ((char *)(s + idx));
	}
	return (NULL);
}
