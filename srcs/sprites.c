/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:49:22 by ericard           #+#    #+#             */
/*   Updated: 2021/03/29 15:49:24 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprite(t_infos *infos)
{
	int		i;
	int		j;
	double	tmp;

	i = 0;
	while (i < infos->sprite.nbsprites)
	{
		infos->sprite.order[i] = i;
		infos->sprite.spritedist[i] = ((infos->ray.posx - infos->spos[i].x) * (infos->ray.posx - infos->spos[i].x) + (infos->ray.posy - infos->spos[i].y) * (infos->ray.posy - infos->spos[i].y));
		i++;
	}
	i = 0;
	while (i < infos->sprite.nbsprites)
	{
		j = 0;
		while (j < infos->sprite.nbsprites - 1)
		{
			if (infos->sprite.spritedist[j] < infos->sprite.spritedist[j + 1])
			{
				tmp = infos->sprite.spritedist[j];
				infos->sprite.spritedist[j] = infos->sprite.spritedist[j + 1];
				infos->sprite.spritedist[j + 1] = tmp;
				tmp = infos->sprite.order[j];
				infos->sprite.order[j] = infos->sprite.order[j + 1];
				infos->sprite.order[j + 1] = tmp;
			}
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

	y = infos->sprite.drawstarty;
	while (y < infos->sprite.drawendy)
	{
		d = (y) * 256 - infos->resy * 128 + infos->sprite.spriteheight * 128;
		texy = ((d * infos->textures[4].img_height) / infos->sprite.spriteheight) / 256;
		if (infos->textures[4].addr[texy * infos->textures[4].img_width + infos->sprite.texx] != -16777216)
			my_mlx_pixel_put(infos, infos->sprite.stripe, y, infos->textures[4].addr[texy * infos->textures[4].img_width + infos->sprite.texx]);
		y++;
	}
}

void	sprite(t_infos *infos)
{
	int	i;

	sort_sprite(infos);
	i = 0;
	while (i < infos->sprite.nbsprites)
	{
		infos->sprite.spritex = infos->spos[infos->sprite.order[i]].x - infos->ray.posx;
		infos->sprite.spritey = infos->spos[infos->sprite.order[i]].y - infos->ray.posy;
		infos->sprite.invdet = 1.0 / (infos->ray.planx * infos->ray.diry - infos->ray.dirx * infos->ray.plany);
		infos->sprite.transformx = infos->sprite.invdet * (infos->ray.diry * infos->sprite.spritex - infos->ray.dirx * infos->sprite.spritey);
		infos->sprite.transformy = infos->sprite.invdet * (-infos->ray.plany * infos->sprite.spritex + infos->ray.planx * infos->sprite.spritey);
		infos->sprite.spritescreenx = (int)((infos->resx / 2) * (1 + infos->sprite.transformx / infos->sprite.transformy));
		infos->sprite.spriteheight = abs((int)(infos->resy / (infos->sprite.transformy)));
		infos->sprite.drawstarty = -infos->sprite.spriteheight / 2 + infos->resy / 2;
		if (infos->sprite.drawstarty < 0)
			infos->sprite.drawstarty = 0;
		infos->sprite.drawendy = infos->sprite.spriteheight / 2 + infos->resy / 2;
		if (infos->sprite.drawendy >= infos->resy)
			infos->sprite.drawendy = infos->resy - 1;
		infos->sprite.spritewidth = abs((int)(infos->resy / (infos->sprite.transformy)));
		infos->sprite.drawstartx = -infos->sprite.spritewidth / 2 + infos->sprite.spritescreenx;
		if (infos->sprite.drawstartx < 0)
			infos->sprite.drawstartx = 0;
		infos->sprite.drawendx = infos->sprite.spritewidth / 2 + infos->sprite.spritescreenx;
		if (infos->sprite.drawendx >= infos->resx)
			infos->sprite.drawendx = infos->resx - 1;
		infos->sprite.stripe = infos->sprite.drawstartx;
		while (infos->sprite.stripe < infos->sprite.drawendx)
		{
			infos->sprite.texx = (int)(256 * (infos->sprite.stripe - (-infos->sprite.spritewidth / 2 + infos->sprite.spritescreenx)) * infos->textures[4].img_width / infos->sprite.spritewidth) / 256;
			if (infos->sprite.transformy > 0 && infos->sprite.stripe > 0 && infos->sprite.stripe < infos->resx && infos->sprite.transformy < infos->sprite.zbuffer[infos->sprite.stripe])
				drawsprite(infos);
			infos->sprite.stripe++;
		}
		i++;
	}
}