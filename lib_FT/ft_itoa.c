/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:31:55 by moutifer          #+#    #+#             */
/*   Updated: 2024/11/09 22:50:03 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	itoa_count_size(int num, int sign)
{
	int	count;
	int	div;

	count = 1;
	div = 10;
	if (sign == -1)
		count++;
	while ((num / div) > 0)
	{
		count++;
		div = div * 10;
	}
	return (count + 1);
}

static char	*rev_str(char *r)
{
	int		idx;
	int		last;
	char	tmp;

	idx = 0;
	last = ft_strlen(r) - 1;
	while (idx != last)
	{
		tmp = r[idx];
		r[idx] = r[last];
		r[last] = tmp;
		if (((idx + 1) == last))
			break ;
		last--;
		idx++;
	}
	return (r);
}

static char	*fill_result(char *result, int n, int sign)
{
	int	idx;

	idx = 0;
	while (n > 0)
	{
		result[idx] = (n % 10) + '0';
		idx++;
		n = n / 10;
	}
	if (sign == -1)
	{
		result[idx] = '-';
		idx++;
	}
	result[idx] = '\0';
	rev_str(result);
	return (result);
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*result;

	sign = 1;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	if (n < 0)
	{
		sign = -1;
		n = -1 * n;
	}
	result = malloc(sizeof(char) * itoa_count_size(n, sign));
	if (result == NULL)
		return (NULL);
	result = fill_result(result, n, sign);
	return (result);
}
