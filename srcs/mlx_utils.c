/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:47:48 by ericard           #+#    #+#             */
/*   Updated: 2021/03/29 16:14:18 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_infos *infos, int x, int y, int color)
{
	char *dst;

	dst = (char *)infos->mlx.addr + y * infos->mlx.line_length + x
		* (infos->mlx.bits_per_pixel / 8);
	*(unsigned int*)dst = color;
}
