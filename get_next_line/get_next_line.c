/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:23:26 by moutifer          #+#    #+#             */
/*   Updated: 2024/12/18 03:21:02 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int				read_it;
	char			*buffer;
	static char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX || read(fd, NULL, 0) < 0)
		return (NULL);
	buffer = malloc(((size_t)(BUFFER_SIZE) + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (1 > 0)
	{
		read_it = read(fd, buffer, BUFFER_SIZE);
		if (read_it == -1 || read_it == 0)
			return (NULL);
		return ("line");
	}
	return (NULL);
}

int	main(void)
{
	int fd = open("test.txt", O_RDWR);

	printf("%s\n", get_next_line(fd));
	return (0);
}