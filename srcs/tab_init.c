/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:39:32 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/03/05 13:51:05 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	depart_init(t_infos *infos)
{
	if (infos->depart == 'N')
	{
		infos->ray.dirx = -1;
		infos->ray.diry = 0;
		infos->ray.planx = 0;
		infos->ray.plany = 0.66;
	}
	if (infos->depart == 'S')
	{
		infos->ray.dirx = 1;
		infos->ray.diry = 0;
		infos->ray.planx = 0;
		infos->ray.plany = -0.66;
	}
	if (infos->depart == 'E')
	{
		infos->ray.dirx = 0;
		infos->ray.diry = 1;
		infos->ray.planx = 0.66;
		infos->ray.plany = 0;
	}
	if (infos->depart == 'W')
	{
		infos->ray.dirx = 0;
		infos->ray.diry = -1;
		infos->ray.planx = -0.66;
		infos->ray.plany = 0;
	}
	infos->ray.posx = (double)infos->departx;
	infos->ray.posy = (double)infos->departy;
}

void	infos_init(t_infos *infos)
{
    infos->resx = 0;
    infos->resy = 0;
    infos->f.r = -1;
	infos->f.g = -1;
	infos->f.b = -1;
	infos->f.value = -1;
	infos->c.r = -1;
	infos->c.g = -1;
    infos->c.b = -1;
	infos->c.value = -1;
    infos->no = NULL;
    infos->so = NULL;
    infos->we = NULL;
    infos->ea = NULL;
    infos->s = NULL;
    infos->map = NULL;
	infos->lines = 0;
	infos->columns = 0;
	infos->depart = '0';
	infos->departx = 0;
	infos->departy = 0;
}

void	struct_mlx_init(t_infos *infos)
{
	infos->mlx.mlx = NULL;
	infos->mlx.win = NULL;
	infos->mlx.img = NULL;
	infos->mlx.addr = NULL;
	infos->mlx.bits_per_pixel = 0;
	infos->mlx.line_length = 0;
	infos->mlx.endian = 0;
	infos->mlx.screenx = 0;
	infos->mlx.screeny = 0;
}