/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:23:26 by moutifer          #+#    #+#             */
/*   Updated: 2024/12/21 10:23:10 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*update_result(char **result)
{
	size_t	idx;
	char	*tmp_result;

	idx = 0;
	while ((*result) != NULL && (*result)[idx] != '\0'
		&& (*result)[idx] != '\n')
		idx++;
	if ((*result)[idx] == '\0')
	{
		free((*result));
		(*result) = NULL;
		return (NULL);
	}
	if (((*result)[idx] == '\n') && (size_t)(idx + 1) <= ft_strlen((*result)))
		tmp_result = ft_strdup(&(*result)[idx + 1]);
	else
		tmp_result = ft_strdup(&(*result)[idx]);
	free(*(result));
	*(result) = NULL;
	if (tmp_result == NULL)
		return (NULL);
	*(result) = tmp_result;
	return ((*result));
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
	if (idx == 0 && result[idx] == '\0')
		return (result);
	if (result[idx] == '\n' && (size_t)(idx + 1) <= ft_strlen(result))
		line = ft_substr(result, 0, idx + 1);
	else
		line = ft_substr(result, 0, idx);
	if (line[0] == '\0')
	{
		free (line);
		return (NULL);
	}
	return (line);
}

char	*_append(char **result, char *buffer, ssize_t read_it)
{
	char	*new_result;

	buffer[read_it] = '\0';
	new_result = ft_strjoin(*result, buffer);
	if (new_result == NULL)
		return (free(new_result), free(*result), (*result) = NULL, NULL);
	if (*result != NULL)
		free(*result);
	return (new_result);
}

static char	*_malloc(int buff_size, char **buffer)
{
	*buffer = malloc(((size_t)(buff_size) + 1) * sizeof(char));
	if (!*buffer)
		return (NULL);
	return (*buffer);
}

char	*get_next_line(int fd)
{
	int				read_it;
	char			*buffer;
	static char		*result;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = _malloc(BUFFER_SIZE, &buffer);
	read_it = read(fd, buffer, BUFFER_SIZE);
	while (read_it > 0)
	{
		result = _append(&result, buffer, read_it);
		if (ft_strchr(result, '\n') != NULL)
			break ;
		read_it = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	buffer = NULL;
	if (read_it == -1 || result == NULL)
		return (free(result), result = NULL, NULL);
	line = _get_line(result);
	if ((line[0] == '\0' || line == NULL) && read_it == 0)
		return (free(result), result = NULL, NULL);
	result = update_result(&result);
	return (line);
}

//   int	main(void)
//   {
//   	int fd = open("test.txt", O_RDWR);

//   	char *s = get_next_line(fd);
//   	printf("Line = %s", s);
//   	free(s);
//  	s = get_next_line(fd);
//  	printf("Line = %s", s);
//   	free(s);
//  	s = get_next_line(fd);
//  	printf("Line = %s", s);
//   	free(s);
//  	s = get_next_line(fd);
//  	printf("Line = %s", s);
//   	free(s);
//  	s = get_next_line(fd);
//  	printf("Line = %s", s);
//   	free(s);
//  	s = get_next_line(fd);
//  	printf("Line = %s", s);
//   	free(s);
//  	s = get_next_line(fd);
//  	printf("Line = %s", s);
//   	free(s);
//  	s = get_next_line(fd);
//  	printf("%s", s);
//   	free(s);

//  	printf("\n-----\n");
//  	close(fd);
//   	return (0);
//   }
