/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:51:41 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/02/19 13:49:10 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_is_valid(t_infos infos)
{
	int	i;
	int	j;

	i = 0;
	while (i < infos.lines)
	{
		j = 0;
		while(infos.map[i][j] != '\0')
		{
			if ((i == 0 || i == infos.lines - 1) && (infos.map[i][j] != ' '
				&& infos.map[i][j] != '1' && infos.map[i][j] != '\t'))
				errors("Map incorrecte");
			else
			{
				if (infos.map[i][j] == '0' || infos.map[i][j] == '2')
				{
					if (infos.map[i][j - 1] != '0' && infos.map[i][j - 1] != '2'
						&& infos.map[i][j - 1] != '1')
						errors("Map incorrecte");
					if (infos.map[i][j + 1] != '0' && infos.map[i][j + 1] != '2'
						&& infos.map[i][j + 1] != '1')
						errors("Map incorrecte");
					if (infos.map [i - 1][j] != '0' && infos.map[i - 1][j] != '2'
						&& infos.map[i - 1][j] != '1')
						errors("Map incorrecte");
					if (infos.map [i + 1][j] != '0' && infos.map[i + 1][j] != '2'
						&& infos.map[i + 1][j] != '1')
						errors("Map incorrecte");
				}
			}
			j++;
		}
		i++;
	}
}