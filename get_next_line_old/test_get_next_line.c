/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:42:23 by mloeffer          #+#    #+#             */
/*   Updated: 2024/12/18 05:05:42 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <assert.h>

void	test_get_next_line(const char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	assert(fd != -1);
	line = get_next_line(fd);
	assert(line != NULL);
	printf("First line: %s\n", line);
	free(line);
	line = get_next_line(fd);
	assert(line != NULL);
	printf("Second line: %s\n", line);
	free(line);
	line = get_next_line(fd);
	assert(line != NULL);
	printf("Third line: %s\n", line);
	free(line);
	line = get_next_line(fd);
	assert(line != NULL);
	printf("Fourth line: %s\n", line);
	free(line);
	line = get_next_line(fd);
	assert(line == NULL);
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	test_get_next_line(argv[1]);
	return (0);
}