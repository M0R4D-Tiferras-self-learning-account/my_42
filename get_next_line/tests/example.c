/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutifer <moutifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:03:01 by moutifer          #+#    #+#             */
/*   Updated: 2024/12/12 21:01:24 by moutifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


int	main(void)
{
	int	fd;
	size_t bsize = 3;
	static char *buffer;
	int n = -1;


	fd = open("./text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erorr in fd, fd = %d \n", fd);
		exit(3);
	}
	
	buffer = malloc(((size_t) (bsize) * sizeof(char)) + 1);
	n = read(fd, buffer, bsize);
	printf("first read call; %s\n", buffer);
	read(fd, buffer, bsize);
	printf("second read call; %s\n", buffer);
	read(fd, buffer, bsize);
	printf("third read call; %s\n", buffer);
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

	return (0);
}
