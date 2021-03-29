/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:47:39 by ericard           #+#    #+#             */
/*   Updated: 2021/03/29 16:08:42 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_is_valid_two(t_infos *infos, int i, int j)
{
	if (infos->map[i][j] == '0' || infos->map[i][j] == '2')
	{
		if (infos->map[i][j - 1] != '0' && infos->map[i][j - 1] != '2'
			&& infos->map[i][j - 1] != '1')
			errors("Map incorrecte", infos);
		if (infos->map[i][j + 1] != '0' && infos->map[i][j + 1] != '2'
			&& infos->map[i][j + 1] != '1')
			errors("Map incorrecte", infos);
		if (infos->map[i - 1][j] != '0' && infos->map[i - 1][j] != '2'
			&& infos->map[i - 1][j] != '1')
			errors("Map incorrecte", infos);
		if (infos->map[i + 1][j] != '0' && infos->map[i + 1][j] != '2'
			&& infos->map[i + 1][j] != '1')
			errors("Map incorrecte", infos);
	}
}

void	map_is_valid(t_infos *infos)
{
	int	i;
	int	j;

	i = 0;
	if (infos->depart == '0')
		errors("Aucun depart", infos);
	while (i < infos->lines)
	{
		j = 0;
		while (infos->map[i][j] != '\0')
		{
			if ((i == 0 || i == infos->lines - 1) && (infos->map[i][j] != ' '
				&& infos->map[i][j] != '1' && infos->map[i][j] != '\t'))
				errors("Map incorrecte", infos);
			else
				map_is_valid_two(infos, i, j);
			j++;
		}
		i++;
	}
}
