/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:39:32 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/02/03 16:57:33 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_infos		infos_init(void)
{
    t_infos		infos;

    infos.resx = 0;
    infos.resy = 0;
    infos.f = -1;
    infos.c = -1;
    infos.no = NULL;
    infos.so = NULL;
    infos.we = NULL;
    infos.ea = NULL;
    infos.s = NULL;
    infos.map = NULL;

    return (infos);
}