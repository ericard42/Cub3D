/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:43:47 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/03/18 16:43:10 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_infos *infos, int x, int y, int color)
{
	char *dst;

	dst = (char *)infos->mlx.addr + y * (infos->mlx.line_length + x * (infos->mlx.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}