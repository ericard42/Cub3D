/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:54:42 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/03/25 15:31:15 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save(t_infos *infos)
{
	int		fd;
	int		tmp;
	int		x;
	int 	y;

	if ((fd = open("./save.bmp", O_CREAT | O_RDWR)) == -1)
		errors("Impossible de creer .bmp", infos);
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
	system("chmod 777 save.bmp");
	infos->save = 0;
}