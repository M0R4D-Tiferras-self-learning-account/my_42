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

static char	*update_result(char **result)
{
	size_t	idx;
	char	*tmp_result;

	idx = 0;
	while ((*result) != NULL && (*result)[idx] != '\0' && (*result)[idx] != '\n')
		idx++;
	if ((*result)[idx] == '\0')
	{
		free((*result));
		return (NULL);
	}
	if (((*result)[idx] == '\n') && (size_t)(idx + 1) <= ft_strlen((*result)))
		tmp_result = ft_strdup(&(*result)[idx + 1]);
	else
		tmp_result = ft_strdup(&(*result)[idx]);
	if (tmp_result == NULL)
	{
		free(*(result));
		*(result) = NULL;
		return (NULL);
	}
	free(*(result));
	*(result) = tmp_result;
	return (tmp_result);
}

char	*_get_line(char *result)
{
	int		idx;
	char	*line;

	idx = 0;
	if (result == NULL)
		return (NULL);
	while (result != NULL && result[idx] != '\0' && result[idx] != '\n')
		idx++;
	if (idx == 0 && result[idx] == '\n')
		return (ft_strdup("\n"));
	if (idx == 0)
		return (result);
	if (result[idx] == '\n' && (size_t)(idx + 1) <= ft_strlen(result))
		line = ft_substr(result, 0, idx + 1);
	else
		line = ft_substr(result, 0, idx);
	if (line[0] == '\0')
	{
		free(line);
		return(NULL);
	}
	return (line);
}

char	*_append(char **result, char *buffer, ssize_t read_it)
{
	char	*new_result;

	buffer[read_it] = '\0';
	new_result = ft_strjoin(*result, buffer);
	if (new_result == NULL)
		return (free(new_result), free(*result), NULL);
	if (*result != NULL)
		free(*result);
	return (new_result);
}

char	*get_next_line(int fd)
{
	int				read_it;
	char			*buffer;
	static char		*result = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX || read(fd, NULL, 0) < 0)
		return (NULL);
	buffer = malloc(((size_t)(BUFFER_SIZE) + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (1 > 0)
	{
		read_it = read(fd, buffer, BUFFER_SIZE);
		if (read_it == 0 || read_it == -1)
			break ;
		result = _append(&result, buffer, read_it);
		if (ft_strchr(result, '\n') != NULL)
			break ;
	}
	free(buffer);
	buffer = NULL;
	if (read_it == -1 || result == NULL)
		return (free(result), result = NULL, NULL);
	line = _get_line(result);
	if ((line[0] == '\0' || line == NULL) && read_it == 0)
		return (free(result), result = NULL, NULL);
	if (line[0] == '\0')
        return (free(result), result = NULL, NULL);
	result = update_result(&result);
	return (line);
}

 int	main(void)
 {
 	int fd = open("test.txt", O_RDWR);

 	char *s = get_next_line(fd);
 	printf("--%s--", s);
 	free(s);
	s = get_next_line(fd);
	printf("--%s--", s);
 	free(s);
	s = get_next_line(fd);
	printf("--%s--", s);
 	free(s);
	s = get_next_line(fd);
	printf("--%s--", s);
 	free(s);
	s = get_next_line(fd);
	printf("--%s--", s);
 	free(s);
	s = get_next_line(fd);
	printf("--%s--", s);
 	free(s);
	s = get_next_line(fd);
	printf("--%s--", s);
 	free(s);
	s = get_next_line(fd);
	printf("--%s--", s);
 	free(s);

	printf("\n-----\n");
	close(fd);
 	return (0);
 }
