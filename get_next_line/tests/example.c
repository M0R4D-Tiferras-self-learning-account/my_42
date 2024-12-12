/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:03:01 by moutifer          #+#    #+#             */
/*   Updated: 2024/12/06 17:03:20 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


int	main(void)
{
	int	fd;
	size_t bsize = 100000;
	char buffer[bsize];
	int n = -1;


	fd = open("./text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erorr in fd, fd = %d \n", fd);
		exit(3);
	}

	n = read(fd, buffer, bsize);
	if (n < 0)
	{
		printf("Error in reading file\n");
		exit(3); 
	}

	if (buffer[0] == '\0')
	{
		printf("The file is empty\n");
		exit(3);
	}

	printf("%s", buffer);
	return (0);
}
