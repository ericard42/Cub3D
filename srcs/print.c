/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:22:04 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/03/11 14:23:55 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	which_texture(t_infos *infos)
{
	if (infos->ray.side == 0 && infos->ray.raydirx < 0)
		infos->tex.tex = 0;
	if (infos->ray.side == 0 && infos->ray.raydirx >= 0)
		infos->tex.tex = 1;
	if (infos->ray.side == 1 && infos->ray.raydirx < 0)
		infos->tex.tex = 2;
	if (infos->ray.side == 1 && infos->ray.raydirx >= 0)
		infos->tex.tex = 3;
	if (infos->ray.side == 1)
		infos->tex.wallx = infos->ray.posy + infos->ray.perpwalldist * infos->ray.raydiry;
	else
		infos->tex.wallx = infos->ray.posx + infos->ray.perpwalldist * infos->ray.raydirx;
	infos->tex.wallx -= floor((infos->tex.wallx));
}

void	print_texture(t_infos *infos, int i)
{
	which_texture(infos);
	i = infos->ray.drawstart;
	infos->tex.texx = (int)(infos->tex.wallx * (double)infos->textures[infos->tex.tex]. img_width);
	if (infos->ray.side == 0 && infos->ray.raydirx > 0)
		infos->tex.texx = infos->textures[infos->tex.tex].img_width - infos->tex.texx - 1;
	if (infos->ray.side == 1 && infos->ray.raydirx < 0)
		infos->tex.texx = infos->textures[infos->tex.tex].img_width - infos->tex.texx - 1;
	infos->tex.texpos = (infos->ray.drawstart - infos->resy / 2 + infos->ray.lineheight / 2) * infos->tex.step;
	infos->tex.step = 1 * infos->textures[0].img_height / infos->ray.lineheight;
	infos->tex.texpos = (infos->ray.drawstart - infos->resy / 2 + infos->ray.lineheight / 2) * infos->tex.step;
	while (i <= infos->ray.drawend)
	{
		infos->tex.texy = (int)infos->tex.texpos & (infos->textures[infos->tex.tex].img_height - 1);
		infos->tex.texpos += infos->tex.step;
		infos->mlx.addr[i * infos->mlx.line_length / 4 + infos->ray.x] = infos->textures[infos->tex.tex].addr[infos->tex.texy * infos->textures[infos->tex.tex].line_length / 4 + infos->tex.texx];
		i++;
	}
}

void	print_columns(t_infos *infos)
{
	int i;

	i = 0;
	while (i < infos->ray.drawstart)
	{
		my_mlx_pixel_put(infos, infos->ray.x, i, infos->c.value);
		i++;
	}
	/*if (i <= infos->ray.drawend)
		print_texture(infos, i);*/
	while (i <= infos->ray.drawend)
	{
		if (infos->ray.side == 0 && infos->ray.raydirx < 0)
			my_mlx_pixel_put(infos, infos->ray.x, i, 0x848274);
		if (infos->ray.side == 0 && infos->ray.raydirx >= 0)
			my_mlx_pixel_put(infos, infos->ray.x, i, 0x728394);
		if (infos->ray.side == 1 && infos->ray.raydirx < 0)
			my_mlx_pixel_put(infos, infos->ray.x, i, 0x202973);
		if (infos->ray.side == 1 && infos->ray.raydirx >= 0)
			my_mlx_pixel_put(infos, infos->ray.x, i, 0x293847);
		i++;
	}
	while (i < infos->resy)
	{
		my_mlx_pixel_put(infos, infos->ray.x, i, infos->f.value);
		i++;
	}
}
