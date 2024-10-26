/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:10:15 by moutifer          #+#    #+#             */
/*   Updated: 2024/10/26 15:23:44 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	idx;
	int	last_idx;

	idx = 0;
	last_idx = -1;
	while (s[idx] != '\0')
	{
		if (s[idx] == c)
		{
			last_idx = idx;
		}
		idx++;
	}
	if (c == '\0')
	{
		return ((char *)(s + idx));
	}
	if (last_idx >= 0)
	{
		return ((char *)(s + last_idx));
	}
	return (NULL);
}
