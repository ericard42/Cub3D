/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:49:16 by ericard           #+#    #+#             */
/*   Updated: 2021/03/30 13:25:24 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_two(t_infos *infos, int fd)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 54 + 4 * infos->resx * infos->resy;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 4);
	tmp = 14;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &infos->resx, 4);
	write(fd, &infos->resy, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &infos->mlx.bits_per_pixel, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

void	save(t_infos *infos)
{
	int	fd;
	int	x;
	int	y;

	if ((fd = open("./save.bmp", O_RDWR | O_CREAT, S_IRWXU)) == -1)
		errors("Impossible de creer .bmp", infos);
	save_two(infos, fd);
	y = infos->resy;
	while (y >= 0)
	{
		x = 0;
		while (x < infos->resx)
		{
			write(fd, &infos->mlx.addr[y * infos->mlx.line_length / 4 + x], 4);
			x++;
		}
		y--;
	}
	infos->save = 0;
	close(fd);
	ft_close(infos);
}
