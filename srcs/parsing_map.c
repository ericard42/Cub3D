/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:48:18 by ericard           #+#    #+#             */
/*   Updated: 2021/04/02 15:06:36 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		verify_map(char *str)
{
	int i;

	i = 0;
	while (str[i] != '1')
	{
		if (str[i] == '\0' || (str[i] != 1 && str[i] != '0' && str[i] != ' '
			&& str[i] != '\t' && str[i] != 'N' && str[i] != 'S'
			&& str[i] != 'E' && str[i] != 'W' && str[i] != '2'))
			return (0);
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != ' ' && str[i] != '\t'
			&& str[i] != 'N' && str[i] != 'S' && str[i] != 'E' && str[i] != 'W'
			&& str[i] != '2')
			return (0);
		i++;
	}
	return (i);
}

void	map_parse_depart(t_infos *infos, char *str, int i, int j)
{
	if (infos->depart != '0')
	{
		free(str);
		errors("Point de depart en double", infos);
	}
	infos->departx = j;
	infos->departy = i;
	infos->depart = str[i];
	infos->map[j][i] = '0';
}

void	map_parse_two(t_infos *infos, char *str, int j)
{
	int	i;

	i = 0;
	if (!(infos->map[j] = (char*)malloc(sizeof(char) * (infos->columns + 1))))
		errors("Probleme de Malloc", infos);
	while (str[i] != '\0')
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			map_parse_depart(infos, str, i, j);
		else
			infos->map[j][i] = str[i];
		if (infos->map[j][i] == '2')
			infos->sp.nbsprites++;
		i++;
	}
	while (i < infos->columns)
	{
		infos->map[j][i] = ' ';
		i++;
	}
	infos->map[j][i] = '\0';
}

void	map_parse(t_infos *infos, char *file)
{
	int		fd;
	int		j;
	int		ret;
	char	*str;

	ret = 1;
	j = 0;
	infos->sp.nbsprites = 0;
	if (!(infos->map = (char**)malloc(sizeof(char*) * infos->lines)))
		errors("Probleme de Malloc", infos);
	fd = open(file, O_RDONLY);
	while (j < infos->lines)
	{
		ret = get_next_line(fd, &str);
		if (verify_map(str) != 0)
		{
			map_parse_two(infos, str, j);
			j++;
		}
		free(str);
	}
	close(fd);
}

int		size_map(t_infos *infos, char *str)
{
	int	i;

	i = verify_map(str);
	if (i == 0)
	{
		if (infos->lines != 0)
		{
			free(str);
			errors("Probleme de map", infos);
		}
		else
			return (0);
	}
	if (infos->resx == 0 || infos->resy == 0 || infos->f.value == -1
		|| infos->c.value == -1 || infos->s == NULL || infos->no == NULL
		|| infos->so == NULL || infos->we == NULL || infos->ea == NULL)
	{
		free(str);
		errors("Parametres manquants", infos);
	}
	if (i > infos->columns)
		infos->columns = i;
	infos->lines++;
	return (1);
}
