/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:23:16 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/02/15 13:56:27 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		atoi_res(char *str, int *i)
{
	int	ret;

	ret = 0;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		*i += 1;
	if (str[*i] == '-' || str[*i] == '+')
		errors("Resolution incorrecte");
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		ret = 10 * ret + (str[*i] - '0');
		*i += 1;
	}
	return (ret);
}

int		atoi_colors(char *str, int *i)
{
	int	ret;

	ret = 0;
	while (str[*i] == ' ' || str[*i] == ','
			|| (str[*i] >= 9 && str[*i] <= 13))
		*i += 1;
	if (str[*i] == '-' || str[*i] == '+')
		errors("Couleurs incorrectes");
	if (str[*i] == '\0')
		errors("Couleurs incorrectes");
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		ret = 10 * ret + (str[*i] - '0');
		*i += 1;
	}
	if (ret > 255)
		errors("Couleurs incorrectes");
	return (ret);
}

void	resolution(t_infos *infos, char *str)
{
    int	i;

    i = 0;
    if (str[i] == 'R')
    {
		i++;
        infos->resx = atoi_res(str, &i);
		infos->resy = atoi_res(str, &i);
		if (str[i] != '\0')
			errors("Resolution incorrecte");
    }
}

void	colors(t_infos *infos, char *str)
{
	int	i;

    i = 0;
    if (str[i] == 'F')
    {
		i++;
        infos->fr = atoi_colors(str, &i);
		infos->fg= atoi_colors(str, &i);
		infos->fb= atoi_colors(str, &i);
		if (str[i] != '\0')
			errors("Couleurs du sol incorrectes");
    }
	if (str[i] == 'C')
	{
		i++;
        infos->cr = atoi_colors(str, &i);
		infos->cg= atoi_colors(str, &i);
		infos->cb= atoi_colors(str, &i);
		if (str[i] != '\0')
			errors("Couleurs du plafond incorrectes");
	}
}
