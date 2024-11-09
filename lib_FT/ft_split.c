/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:46:22 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/09 20:08:51 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char sep)
{
	size_t	idx;
	size_t	count;
	int		check;

	idx = 0;
	count = 0;
	check = 88;
	while (str[idx] != '\0')
	{
		if ((str[idx] == sep))
		{
			check = 1;
		}
		else if ((str[idx] != sep) && (check == 1 || check == 88))
		{
			count++;
			check = -1;
		}
		idx++;
	}
	return (count);
}

static void	*to_free(char **result, size_t col)
{
	int	i_col;

	i_col = 0;
	if (col == 0)
		free(result[i_col]);
	while (i_col < col)
	{
		free(result[i_col]);
		i_col++;
	}
	free(result);
	return (NULL);
}

static int	count_word_len(char const *s, size_t start, char sep)
{
	int	count;

	count = 0;
	while ((s[start] != '\0') && (s[start] != sep))
	{
		count++;
		start++;
	}
	return (count + 1);
}

static char	**fill(char const *s, char sep, char **result)
{
	size_t	idx;
	size_t	col;
	size_t	row;

	idx = 0;
	col = 0;
	while (s[idx] != '\0' && col < count_words(s, sep))
	{
		row = 0;
		if (s[idx] != sep)
		{
			result[col] = malloc(count_word_len(s, s[idx], sep) * sizeof(char));
			if (result[col] == NULL)
				return (to_free(result, col));
			while (s[idx] != sep)
			{
				result[col][row] = s[idx];
				row++;
				idx++;
			}
			result[col][row] = '\0';
			col++;
		}
		idx++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (s == NULL)
		return (NULL);
	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	result = fill(s, c, result);
	return (result);
}

#include <libc.h>

int	main()
{
	int c = 0;
	char *s = "";
	char **res;

	res = ft_split(s, ' ');

	while (c < count_words(s, ' '))
	{
		printf("%s", res[c]);
		c++;
		printf("\n");
	}
	printf("%s", res[0]);
	return (0);
}
