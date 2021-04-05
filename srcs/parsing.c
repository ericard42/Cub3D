/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:48:55 by ericard           #+#    #+#             */
/*   Updated: 2021/04/05 12:24:15 by ericard          ###   ########.fr       */
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
		errors("Un parametre dans le .cub est inconnu", infos);
	}
	return (0);
}

void	parsing(char *file, t_infos *infos)
{
	int		fd;
	char	*str;
	int		ret;

	ret = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		errors("Impossible d'ouvrir le fichier .cub", infos);
	while (ret == 1)
	{
		if ((ret = get_next_line(fd, &str)) == -1)
			errors("Erreur lors de la lecture du fichier", infos);
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
