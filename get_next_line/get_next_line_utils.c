/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:20:25 by moutifer          #+#    #+#             */
/*   Updated: 2024/12/15 14:04:49 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	count_newline(char *str)
{
	size_t	idx;
	size_t	count;

	idx = 0;
	count = 0;
	if (str == NULL)
		return (0);
	while (str[idx] != '\0')
	{
		if (str[idx] == '\n')
			count++;
		idx++;
	}
	return (count);
}

void	_free(char *str)
{
	free(str);
	str = NULL;
}