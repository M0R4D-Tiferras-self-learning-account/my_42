/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:26:46 by moutifer          #+#    #+#             */
/*   Updated: 2024/10/26 16:59:25 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while ((s1[idx] != '\0') && (s2[idx] != '\0') && (s1[idx] == s2[idx])
		&& (idx < n))
	{
		idx++;
	}
	return (((unsigned char)(s1[idx])) - ((unsigned char)(s2[idx])));
}
