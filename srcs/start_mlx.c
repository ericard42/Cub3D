/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:20:56 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/03/03 12:01:44 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_infos *infos, int x, int y, int color)
{
	char *dst;

	dst = infos->mlx.addr + (y * infos->mlx.line_length + x *(infos->mlx.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
	y = 0;
	while (y < infos->lines)
	{
		i = 0;
		while (i < 10)
		{
			x = 0;
			mapx = 0;
			while (x < infos->columns)
			{
				j = 0;
				while (j < 10)
				{
					if (infos->departx == x && infos->departy == y)
						my_mlx_pixel_put(infos, mapx, mapy, 0xEB1DF5);
					else if (infos->map[y][x] == ' ' || infos->map[y][x] == '0')
						my_mlx_pixel_put(infos, mapx, mapy, 0x000000);
					else if (infos->map[y][x] == '1')
						my_mlx_pixel_put(infos, mapx, mapy, 0xFFFFFF);
					else if (infos->map[y][x] == '2')
						my_mlx_pixel_put(infos, mapx, mapy, 0x1CD9EC);
					j++;
					mapx++;
				}
				x++;
			}
			i++;
			mapy++;
		}
		y++;
	}
	mlx_put_image_to_window(infos->mlx.mlx, infos->mlx.win, infos->mlx.img, 0, 0);
	return (1);
}

void	mlx_start(t_infos *infos)
{
	struct_mlx_init(infos);
	infos->mlx.mlx = mlx_init();
	mlx_get_screen_size(infos->mlx.mlx, &infos->mlx.screenx, &infos->mlx.screeny);
	infos->resx = (infos->resx < infos->mlx.screenx) ? infos->resx : infos->mlx.screenx;
	infos->resy = (infos->resy < infos->mlx.screeny) ? infos->resy : infos->mlx.screeny;
	infos->mlx.win = mlx_new_window(infos->mlx.mlx, infos->resx, infos->resy,
					"cub3D");
	infos->mlx.img = mlx_new_image(infos->mlx.mlx, infos->resx, infos->resy);
	infos->mlx.addr = mlx_get_data_addr(infos->mlx.img, &infos->mlx.bits_per_pixel, &infos->mlx.line_length, 
				&infos->mlx.endian);
	mlx_loop_hook(infos->mlx.mlx, minimap, infos);
	mlx_hook(infos->mlx.win, 2, 1L << 0, key_press, infos);
	mlx_loop(infos->mlx.mlx);
}