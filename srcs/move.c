/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:47:56 by ericard           #+#    #+#             */
/*   Updated: 2021/03/30 17:27:20 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key(t_infos *infos)
{
	if (infos->move.w == 1)
		key_w_s(infos, 'w');
	if (infos->move.s == 1)
		key_w_s(infos, 's');
	if (infos->move.a == 1)
		key_a_d(infos, 'a');
	if (infos->move.d == 1)
		key_a_d(infos, 'd');
	if (infos->move.left == 1)
		key_left(infos);
	if (infos->move.right == 1)
		key_right(infos);
	return (1);
}

void	key_w_s(t_infos *infos, char key)
{
	if (key == 'w')
	{
		if (infos->map[(int)(infos->ray.posx + infos->ray.dirx
				* 0.08)][(int)infos->ray.posy] == '0')
			infos->ray.posx += infos->ray.dirx * 0.08;
		if (infos->map[(int)infos->ray.posx][(int)(infos->ray.posy
				+ infos->ray.diry * 0.08)] == '0')
			infos->ray.posy += infos->ray.diry * 0.08;
	}
	if (key == 's')
	{
		if (infos->map[(int)(infos->ray.posx
				- infos->ray.dirx * 0.08)][(int)infos->ray.posy] == '0')
			infos->ray.posx -= infos->ray.dirx * 0.08;
		if (infos->map[(int)infos->ray.posx][(int)(infos->ray.posy
				- infos->ray.diry * 0.08)] == '0')
			infos->ray.posy -= infos->ray.diry * 0.08;
	}
}

void	key_a_d(t_infos *infos, char key)
{
	if (key == 'd')
	{
		if (infos->map[(int)(infos->ray.posx
				+ infos->ray.diry * 0.08)][(int)infos->ray.posy] == '0')
			infos->ray.posx += infos->ray.diry * 0.08;
		if (infos->map[(int)infos->ray.posx][(int)(infos->ray.posy
				- infos->ray.dirx * 0.08)] == '0')
			infos->ray.posy -= infos->ray.dirx * 0.08;
	}
	if (key == 'a')
	{
		if (infos->map[(int)(infos->ray.posx
				- infos->ray.diry * 0.08)][(int)infos->ray.posy] == '0')
			infos->ray.posx -= infos->ray.diry * 0.08;
		if (infos->map[(int)infos->ray.posx][(int)(infos->ray.posy
				+ infos->ray.dirx * 0.08)] == '0')
			infos->ray.posy += infos->ray.dirx * 0.08;
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
