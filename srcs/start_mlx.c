/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:20:56 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/03/12 16:07:46 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	recup_textures(t_infos *infos)
{
	infos->textures[0].img = mlx_xpm_file_to_image(infos->mlx.mlx, infos->no,
					&infos->textures[0].img_width, &infos->textures[0].img_height);
	infos->textures[0].addr = mlx_get_data_addr (infos->textures[0].img,
					&infos->textures[0].bits_per_pixel,
					&infos->textures[0].line_length, &infos->textures[0].endian);
	infos->textures[1].img = mlx_xpm_file_to_image(infos->mlx.mlx, infos->so,
					&infos->textures[1].img_width, &infos->textures[1].img_height);
	infos->textures[1].addr = mlx_get_data_addr (infos->textures[1].img,
					&infos->textures[1].bits_per_pixel,
					&infos->textures[1].line_length, &infos->textures[1].endian);
	infos->textures[2].img = mlx_xpm_file_to_image(infos->mlx.mlx, infos->we,
					&infos->textures[2].img_width, &infos->textures[2].img_height);
	infos->textures[2].addr = mlx_get_data_addr (infos->textures[2].img,
					&infos->textures[2].bits_per_pixel,
					&infos->textures[2].line_length, &infos->textures[2].endian);
	infos->textures[3].img = mlx_xpm_file_to_image(infos->mlx.mlx, infos->ea,
					&infos->textures[3].img_width, &infos->textures[3].img_height);
	infos->textures[3].addr = mlx_get_data_addr (infos->textures[3].img,
					&infos->textures[3].bits_per_pixel,
					&infos->textures[3].line_length, &infos->textures[3].endian);
	infos->textures[4].img = mlx_xpm_file_to_image(infos->mlx.mlx, infos->s,
					&infos->textures[4].img_width, &infos->textures[4].img_height);
	infos->textures[4].addr = mlx_get_data_addr (infos->textures[4].img,
					&infos->textures[4].bits_per_pixel,
					&infos->textures[4].line_length, &infos->textures[4].endian);
}

int		minimap(t_infos	*infos)
{
	int		x;
	int		mapx;
	int		mapy;
	int		i;
	int		j;
	int		y;

	mapy = 0;
	x = 0;
	while (x < infos->lines)
	{
		i = 0;
		while (i < 10)
		{
			y = 0;
			mapx = 0;
			while (y < infos->columns)
			{
				j = 0;
				while (j < 10)
				{
					if ((int)infos->ray.posx == x && (int)infos->ray.posy == y)
						my_mlx_pixel_put(infos, mapx, mapy, 0xEB1DF5);
					else if (infos->map[x][y] == ' ' || infos->map[x][y] == '0')
						my_mlx_pixel_put(infos, mapx, mapy, 0x000000);
					else if (infos->map[x][y] == '1')
						my_mlx_pixel_put(infos, mapx, mapy, 0xFFFFFF);
					else if (infos->map[x][y] == '2')
						my_mlx_pixel_put(infos, mapx, mapy, 0x1CD9EC);
					j++;
					mapx++;
				}
				y++;
			}
			i++;
			mapy++;
		}
		x++;
	}
	mlx_put_image_to_window(infos->mlx.mlx, infos->mlx.win, infos->mlx.img, 0, 0);
	return (1);
}

void	mlx_start(t_infos *infos)
{
	struct_mlx_init(infos);
	depart_init(infos);
	infos->mlx.mlx = mlx_init();
	mlx_get_screen_size(infos->mlx.mlx, &infos->mlx.screenx, &infos->mlx.screeny);
	infos->resx = (infos->resx < infos->mlx.screenx) ? infos->resx : infos->mlx.screenx;
	infos->resy = (infos->resy < infos->mlx.screeny) ? infos->resy : infos->mlx.screeny;
	recup_textures(infos);
	infos->mlx.win = mlx_new_window(infos->mlx.mlx, infos->resx, infos->resy,
					"cub3D");
	infos->mlx.img = mlx_new_image(infos->mlx.mlx, infos->resx, infos->resy);
	infos->mlx.addr = mlx_get_data_addr(infos->mlx.img, &infos->mlx.bits_per_pixel, &infos->mlx.line_length, 
				&infos->mlx.endian);
	mlx_loop_hook(infos->mlx.mlx, raycasting, infos);
	mlx_hook(infos->mlx.win, 2, 1L << 0, key_press, infos);
	mlx_loop(infos->mlx.mlx);
}