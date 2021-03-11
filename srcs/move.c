/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:43:18 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/03/11 14:10:15 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_w_s(t_infos *infos, char key)
{
	if (key == 'w')
	{
		if (infos->map[(int)infos->ray.posy][(int)(infos->ray.posx + infos->ray.dirx * 0.1)] != '1')
			infos->ray.posx += infos->ray.dirx * 0.1;
		if (infos->map[(int)(infos->ray.posy + (infos->ray.diry * 0.1))][(int)infos->ray.posx] != '1')
			infos->ray.posy += infos->ray.diry * 0.1;
	}
	if (key == 's')
	{
		if (infos->map[(int)infos->ray.posy][(int)(infos->ray.posx - (infos->ray.dirx * 0.1))] != '1')
		infos->ray.posx -= infos->ray.dirx * 0.1;
		if (infos->map[(int)(infos->ray.posy - (infos->ray.diry * 0.1))][(int)infos->ray.posx] != '1')
		infos->ray.posy -= infos->ray.diry * 0.1;
	}
}

void	key_a_d(t_infos *infos, char key)
{
	if (key == 'd')
	{
		if (infos->map[(int)infos->ray.posy][(int)(infos->ray.posx - (infos->ray.dirx * 0.1))] != '1')
		infos->ray.posx -= infos->ray.diry * 0.1;
		if (infos->map[(int)(infos->ray.posy + (infos->ray.diry * 0.1))][(int)infos->ray.posx] != '1')
		infos->ray.posy += infos->ray.dirx * 0.1;
	}
	if (key == 'a')
	{
		if (infos->map[(int)infos->ray.posy][(int)(infos->ray.posx + (infos->ray.dirx * 0.1))] != '1')
		infos->ray.posx += infos->ray.dirx * 0.1;
		if (infos->map[(int)(infos->ray.posy - (infos->ray.diry * 0.1))][(int)infos->ray.posx] != '1')
		infos->ray.posy -= infos->ray.diry * 0.1;
	}
}

void	key_left_right(t_infos *infos, char key)
{
	double	olddirx;
	double	oldplanx;

	olddirx = infos->ray.dirx;
	oldplanx = infos->ray.planx;
	if (key == 'r')
	{
		infos->ray.dirx = infos->ray.dirx * cos(-0.05 / 2) - infos->ray.diry * sin(-0.05 / 2);
		infos->ray.diry = olddirx * sin(-0.05 / 2) + infos->ray.diry * cos(-0.05 / 2);
		infos->ray.planx = infos->ray.planx * cos(-0.05 / 2) - infos->ray.plany * sin(-0.05 / 2);
		infos->ray.plany = oldplanx * sin(-0.05 / 2) + infos->ray.plany * cos(-0.05 / 2);
	}
	if (key == 'l')
	{
		infos->ray.dirx = infos->ray.dirx * cos(0.05 / 2) - infos->ray.diry * sin(0.05 / 2);
		infos->ray.diry = olddirx * sin(0.05 / 2) + infos->ray.diry * cos(0.05 / 2);
		infos->ray.planx = infos->ray.planx * cos(0.05 / 2) - infos->ray.plany * sin(0.05 / 2);
		infos->ray.plany = oldplanx * sin(0.05 / 2) + infos->ray.plany * cos(0.05 / 2);
	}
}