/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:49:22 by ericard           #+#    #+#             */
/*   Updated: 2021/03/30 13:26:49 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprite_two(t_infos *infos, int j)
{
	double	tmp;

	if (infos->sp.spritedist[j] < infos->sp.spritedist[j + 1])
	{
		tmp = infos->sp.spritedist[j];
		infos->sp.spritedist[j] = infos->sp.spritedist[j + 1];
		infos->sp.spritedist[j + 1] = tmp;
		tmp = infos->sp.order[j];
		infos->sp.order[j] = infos->sp.order[j + 1];
		infos->sp.order[j + 1] = tmp;
	}
}

void	sort_sprite(t_infos *infos)
{
	int		i;
	int		j;

	i = 0;
	while (i < infos->sp.nbsprites)
	{
		infos->sp.order[i] = i;
		infos->sp.spritedist[i] = ((infos->ray.posx - infos->spos[i].x)
			* (infos->ray.posx - infos->spos[i].x) + (infos->ray.posy
				- infos->spos[i].y) * (infos->ray.posy - infos->spos[i].y));
		i++;
	}
	i = 0;
	while (i < infos->sp.nbsprites)
	{
		j = 0;
		while (j < infos->sp.nbsprites - 1)
		{
			sort_sprite_two(infos, j);
			j++;
		}
		i++;
	}
}

void	drawsprite(t_infos *infos)
{
	int	y;
	int	d;
	int	texy;

	y = infos->sp.drawstarty;
	while (y < infos->sp.drawendy)
	{
		d = (y) * 256 - infos->resy * 128 + infos->sp.spriteheight * 128;
		texy = ((d * infos->textures[4].img_height)
			/ infos->sp.spriteheight) / 256;
		if (infos->textures[4].addr[texy * infos->textures[4].img_width
			+ infos->sp.texx] != -16777216)
			my_mlx_pixel_put(infos, infos->sp.stripe, y,
				infos->textures[4].addr[texy
					* infos->textures[4].img_width + infos->sp.texx]);
		y++;
	}
}

void	calculs_sprite(t_infos *infos, int i)
{
	infos->sp.spritex = infos->spos[infos->sp.order[i]].x - infos->ray.posx;
	infos->sp.spritey = infos->spos[infos->sp.order[i]].y - infos->ray.posy;
	infos->sp.invdet = 1.0 / (infos->ray.planx * infos->ray.diry
		- infos->ray.dirx * infos->ray.plany);
	infos->sp.transformx = infos->sp.invdet * (infos->ray.diry
		* infos->sp.spritex - infos->ray.dirx * infos->sp.spritey);
	infos->sp.transformy = infos->sp.invdet * (-infos->ray.plany
		* infos->sp.spritex + infos->ray.planx * infos->sp.spritey);
	infos->sp.spritescreenx = (int)((infos->resx / 2)
		* (1 + infos->sp.transformx / infos->sp.transformy));
	infos->sp.spriteheight = abs((int)(infos->resy / (infos->sp.transformy)));
	infos->sp.drawstarty = -infos->sp.spriteheight / 2 + infos->resy / 2;
	if (infos->sp.drawstarty < 0)
		infos->sp.drawstarty = 0;
	infos->sp.drawendy = infos->sp.spriteheight / 2 + infos->resy / 2;
	if (infos->sp.drawendy >= infos->resy)
		infos->sp.drawendy = infos->resy - 1;
	infos->sp.spritewidth = abs((int)(infos->resy / (infos->sp.transformy)));
	infos->sp.drawstartx = -infos->sp.spritewidth / 2 + infos->sp.spritescreenx;
	if (infos->sp.drawstartx < 0)
		infos->sp.drawstartx = 0;
	infos->sp.drawendx = infos->sp.spritewidth / 2 + infos->sp.spritescreenx;
	if (infos->sp.drawendx >= infos->resx)
		infos->sp.drawendx = infos->resx - 1;
}

void	sprite(t_infos *infos)
{
	int	i;

	sort_sprite(infos);
	i = 0;
	while (i < infos->sp.nbsprites)
	{
		calculs_sprite(infos, i);
		infos->sp.stripe = infos->sp.drawstartx;
		while (infos->sp.stripe < infos->sp.drawendx)
		{
			infos->sp.texx = (int)(256 * (infos->sp.stripe
				- (-infos->sp.spritewidth / 2 + infos->sp.spritescreenx))
				* infos->textures[4].img_width / infos->sp.spritewidth) / 256;
			if (infos->sp.transformy > 0 && infos->sp.stripe > 0
				&& infos->sp.stripe < infos->resx
				&& infos->sp.transformy < infos->sp.zbuffer[infos->sp.stripe])
				drawsprite(infos);
			infos->sp.stripe++;
		}
		i++;
	}
}
