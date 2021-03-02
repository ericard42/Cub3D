/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:39:32 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/03/02 12:28:25 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		infos_init(t_infos *infos)
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
}