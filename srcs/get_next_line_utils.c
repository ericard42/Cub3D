/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 09:10:24 by ericard           #+#    #+#             */
/*   Updated: 2020/03/03 15:56:47 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str, char c)
{
	size_t i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

void		ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)s)[i] = 0;
		i++;
	}
}

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src, 0));
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src, 0));
}

char		*ft_strdup(const char *s, char c)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!(new = (char*)malloc(sizeof(*new) * (ft_strlen(s, '\n') + 1))))
		return (NULL);
	while (s[i] && s[i] != c)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char		*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	int		len2;
	char	*str;

	i = -1;
	j = 0;
	if (!s1)
		return (ft_strdup(s2, '\n'));
	if (!s2)
		return (NULL);
	len2 = ft_strlen(s2, '\n');
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1, 0) + len2 + 1))))
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j] && s2[j] != '\n')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
