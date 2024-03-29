/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:49:02 by ericard           #+#    #+#             */
/*   Updated: 2021/03/30 12:57:11 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	which_texture(t_infos *infos)
{
	if (infos->ray.side == 0 && infos->ray.raydirx < 0)
		infos->tex.tex = 0;
	if (infos->ray.side == 0 && infos->ray.raydirx >= 0)
		infos->tex.tex = 1;
	if (infos->ray.side == 1 && infos->ray.raydiry < 0)
		infos->tex.tex = 2;
	if (infos->ray.side == 1 && infos->ray.raydiry >= 0)
		infos->tex.tex = 3;
}

void	calculs_print_tex(t_infos *infos)
{
	if (infos->ray.side == 0)
		infos->tex.wallx = infos->ray.posy + infos->ray.perpwalldist
			* infos->ray.raydiry;
	else
		infos->tex.wallx = infos->ray.posx + infos->ray.perpwalldist
			* infos->ray.raydirx;
	infos->tex.wallx -= floor(infos->tex.wallx);
	infos->tex.texx = (int)(infos->tex.wallx
		* (double)(infos->textures[infos->tex.tex].img_width));
	if (infos->ray.side == 0 && infos->ray.raydirx > 0)
		infos->tex.texx = infos->textures[infos->tex.tex].img_width
			- infos->tex.texx - 1;
	if (infos->ray.side == 1 && infos->ray.raydiry < 0)
		infos->tex.texx = infos->textures[infos->tex.tex].img_width
			- infos->tex.texx - 1;
	infos->tex.step = 1.0 * infos->textures[infos->tex.tex].img_height
		/ infos->ray.lineheight;
	infos->tex.texpos = (infos->ray.drawstart - infos->resy / 2
		+ infos->ray.lineheight / 2) * infos->tex.step;
}

void	print_texture(t_infos *infos, int i)
{
	which_texture(infos);
	calculs_print_tex(infos);
	i = infos->ray.drawstart;
	while (i < infos->ray.drawend)
	{
		infos->tex.texy = (int)infos->tex.texpos &
			(infos->textures[infos->tex.tex].img_height - 1);
		infos->tex.texpos += infos->tex.step;
		my_mlx_pixel_put(infos, infos->ray.x, i,
			infos->textures[infos->tex.tex].addr[infos->tex.texy
			* infos->textures[infos->tex.tex].img_height + infos->tex.texx]);
		i++;
	}
}

void	print_columns(t_infos *infos)
{
	int i;
	int j;

	j = 0;
	i = infos->ray.drawend;
	while (j < infos->ray.drawstart)
	{
		my_mlx_pixel_put(infos, infos->ray.x, j, infos->c.value);
		j++;
	}
	if (j <= infos->ray.drawend)
		print_texture(infos, j);
	j = i;
	while (j < infos->resy)
	{
		my_mlx_pixel_put(infos, infos->ray.x, j, infos->f.value);
		j++;
	}
}
