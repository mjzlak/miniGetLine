/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:29:18 by mjzlak            #+#    #+#             */
/*   Updated: 2024/11/24 19:14:17 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static size_t	get_words_count(const char *str, char c)
{
	size_t	count;
	size_t	i;

	if (!str)
		return (0);
	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static size_t	get_size(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	**ft_split(const char *str, char c)
{
	char	**array;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	array = malloc(sizeof(char *) * (get_words_count(str, c) + 1));
	if (!array)
		return (NULL);
	while (i < get_words_count(str, c))
	{
		while (str[j] && str[j] == c)
			j++;
		if (str[j])
			array[i] = ft_substr(str, j, get_size(&str[j], c));
		if (!array[i])
			return (free_array(array), NULL);
		while (str[j] && str[j] != c)
			j++;
		i++;
	}
	array[i] = NULL;
	return (array);
}
