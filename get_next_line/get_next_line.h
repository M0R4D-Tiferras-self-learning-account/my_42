/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:24:25 by moutifer          #+#    #+#             */
/*   Updated: 2024/12/12 04:16:04 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <libc.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	count_newline(char *str);
char	*get_next_line(int fd);

#endif
