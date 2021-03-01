/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:20:56 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/03/01 19:09:57 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int keycode, t_infos *infos)
{
	if (keycode == 0xFF1B)
		ft_close(infos);
	return (1);
}

void	mlx_start(t_infos *infos)
{
	infos->mlx.mlx = mlx_init();
	infos->mlx.win = mlx_new_window(infos->mlx.mlx, infos->resx, infos->resy,
					"cub3D");
	mlx_hook(infos->mlx.win, 2, 1L << 0, key_press, infos);
	mlx_loop(infos->mlx.mlx);
}