/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:00:31 by moutifer          #+#    #+#             */
/*   Updated: 2025/04/22 22:05:49 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_split(char const *s)
{
	int		count;
	int		i;
	int		j;
	char	**result;

	if (!s)
		return (NULL);
	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != ' ')
			i++;
	}
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	result[count] = NULL;
	i = 0;
	j = 0;
	while (j < count)
	{
		while (s[i] && s[i] == ' ')
			i++;
		result[j] = ft_strdup(&s[i]);
		while (s[i] && s[i] != ' ')
			i++;
		j++;
	}
	return (result);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		len;

	len = 0;
	while (s[len] && s[len] != ' ')
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	parse_string_args(char *str, t_stack *stack_a)
{
	char	**args;
	int		i;
	int		error;
	int		success;

	args = ft_split(str);
	if (!args)
		return (0);
	i = 0;
	success = 1;
	while (args[i] && success)
	{
		error = 0;
		stack_a->array[stack_a->size] = ft_atoi(args[i], &error);
		if (error)
			success = 0;
		else
			stack_a->size++;
		i++;
	}
	free_split(args);
	return (success);
}

int	parse_args(int argc, char **argv, t_stack *stack_a)
{
	int	i;
	int	error;

	stack_a->size = 0;
	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] == ' ')
				return (parse_string_args(argv[1], stack_a));
			i++;
		}
	}
	i = 1;
	while (i < argc)
	{
		error = 0;
		stack_a->array[stack_a->size] = ft_atoi(argv[i], &error);
		if (error)
			return (0);
		stack_a->size++;
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->array[i] == stack->array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
