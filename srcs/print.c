/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:22:04 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/03/19 15:50:02 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	which_texture(t_infos *infos)
{
	if (infos->ray.side == 0 && infos->ray.raydirx < 0)
		infos->tex.tex = 4;
	if (infos->ray.side == 0 && infos->ray.raydirx >= 0)
		infos->tex.tex = 4;
	if (infos->ray.side == 1 && infos->ray.raydiry < 0)
		infos->tex.tex = 4;
	if (infos->ray.side == 1 && infos->ray.raydiry >= 0)
		infos->tex.tex = 4;
}

void	print_texture(t_infos *infos, int i)
{
	//int color;

	//color = 0;
	which_texture(infos);
	if (infos->ray.side == 0)
		infos->tex.wallx = infos->ray.posy + infos->ray.perpwalldist * infos->ray.raydiry;
	else
		infos->tex.wallx = infos->ray.posx + infos->ray.perpwalldist * infos->ray.raydirx;
	infos->tex.wallx -= floor(infos->tex.wallx);
	infos->tex.texx = (int)(infos->tex.wallx * (double)(infos->textures[infos->tex.tex].img_width));
	if (infos->ray.side == 0 && infos->ray.raydirx > 0)
		infos->tex.texx = infos->textures[infos->tex.tex].img_width - infos->tex.texx - 1;
	if (infos->ray.side == 1 && infos->ray.raydiry < 0)
		infos->tex.texx = infos->textures[infos->tex.tex].img_width - infos->tex.texx - 1;
	infos->tex.step = 1.0 * infos->textures[infos->tex.tex].img_height / infos->ray.lineheight;
	infos->tex.texpos = (infos->ray.drawstart - infos->resy / 2 + infos->ray.lineheight / 2) * infos->tex.step;
	i = infos->ray.drawstart;
	while (i < infos->ray.drawend)
	{
		infos->tex.texy = (int)infos->tex.texpos & (infos->textures[infos->tex.tex].img_height - 1);
		infos->tex.texpos += infos->tex.step;
		//color = infos->textures[infos->tex.tex].addr[infos->textures[infos->tex.tex].img_height * infos->tex.texy + infos->tex.texx];
		//my_mlx_pixel_put(infos, infos->ray.x, i, color);
		my_mlx_pixel_put(infos, infos->ray.x, i, infos->textures[infos->tex.tex].addr[infos->tex.texy * infos->textures[infos->tex.tex].img_height + infos->tex.texx]);
		//infos->mlx.addr[i *infos->mlx.line_length / 4 + infos->ray.x] = infos->textures[infos->tex.tex].addr[infos->tex.texy * infos->textures[infos->tex.tex].line_length / 4 + infos->tex.texx];
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
	/*while (i <= infos->ray.drawend)
	{
		if (infos->ray.side == 0 && infos->ray.raydirx < 0)
			my_mlx_pixel_put(infos, infos->ray.x, i, 0x848274);
		if (infos->ray.side == 0 && infos->ray.raydirx >= 0)
			my_mlx_pixel_put(infos, infos->ray.x, i, 0x728394);
		if (infos->ray.side == 1 && infos->ray.raydiry < 0)
			my_mlx_pixel_put(infos, infos->ray.x, i, 0x202973);
		if (infos->ray.side == 1 && infos->ray.raydiry >= 0)
			my_mlx_pixel_put(infos, infos->ray.x, i, 0x293847);
		i++;
	}*/
	j = i;
	while (j < infos->resy)
	{
		my_mlx_pixel_put(infos, infos->ray.x, j, infos->f.value);
		j++;
	}
}
