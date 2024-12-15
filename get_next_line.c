/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjzlak <mjzlak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:42:23 by mloeffer          #+#    #+#             */
/*   Updated: 2024/12/15 13:56:26 by mjzlak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_extract_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (free(save), NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_save(char *save)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
		return (free(save), NULL);
	str = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!str)
		return (free(save), NULL);
	i += 1;
	j = 0;
	while (save[i])
		str[j++] = save[i++];
	str[j] = '\0';
	return (free(save), str);
}

static char	*ft_read_and_save(int fd, char *save)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free(save), NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buff), free(save), NULL);
		buff[read_bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	return (free(buff), save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_extract_line(save);
	save = ft_save(save);
	if (!line || !save)
	{
		free(save);
		save = NULL;
	}
	return (line);
}

int main(void)
{
    int     fd;
    char    *line;

    fd = open("lol.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    line = get_next_line(fd);
    __builtin_printf("first line : %s\n", line);
    free(line);
    line = get_next_line(fd);
    __builtin_printf("second line : %s\n", line);
    free(line);
    line = get_next_line(fd);
    __builtin_printf("third line : %s\n", line);
    free(line);
    line = get_next_line(fd);
    __builtin_printf("fourth line : %s\n", line);
    free(line);
    line = get_next_line(fd);
    __builtin_printf("fifth line : %s\n", line);
    free(line);
    line = get_next_line(fd);
    __builtin_printf("sixth line : %s\n", line);
    free(line);
    line = get_next_line(fd);
    __builtin_printf("seventh line : %s\n", line);
    free(line);
    line = get_next_line(fd);
    __builtin_printf("eighth line : %s\n", line);
    free(line);
    line = get_next_line(fd);
    __builtin_printf("ninth line : %s\n", line);
    free(line);
    line = get_next_line(fd);
    __builtin_printf("tenth line : %s\n", line);
    free(line);
	while ((line = get_next_line(fd)) != NULL)
		free(line);
    close(fd);
    return (0);
}
