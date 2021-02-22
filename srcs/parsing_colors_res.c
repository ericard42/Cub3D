/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors_res.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:30:02 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/02/22 13:30:18 by ericard@stu      ###   ########.fr       */
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

int		colors_comma(char *str, int *i)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		*i += 1;
	if (str[*i] == ',')
	{
		*i += 1;
		return (1);
	}
	else
		errors("Couleurs incorrectes");
	return (0);
}

int		atoi_colors(char *str, int *i)
{
	int	ret;

	ret = 0;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
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
	if (ret > 255 || ret < 0)
		errors("Couleurs incorrectes");
	return (ret);
}

void	resolution(t_infos *infos, char *str)
{
    int	i;

    i = 0;
    if (str[i] == 'R')
    {
		if (infos->resx != 0 && infos->resy != 0)
			errors("Parametres en double");
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
		if (infos->fr != -1)
			errors("Parametres en double");
		i++;
        infos->fr = atoi_colors(str, &i);
		colors_comma(str, &i);
		infos->fg= atoi_colors(str, &i);
		colors_comma(str, &i);
		infos->fb= atoi_colors(str, &i);
		if (str[i] != '\0')
			errors("Couleurs du sol incorrectes");
    }
	if (str[i] == 'C')
	{
		if (infos->cr != -1)
			errors("Parametres en double");
		i++;
        infos->cr = atoi_colors(str, &i);
		colors_comma(str, &i);
		infos->cg= atoi_colors(str, &i);
		colors_comma(str, &i);
		infos->cb= atoi_colors(str, &i);
		if (str[i] != '\0')
			errors("Couleurs du plafond incorrectes");
	}
}
