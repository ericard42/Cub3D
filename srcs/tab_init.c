/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:49:45 by ericard           #+#    #+#             */
/*   Updated: 2021/03/30 14:56:48 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	depart_init_two(t_infos *infos)
{
	if (infos->depart == 'E')
	{
		infos->ray.dirx = 0;
		infos->ray.diry = 1;
		infos->ray.planx = 0.66;
		infos->ray.plany = 0;
	}
	if (infos->depart == 'W')
	{
		infos->ray.dirx = 0;
		infos->ray.diry = -1;
		infos->ray.planx = -0.66;
		infos->ray.plany = 0;
	}
}

void	depart_init(t_infos *infos)
{
	if (infos->depart == 'N')
	{
		infos->ray.dirx = -1;
		infos->ray.diry = 0;
		infos->ray.planx = 0;
		infos->ray.plany = 0.66;
	}
	if (infos->depart == 'S')
	{
		infos->ray.dirx = 1;
		infos->ray.diry = 0;
		infos->ray.planx = 0;
		infos->ray.plany = -0.66;
	}
	depart_init_two(infos);
	infos->ray.posx = (double)infos->departx + 0.5;
	infos->ray.posy = (double)infos->departy + 0.5;
}

void	infos_init(t_infos *infos)
{
	infos->resx = 0;
	infos->resy = 0;
	infos->f.r = -1;
	infos->f.g = -1;
	infos->f.b = -1;
	infos->f.value = -1;
	infos->c.r = -1;
	infos->c.g = -1;
	infos->c.b = -1;
	infos->c.value = -1;
	infos->no = NULL;
	infos->so = NULL;
	infos->we = NULL;
	infos->ea = NULL;
	infos->s = NULL;
	infos->map = NULL;
	infos->lines = 0;
	infos->columns = 0;
	infos->depart = '0';
	infos->departx = 0;
	infos->departy = 0;
	infos->save = 0;
	struct_mlx_init(infos);
}

void	struct_mlx_init(t_infos *infos)
{
	infos->mlx.mlx = NULL;
	infos->mlx.win = NULL;
	infos->mlx.img = NULL;
	infos->mlx.addr = NULL;
	infos->mlx.bits_per_pixel = 0;
	infos->mlx.line_length = 0;
	infos->mlx.endian = 0;
	infos->mlx.screenx = 0;
	infos->mlx.screeny = 0;
	infos->sp.spritedist = NULL;
	infos->sp.order = NULL;
	infos->sp.zbuffer = NULL;
	infos->spos = NULL;
}

void	init_sprite(t_infos *infos)
{
	int	i;
	int j;
	int s;

	i = -1;
	s = 0;
	if (!(infos->spos = malloc(sizeof(t_spritepos) * infos->sp.nbsprites)))
		errors("Probleme de malloc", infos);
	if (!(infos->sp.order = malloc(sizeof(int) * infos->sp.nbsprites)))
		errors("Probleme de malloc", infos);
	if (!(infos->sp.spritedist = malloc(sizeof(double) * infos->sp.nbsprites)))
		errors("Probleme de malloc", infos);
	while (++i < infos->lines)
	{
		j = -1;
		while (++j < infos->columns)
		{
			if (infos->map[i][j] == '2')
			{
				infos->spos[s].x = (double)i + 0.5;
				infos->spos[s].y = (double)j + 0.5;
				s++;
			}
		}
	}
}
