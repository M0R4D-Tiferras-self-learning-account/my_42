/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:26:46 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/18 20:48:48 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <libc.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	if (n == 0)
		return (0);
	idx = 0;
	while ((idx < (n - 1)) && s1[idx] && s2[idx] && s1[idx] == s2[idx])
	{
		idx++;
	}
	return (((unsigned char)(s1[idx])) - ((unsigned char)(s2[idx])));
}

// int main()
// {
// 	char *s = "hello";
// 	char *s2 = "hel";

// 	printf("%d\n", strncmp("hello", "", 5));
// 	printf("%d\n", ft_strncmp(s,s2, 5));
	
// 	return 0;
// }
