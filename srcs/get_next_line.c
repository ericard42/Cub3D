/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 09:10:26 by ericard           #+#    #+#             */
/*   Updated: 2020/03/03 16:05:55 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		next(char *buffer)
{
	size_t			i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	int				bytes;
	static char		buffer[256][BUFFER_SIZE + 1];

	if (!line || fd == -1)
		return (-1);
	if (BUFFER_SIZE == 0)
	{
		*line = 0;
		return (-1);
	}
	if (!(*line = ft_strdup("", 0)))
		return (-1);
	while (next(buffer[fd]) == -1)
	{
		if (!(*line = ft_strjoin(*line, buffer[fd])))
			return (-1);
		ft_bzero(buffer[fd], BUFFER_SIZE + 1);
		bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes <= 0)
			return (bytes);
	}
	if (!(*line = ft_strjoin(*line, buffer[fd])))
		return (-1);
	ft_strlcpy(buffer[fd], buffer[fd] + next(buffer[fd]) + 1, BUFFER_SIZE);
	return (1);
}
