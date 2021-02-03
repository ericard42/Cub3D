/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:03:18 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/02/03 16:09:36 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	resolution(t_infos infos, char **str)
{
    int	i;

    i = 0;
    if (*str[i] = 'R')
    {
        
    }
}

void	parsing(char *file)
{
	int         fd;
    char        **str;
    int         ret;
    t_infos     infos;

    ret = 1;
    infos = infos_init();
    fd = open(file, O_RDONLY);
    while (ret == 1)
    {
        ret = get_next_line(fd, &str);
        resolution(infos, &str);
        free(str);
    }
}