/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:47:45 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/10 12:56:17 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		idx;
	char	c_cast;

	c_cast = (char) c;
	idx = 0;
	while (*(s + idx) != '\0')
	{
		if (s[idx] == c_cast)
		{
			return ((char *)(s + idx));
		}
		idx++;
	}
	if ((s[idx] == '\0') && (c_cast == '\0'))
	{
		return ((char *)(s + idx));
	}
	return (NULL);
}

/*#include <string.h>
#include <stdio.h>

int main()
{
	printf("===%s===\n", strchr("teste", 357));
	printf("===%s===\n", ft_strchr("teste", 357));
}*/
