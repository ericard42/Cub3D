/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:29:54 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/02/16 15:03:46 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		size_map(t_infos *infos, char *str)
{
	int	i;

	i = 0;
	while(str[i] != '1')
	{
		if (str[i] == '\0')
		{
			if (infos->lines != 0)
				break;
			return (0);
		}
		i++;
	}
	while(str[i] != '\0')
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != ' ' && str[i] != '\t'
			&& str[i] != 'N' && str[i] != 'S' && str[i] != 'E' && str[i] != 'W')
			return(0);
		i++;
	}
	if (i > infos->columns)
		infos->columns = i;
	infos->lines++;
	return(1);
}