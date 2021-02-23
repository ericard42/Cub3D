/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:39:32 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/02/23 14:30:02 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		infos_init(t_infos *infos)
{
    infos->resx = 0;
    infos->resy = 0;
    infos->fr = -1;
	infos->fg = -1;
	infos->fb = -1;
	infos->cr = -1;
	infos->cg = -1;
    infos->cb = -1;
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