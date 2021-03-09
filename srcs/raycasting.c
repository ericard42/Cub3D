/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:27:13 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/03/08 21:01:54 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initial_sidedist(t_infos *infos)
{
	if (infos->ray.dirx < 0)
		{
			infos->ray.stepx = -1;
			infos->ray.sidedistx = (infos->ray.posx - infos->ray.mapx) * infos->ray.deltadistx;
		}
		else
		{
			infos->ray.stepx = 1;
			infos->ray.sidedistx = (infos->ray.mapx + 1 - infos->ray.posx) * infos->ray.deltadistx;
		}
		if (infos->ray.diry < 0)
		{
			infos->ray.stepy = -1;
			infos->ray.sidedisty = (infos->ray.posy - infos->ray.mapy) * infos->ray.deltadisty;
		}
		else
		{
			infos->ray.stepy = 1;
			infos->ray.sidedisty = (infos->ray.mapy + 1 - infos->ray.posy) * infos->ray.deltadisty;
		}
}

void	distance_wall(t_infos *infos)
{
	infos->ray.hit = 0;
	while (infos->ray.hit == 0)
	{
		if (infos->ray.sidedistx < infos->ray.sidedisty)
		{
			infos->ray.sidedistx += infos->ray.deltadistx;
			infos->ray.mapx += infos->ray.stepx;
			infos->ray.side = 0;
		}
		else
		{
			infos->ray.sidedisty += infos->ray.deltadisty;
			infos->ray.mapy += infos->ray.stepy;
			infos->ray.side = 1;
		}

		if (infos->map[infos->ray.mapy][infos->ray.mapx] == '1')
			infos->ray.hit = 1;
	}
	if (infos->ray.side == 0)
		infos->ray.perpwalldist = ((double)infos->ray.mapx - infos->ray.posx + (1 - (double)infos->ray.stepx) / 2) / infos->ray.raydirx;
	else
		infos->ray.perpwalldist = ((double)infos->ray.mapy - infos->ray.posy + (1 - (double)infos->ray.stepy) / 2) / infos->ray.raydiry;
}

void	draw_start_end(t_infos *infos)
{
	infos->ray.lineheight = (int)(infos->resy / infos->ray.perpwalldist);
	infos->ray.drawstart = -infos->ray.lineheight / 2 + infos->resy / 2;
	if (infos->ray.drawstart < 0)
		infos->ray.drawstart = 0;
	infos->ray.drawend = infos->ray.lineheight / 2 + infos->resy / 2;
	if (infos->ray.drawend >= infos->resy || infos->ray.drawend < 0)
		infos->ray.drawend = infos->resy - 1;
}

int		raycasting(t_infos *infos)
{
	infos->ray.x = 0;
	while (infos->ray.x < infos->resx)
	{
		infos->ray.camerax = 2 * infos->ray.x / (double)infos->resx - 1;
		infos->ray.raydirx = infos->ray.dirx + infos->ray.planx * infos->ray.camerax;
		infos->ray.raydiry = infos->ray.diry + infos->ray.plany * infos->ray.camerax;
		infos->ray.mapx = (int)infos->ray.posx;
		infos->ray.mapy = (int)infos->ray.posy;
		if (infos->ray.raydiry == 0)
			infos->ray.deltadistx = 0;
		else if (infos->ray.raydirx == 0)
			infos->ray.deltadistx = 1;
		else
			infos->ray.deltadistx = sqrt(1 + (infos->ray.raydiry * infos->ray.raydiry) / (infos->ray.raydirx * infos->ray.raydirx));
		if (infos->ray.raydirx == 0)
			infos->ray.deltadisty = 0;
		else if (infos->ray.raydiry == 0)
			infos->ray.deltadisty = 1;
		else
			infos->ray.deltadisty = sqrt(1 + (infos->ray.raydirx * infos->ray.raydirx) / (infos->ray.raydiry * infos->ray.raydiry));
		initial_sidedist(infos);
		distance_wall(infos);
		draw_start_end(infos);
		print_columns(infos);
		infos->ray.x++;
	}
	minimap(infos);
	mlx_put_image_to_window(infos->mlx.mlx, infos->mlx.win, infos->mlx.img, 0, 0);
	return (1);
}