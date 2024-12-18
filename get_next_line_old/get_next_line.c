/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:42:23 by mloeffer          #+#    #+#             */
/*   Updated: 2024/12/18 05:33:03 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	update_buffer(char *buffer, char *rest)
{
	int	i;

	i = 0;
	while (rest && rest[i])
	{
		buffer[i] = rest[i];
		i++;
	}
	buffer[i] = '\0';
}

static char	*get_rest_of_line(char *buffer)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
		return (NULL);
	rest = malloc((ft_strlen(buffer) - i) + 1);
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i + j])
	{
		rest[j] = buffer[i + j];
		j++;
	}
	rest[j] = '\0';
	return (rest);
}

static char	*read_and_join(int fd, char *buffer, char *line)
{
	int		bytes_read;
	char	*temp;

	while (!ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(line), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = line;
		line = ft_strjoin(line, buffer);
		free(temp);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin(buffer, "");
	if (!line)
		return (NULL);
	line = read_and_join(fd, buffer, line);
	if (!line)
		return (NULL);
	rest = get_rest_of_line(buffer);
	update_buffer(buffer, rest);
	free(rest);
	return (line);
}

/*int main(void)
{
	int	fd;

	fd = open("bin.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	__builtin_printf("first line : %s\n", get_next_line(fd));
	__builtin_printf("second line : %s\n", get_next_line(fd));
	close(fd);
	return (0);
}*/
