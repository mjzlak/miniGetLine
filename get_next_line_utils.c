/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjzlak <mjzlak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:26:24 by mloeffer          #+#    #+#             */
/*   Updated: 2024/12/15 11:25:16 by mjzlak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
    size_t	i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char	*ft_strchr(const char *s, int c)
{
    int	i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
    {
        if (s[i] == (char)c)
            return ((char *)(s + i));
        i++;
    }
    return (0);
}

char	*ft_strdup(const char *str)
{
	char	*res;
	size_t	len;

	len = ft_strlen(str);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	len = 0;
	while (str[len])
	{
		res[len] = str[len];
		len++;
	}
	res[len] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
    char	*str;
    size_t	i;
    size_t	j;

    if (!s1)
    {
        s1 = malloc(1);
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (NULL);
    str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!str)
        return (NULL);
    i = -1;
    j = 0;
    while (s1[++i])
        str[i] = s1[i];
    while (s2[j])
        str[i++] = s2[j++];
    str[i] = '\0';
    free(s1);
    return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
