/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:03:18 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/03/25 16:39:48 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		valid_parameter(char *str, t_infos *infos)
{
	if (str[0] == 'R' || str[0] == 'F' || str[0] == 'C' || (str[0] == 'S' 
		&& str[1] == ' ') || (str[0] == 'N' && str[1] == 'O') || (str[0] == 'S'
		&& str[1] == 'O') || (str[0] == 'W' && str[1] == 'E') || (str[0] == 'E'
		&& str[1] == 'A') || !str[0])
		return (1);
	if (verify_map(str) != 0)
		return (1);
	else
	{
		free(str);
		errors("Parametre inexistant", infos);
	}
	return (0);
}

void	parsing(char *file, t_infos *infos)
{
	int         fd;
    char        *str;
    int         ret;

    ret = 1;
    fd = open(file, O_RDONLY);
	if (fd == -1)
		errors("Impossible d'ouvrir le fichier", infos);
    while (ret == 1)
    {
        ret = get_next_line(fd, &str);
		valid_parameter(str, infos);
        resolution(infos, str);
		colors(infos, str);
		textures(infos, str);
		size_map(infos, str);
        free(str);
	}
	close(fd);
	map_parse(infos, file);
	map_is_valid(infos);
	mlx_start(infos);
}
