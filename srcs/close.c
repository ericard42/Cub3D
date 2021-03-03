/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:11:22 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/03/03 11:56:15 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_close(t_infos *infos)
{
	int	i;

	i = 0;
	if (infos->no != NULL)
		free(infos->no);
	if (infos->so != NULL)
		free(infos->so);
	if (infos->ea != NULL)
		free(infos->ea);
	if (infos->we != NULL)
		free(infos->we);
	if (infos->s != NULL)
		free(infos->s);
	if (infos->map != NULL)
	{
		while (i < infos->lines)
		{
			free(infos->map[i]);
			i++;
		}
		free(infos->map);
	}
	if (infos->mlx.win != NULL)
		mlx_destroy_window(infos->mlx.mlx, infos->mlx.win);
	exit(0);
	return(1);
}