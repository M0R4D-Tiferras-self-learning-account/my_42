/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:20:25 by moutifer          #+#    #+#             */
/*   Updated: 2024/12/18 20:20:03 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	idx;

	idx = 0;
	if (str == NULL)
		return (0);
	while (str[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		idx;

	result = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (result == NULL)
		return (NULL);
	idx = 0;
	while (s1[idx] != '\0')
	{
		result[idx] = s1[idx];
		idx++;
	}
	result[idx] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	result_idx;
	size_t	idx;
	char	*result;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 || !s2)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	result_idx = 0;
	while (s1[result_idx] != '\0')
	{
		result[result_idx] = s1[result_idx];
		result_idx++;
	}
	idx = 0;
	while (s2[idx] != '\0')
		result[result_idx++] = s2[idx++];
	result[result_idx] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	int		idx;
	char	c_cast;

	c_cast = (char) c;
	idx = 0;
	while (*(s + idx) != '\0')
	{
		if (s[idx] == c_cast)
		{
			return ((char *)(s + idx));
		}
		idx++;
	}
	if ((s[idx] == '\0') && (c_cast == '\0'))
	{
		return ((char *)(s + idx));
	}
	return (NULL);
}

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
