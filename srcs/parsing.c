/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:03:18 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/02/08 17:18:32 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		atoi_res(char *str, int *i)
{
	int	nbr;

	nbr = 0;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		*i += 1;
	if (str[*i] == '-' || str[*i] == '+')
		exit(0);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nbr = 10 * nbr + (str[*i] - '0');
		*i += 1;
	}
	return (nbr);
}

int		atoi_coul(char *str, int *i)
{
	int	nbr;

	nbr = 0;
	while (str[*i] == ' ' || str[*i] == ','
			|| (str[*i] >= 9 && str[*i] <= 13))
		*i += 1;
	if (str[*i] == '-' || str[*i] == '+')
		exit(0);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nbr = 10 * nbr + (str[*i] - '0');
		*i += 1;
	}
	return (nbr);
}

void	resolution(t_infos *infos, char **str)
{
    int	i;

    i = 0;
    if (*str[i] == 'R')
    {
		i++;
        infos->resx = atoi_res(*str, &i);
		infos->resy = atoi_res(*str, &i);
    }
}

void	couleurs(t_infos *infos, char **str)
{
	int	i;

    i = 0;
    if (*str[i] == 'F')
    {
		i++;
        infos->fr = atoi_coul(*str, &i);
		infos->fg= atoi_coul(*str, &i);
		infos->fb= atoi_coul(*str, &i);
    }
	if (*str[i] == 'C')
	{
		i++;
        infos->cr = atoi_coul(*str, &i);
		infos->cg= atoi_coul(*str, &i);
		infos->cb= atoi_coul(*str, &i);
	}
}

void	parsing(char *file)
{
	int         fd;
    char        *str;
    int         ret;
    t_infos     infos;

    ret = 1;
    infos = infos_init();
    fd = open(file, O_RDONLY);
    while (ret == 1)
    {
        ret = get_next_line(fd, &str);
        resolution(&infos, &str);
		couleurs(&infos, &str);
        free(str);
    }
}