/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:29:54 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/02/19 15:41:51 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		verify_map(char *str)
{
	int i;

	i = 0;
	while(str[i] != '1')
	{
		if (str[i] == '\0')		
			return (0);
		i++;
	}
	while(str[i] != '\0')
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != ' ' && str[i] != '\t'
			&& str[i] != 'N' && str[i] != 'S' && str[i] != 'E' && str[i] != 'W'
			&& str[i] != '2')
			return(0);
		i++;
	}
	return (i);
}

void	map_parse(t_infos *infos, char *file)
{
	int fd;
	int i;
	int	j;
	int	ret;
	char *str;

	ret = 1;
	j = 0;
	if(!(infos->map = (char**)malloc(sizeof(char*) * infos->lines)))
		errors("Probleme de Malloc");
	fd = open(file, O_RDONLY);
	while (j < infos->lines)
	{
		ret = get_next_line(fd, &str);
		if(verify_map(str) != 0)
		{
			i = 0;
			if(!(infos->map[j] = (char*)malloc(sizeof(char) * (infos->columns + 1))))
				errors("Probleme de Malloc");
			while (str[i] != '\0')
			{
				if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
				{
					infos->departx = i;
					infos->departy = j;
					infos->depart = str[i];
					infos->map[j][i] = '0';
				}
				else
					infos->map[j][i] = str[i];
				i++;
			}
			infos->map[j][i] = '\0';
			j++;
		}	
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
			errors("Probleme de map");
		else
			return(0);
	}
	if (infos->resx == 0 || infos->resy == 0 || infos->fr == -1
		|| infos->cr  == -1 || infos->s == NULL || infos->no == NULL
		|| infos->so == NULL || infos->we == NULL || infos->ea == NULL)
		errors("Parametres manquants");
	if (i > infos->columns)
		infos->columns = i;
	infos->lines++;
	return(1);
}