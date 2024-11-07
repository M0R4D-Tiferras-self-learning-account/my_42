/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:49:43 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/07 17:59:09 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	idx;

	if (s == NULL)
		return ;
	idx = 0;
	while (s[idx] != '\0')
	{
		write(fd, &s[idx], 1);
		idx++;
	}
	write(fd, "\n", 1);
}
