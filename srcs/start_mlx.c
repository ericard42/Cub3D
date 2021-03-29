/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:49:32 by ericard           #+#    #+#             */
/*   Updated: 2021/03/29 15:49:32 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	recup_textures(t_infos *infos)
{
	infos->textures[0].img = mlx_xpm_file_to_image(infos->mlx.mlx, infos->no,
					&infos->textures[0].img_width, &infos->textures[0].img_height);
	infos->textures[0].addr = (int *)mlx_get_data_addr (infos->textures[0].img,
					&infos->textures[0].bits_per_pixel,
					&infos->textures[0].line_length, &infos->textures[0].endian);
	infos->textures[1].img = mlx_xpm_file_to_image(infos->mlx.mlx, infos->so,
					&infos->textures[1].img_width, &infos->textures[1].img_height);
	infos->textures[1].addr = (int *)mlx_get_data_addr (infos->textures[1].img,
					&infos->textures[1].bits_per_pixel,
					&infos->textures[1].line_length, &infos->textures[1].endian);
	infos->textures[2].img = mlx_xpm_file_to_image(infos->mlx.mlx, infos->we,
					&infos->textures[2].img_width, &infos->textures[2].img_height);
	infos->textures[2].addr = (int *)mlx_get_data_addr (infos->textures[2].img,
					&infos->textures[2].bits_per_pixel,
					&infos->textures[2].line_length, &infos->textures[2].endian);
	infos->textures[3].img = mlx_xpm_file_to_image(infos->mlx.mlx, infos->ea,
					&infos->textures[3].img_width, &infos->textures[3].img_height);
	infos->textures[3].addr = (int *)mlx_get_data_addr (infos->textures[3].img,
					&infos->textures[3].bits_per_pixel,
					&infos->textures[3].line_length, &infos->textures[3].endian);
	infos->textures[4].img = mlx_xpm_file_to_image(infos->mlx.mlx, infos->s,
					&infos->textures[4].img_width, &infos->textures[4].img_height);
	infos->textures[4].addr = (int *)mlx_get_data_addr (infos->textures[4].img,
					&infos->textures[4].bits_per_pixel,
					&infos->textures[4].line_length, &infos->textures[4].endian);
}

void	mlx_start(t_infos *infos)
{
	depart_init(infos);
	init_sprite(infos);
	infos->mlx.mlx = mlx_init();
	mlx_get_screen_size(infos->mlx.mlx, &infos->mlx.screenx, &infos->mlx.screeny);
	infos->resx = (infos->resx < infos->mlx.screenx) ? infos->resx : infos->mlx.screenx;
	infos->resy = (infos->resy < infos->mlx.screeny) ? infos->resy : infos->mlx.screeny;
	if (!(infos->sprite.zbuffer = (double *)malloc(sizeof(double) * infos->resx)))
		errors("Soucis de malloc", infos);
	recup_textures(infos);
	infos->mlx.img = mlx_new_image(infos->mlx.mlx, infos->resx, infos->resy);
	infos->mlx.addr = (int *)mlx_get_data_addr(infos->mlx.img, &infos->mlx.bits_per_pixel, &infos->mlx.line_length, 
				&infos->mlx.endian);
	if (infos->save == 1)
		raycasting(infos);
	infos->mlx.win = mlx_new_window(infos->mlx.mlx, infos->resx, infos->resy,
					"cub3D");
	mlx_loop_hook(infos->mlx.mlx, raycasting, infos);
	mlx_hook(infos->mlx.win, 2, 1L << 0, key_press, infos);
	mlx_loop(infos->mlx.mlx);
}