/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:23:26 by moutifer          #+#    #+#             */
/*   Updated: 2024/12/18 20:29:59 by moutifer         ###   ########.fr       */
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
	char	*tmp_result;
	char	*line;

	idx = 0;
	while (result[idx] != '\0' && result[idx] != '\n')
		idx++;
	if (result[idx] != '\0' && result[idx] == '\n' && (size_t)(idx + 1) <= ft_strlen(result))
	{
		line = ft_strdup(ft_substr(result, 0, idx + 1));
		tmp_result = ft_strdup(&result[idx + 1]);
	}
	else
	{
		line = ft_substr(result, 0, idx);
		tmp_result = ft_strdup(&result[idx]);
	}
	result = _free(result);
	result = ft_strdup(tmp_result);
	tmp_result = _free(tmp_result);
	return (line);
}

char	*_append(char *result, char *buffer, ssize_t read_it)
{
	char	*new_result;

	buffer[read_it] = '\0';
	new_result = ft_strjoin(result, buffer);
	result = _free(result);
	return (new_result);
}

char	*get_next_line(int fd)
{
	int				read_it;
	char			*buffer;
	static char		*result;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = malloc(((size_t)(BUFFER_SIZE) + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (1 > 0)
	{
		read_it = read(fd, buffer, BUFFER_SIZE);
		if (read_it == -1)
			return (NULL);
		if (read_it == 0)
			break ;
		result = _append(result, buffer, read_it);
		if (ft_strchr(result, '\n') != NULL)
			break ;
	}
	buffer = _free(buffer);
	line = _get_line(result);
	if (line[0] == '\0')
	{
		result = _free(result);
		line = _free(line);
		return (NULL);
	}
	return (line);
}

// int	main(void)
// {
// 	int fd = open("test.txt", O_RDWR);

// 	char *s = get_next_line(fd);
// 	printf("-->%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("-->%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("-->%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("-->%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("-->%s", s);
// 	free(s);

// 	return (0);
// }