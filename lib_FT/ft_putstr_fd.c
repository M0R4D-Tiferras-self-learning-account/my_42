/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:44:01 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/07 17:47:53 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
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
}
