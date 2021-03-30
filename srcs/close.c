/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:46:28 by ericard           #+#    #+#             */
/*   Updated: 2021/03/30 17:03:27 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_close_two(t_infos *infos)
{
	if (infos->sp.spritedist != NULL)
		free(infos->sp.spritedist);
	if (infos->sp.order != NULL)
		free(infos->sp.order);
	if (infos->sp.zbuffer != NULL)
		free(infos->sp.zbuffer);
	if (infos->spos != NULL)
		free(infos->spos);
	exit(0);
}

int			ft_close(t_infos *infos)
{
	int	i;

	i = 0;
	if (infos->mlx.win != NULL)
		mlx_destroy_window(infos->mlx.mlx, infos->mlx.win);
	if (infos->no != NULL)
		free(infos->no);
	if (infos->so != NULL)
		free(infos->so);
	if (infos->ea != NULL)
		free(infos->ea);
	if (infos->we != NULL)
		free(infos->we);
	if (infos->s != NULL)
		free(infos->s);
	if (infos->map != NULL)
	{
		while (i < infos->lines)
		{
			free(infos->map[i]);
			i++;
		}
		free(infos->map);
	}
	ft_close_two(infos);
	return (1);
}
