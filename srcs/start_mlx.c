/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:20:56 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/03/02 14:55:28 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int keycode, t_infos *infos)
{
	if (keycode == 0xFF1B)
		ft_close(infos);
	return (1);
}

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
				if (infos->map[y][x] == ' ' || infos->map[y][x] == '0')
					while (j < 10)
					{
						my_mlx_pixel_put(infos, mapx, mapy, 0x000000);
						j++;
						mapx++;
					}
				if (infos->map[y][x] == '1')
					while(j < 10)
					{	
						my_mlx_pixel_put(infos, mapx, mapy, 0xFFFFFF);
						j++;
						mapx++;
					}
				if (infos->map[y][x] == '2')
					while(j < 10)
					{
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
	return (1);
}

void	mlx_start(t_infos *infos)
{
	infos->mlx.addr = NULL;
	infos->mlx.img = NULL;
	infos->mlx.win = NULL;
	infos->mlx.mlx = NULL;
	infos->mlx.mlx = mlx_init();
	infos->mlx.win = mlx_new_window(infos->mlx.mlx, infos->resx, infos->resy,
					"cub3D");
	infos->mlx.img = mlx_new_image(infos->mlx.mlx, infos->resx, infos->resy);
	infos->mlx.addr = mlx_get_data_addr(infos->mlx.img, &infos->mlx.bits_per_pixel, &infos->mlx.line_length, 
				&infos->mlx.endian);
	minimap(infos);
	//mlx_loop_hook(infos->mlx.mlx, minimap, infos);
	mlx_put_image_to_window(infos->mlx.mlx, infos->mlx.win, infos->mlx.img, 0, 0);
	mlx_hook(infos->mlx.win, 2, 1L << 0, key_press, infos);
	mlx_loop(infos->mlx.mlx);
}