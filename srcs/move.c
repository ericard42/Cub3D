/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:43:18 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/03/04 22:09:09 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_w_s(t_infos *infos, char key)
{
	if (key == 'w')
	{
		infos->ray.posx += infos->ray.dirx * 0.1;
		infos->ray.posy += infos->ray.diry * 0.1;
	}
	if (key == 's')
	{
		infos->ray.posx -= infos->ray.dirx * 0.1;
		infos->ray.posy -= infos->ray.diry * 0.1;
	}
}

void	key_a_d(t_infos *infos, char key)
{
	if (key == 'a')
	{
		infos->ray.posx += infos->ray.diry * 0.1;
		infos->ray.posy -= infos->ray.dirx * 0.1;
	}
	if (key == 'd')
	{
		infos->ray.posx -= infos->ray.dirx * 0.1;
		infos->ray.posy += infos->ray.diry * 0.1;
	}
}

void	key_left_right(t_infos *infos, char key)
{
	if (key == 'l')
	{
		infos->ray.posx = infos->ray.posx;
	}
	if (key == 'r')
	{
		infos->ray.posx = infos->ray.posx;
	}
}