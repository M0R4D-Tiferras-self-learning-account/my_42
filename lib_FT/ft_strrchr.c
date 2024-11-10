/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:10:15 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/10 13:06:20 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		idx;
	int		last_idx;
	char	c_cast;

	idx = 0;
	last_idx = -1;
	c_cast = (char) c;
	while (s[idx] != '\0')
	{
		if (s[idx] == c_cast)
		{
			last_idx = idx;
		}
		idx++;
	}
	if (c_cast == '\0')
	{
		return ((char *)(s + idx));
	}
	if (last_idx >= 0)
	{
		return ((char *)(s + last_idx));
	}
	return (NULL);
}
