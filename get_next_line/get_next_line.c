/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:23:26 by moutifer          #+#    #+#             */
/*   Updated: 2024/12/18 06:15:05 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	idx;
	char	*result;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	idx = 0;
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	while (idx < len)
	{
		result[idx] = s[start];
		idx++;
		start++;
	}
	result[idx] = '\0';
	return (result);
}

char	*_get_line(char *result)
{
	int		idx;
	char	*tmp;
	char	*line;

	idx = 0;
	while (result[idx] != '\0' && result[idx] != '\n')
		idx++;
	if (result[idx] != '\0' && result[idx] == '\n' && (idx + 1) < ft_strlen(result))
	{
		line = ft_substr(result, 0, idx + 1);
		tmp = ft_strchr(result, '\n');
		result = _free(result);
		result = ft_strdup(tmp + 1);
		return (line);
	}
	line = ft_substr(result, 0, idx);
	tmp = ft_strchr(result, '\n');
	result = _free(result);
	result = ft_strdup(tmp);
	return (line);
}

char	*_append(char *result, char *buffer, ssize_t read_it)
{
	if (result == NULL)
		result = "";
	result = ft_strjoin(result, buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	int				read_it;
	char			*buffer;
	static char		*result;
	char			*line;

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
		result = _append(result, buffer, read_it);
		if (ft_strchr(result, '\n') != NULL)
		{
			line = _get_line(result);
			printf("Result =%s\n", result);
			return (line);
		}
		return (result);
	}
}

int	main(void)
{
	int fd = open("test.txt", O_RDWR);

	printf("get_next_line--%s", get_next_line(fd));
	printf("\n---------\n");
	printf("get_next_line--%s", get_next_line(fd));
	return (0);
}