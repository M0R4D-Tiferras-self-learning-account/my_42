/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:23:26 by moutifer          #+#    #+#             */
/*   Updated: 2024/12/12 20:57:26 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	call;
	int			read_it;
	char		*buffer;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	read_it = read(fd, buffer, BUFFER_SIZE);
	printf("%d\n", read_it);
	if (read_it == -1 || read_it == 0)
		return (NULL);
	call = 1;
	return ("");
}

int main(void)
{
	int fd = open("test.txt", O_RDWR);

	printf("%s\n", get_next_line(fd));
	return (0);
}