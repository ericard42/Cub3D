/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:47:56 by ericard           #+#    #+#             */
/*   Updated: 2021/03/29 16:23:23 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_w_s(t_infos *infos, char key)
{
	if (key == 'w')
	{
		if (infos->map[(int)(infos->ray.posx + infos->ray.dirx
				* 0.1)][(int)infos->ray.posy] == '0')
			infos->ray.posx += infos->ray.dirx * 0.1;
		if (infos->map[(int)infos->ray.posx][(int)(infos->ray.posy
				+ infos->ray.diry * 0.1)] == '0')
			infos->ray.posy += infos->ray.diry * 0.1;
	}
	if (key == 's')
	{
		if (infos->map[(int)(infos->ray.posx
				- infos->ray.dirx * 0.1)][(int)infos->ray.posy] == '0')
			infos->ray.posx -= infos->ray.dirx * 0.1;
		if (infos->map[(int)infos->ray.posx][(int)(infos->ray.posy
				- infos->ray.diry * 0.1)] == '0')
			infos->ray.posy -= infos->ray.diry * 0.1;
	}
}

void	key_a_d(t_infos *infos, char key)
{
	if (key == 'd')
	{
		if (infos->map[(int)(infos->ray.posx
				- infos->ray.diry * 0.1)][(int)infos->ray.posy] == '0')
			infos->ray.posx += infos->ray.diry * 0.1;
		if (infos->map[(int)infos->ray.posx][(int)(infos->ray.posy
				+ infos->ray.dirx * 0.1)] == '0')
			infos->ray.posy -= infos->ray.dirx * 0.1;
	}
	if (key == 'a')
	{
		if (infos->map[(int)(infos->ray.posx
				+ infos->ray.diry * 0.1)][(int)infos->ray.posy] == '0')
			infos->ray.posx -= infos->ray.diry * 0.1;
		if (infos->map[(int)infos->ray.posx][(int)(infos->ray.posy
				- infos->ray.dirx * 0.1)] == '0')
			infos->ray.posy += infos->ray.dirx * 0.1;
	}
}

void	key_right(t_infos *infos)
{
	double	olddirx;
	double	oldplanx;

	olddirx = infos->ray.dirx;
	oldplanx = infos->ray.planx;
	infos->ray.dirx = infos->ray.dirx * cos(-0.05 / 2)
		- infos->ray.diry * sin(-0.05 / 2);
	infos->ray.diry = olddirx * sin(-0.05 / 2)
		+ infos->ray.diry * cos(-0.05 / 2);
	infos->ray.planx = infos->ray.planx * cos(-0.05 / 2)
		- infos->ray.plany * sin(-0.05 / 2);
	infos->ray.plany = oldplanx * sin(-0.05 / 2)
		+ infos->ray.plany * cos(-0.05 / 2);
}

void	key_left(t_infos *infos)
{
	double	olddirx;
	double	oldplanx;

	olddirx = infos->ray.dirx;
	oldplanx = infos->ray.planx;
	infos->ray.dirx = infos->ray.dirx * cos(0.05 / 2)
		- infos->ray.diry * sin(0.05 / 2);
	infos->ray.diry = olddirx * sin(0.05 / 2)
		+ infos->ray.diry * cos(0.05 / 2);
	infos->ray.planx = infos->ray.planx * cos(0.05 / 2)
		- infos->ray.plany * sin(0.05 / 2);
	infos->ray.plany = oldplanx * sin(0.05 / 2)
		+ infos->ray.plany * cos(0.05 / 2);
}
