/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors_res.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:30:02 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/02/23 14:23:40 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		atoi_res(char *str, int *i, t_infos *infos)
{
	int	ret;

	ret = 0;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		*i += 1;
	if (str[*i] == '-' || str[*i] == '+')
		errors("Resolution incorrecte", infos);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		ret = 10 * ret + (str[*i] - '0');
		*i += 1;
	}
	return (ret);
}

int		colors_comma(char *str, int *i, t_infos *infos)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		*i += 1;
	if (str[*i] == ',')
	{
		*i += 1;
		return (1);
	}
	else
		errors("Couleurs incorrectes", infos);
	return (0);
}

int		atoi_colors(char *str, int *i, t_infos *infos)
{
	int	ret;

	ret = 0;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		*i += 1;
	if (str[*i] == '-' || str[*i] == '+')
		errors("Couleurs incorrectes", infos);
	if (str[*i] == '\0')
		errors("Couleurs incorrectes", infos);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		ret = 10 * ret + (str[*i] - '0');
		*i += 1;
	}
	if (ret > 255 || ret < 0)
		errors("Couleurs incorrectes", infos);
	return (ret);
}

void	resolution(t_infos *infos, char *str)
{
    int	i;

    i = 0;
    if (str[i] == 'R')
    {
		if (infos->resx != 0 && infos->resy != 0)
			errors("Parametres en double", infos);
		i++;
        infos->resx = atoi_res(str, &i, infos);
		infos->resy = atoi_res(str, &i, infos);
		if (str[i] != '\0')
			errors("Resolution incorrecte", infos);
    }
}

void	colors(t_infos *infos, char *str)
{
	int	i;

    i = 0;
    if (str[i] == 'F')
    {
		if (infos->fr != -1)
			errors("Parametres en double", infos);
		i++;
        infos->fr = atoi_colors(str, &i, infos);
		colors_comma(str, &i, infos);
		infos->fg= atoi_colors(str, &i, infos);
		colors_comma(str, &i, infos);
		infos->fb= atoi_colors(str, &i, infos);
		if (str[i] != '\0')
			errors("Couleurs du sol incorrectes", infos);
    }
	if (str[i] == 'C')
	{
		if (infos->cr != -1)
			errors("Parametres en double", infos);
		i++;
        infos->cr = atoi_colors(str, &i, infos);
		colors_comma(str, &i, infos);
		infos->cg= atoi_colors(str, &i, infos);
		colors_comma(str, &i, infos);
		infos->cb= atoi_colors(str, &i, infos);
		if (str[i] != '\0')
			errors("Couleurs du plafond incorrectes", infos);
	}
}
