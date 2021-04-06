/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:48:02 by ericard           #+#    #+#             */
/*   Updated: 2021/04/06 11:58:42 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	{
		free(str);
		errors("Couleurs incorrectes", infos);
	}
	return (0);
}

int		atoi_colors(char *str, int *i, t_infos *infos)
{
	int	ret;

	ret = 0;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		*i += 1;
	if (str[*i] == '-' || str[*i] == '+' || str[*i] == '\0')
	{
		free(str);
		errors("Couleurs incorrectes", infos);
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		ret = 10 * ret + (str[*i] - '0');
		*i += 1;
	}
	if (ret > 255 || ret < 0)
	{
		free(str);
		errors("Couleurs incorrectes", infos);
	}
	return (ret);
}

void	colors_f(t_infos *infos, char *str)
{
	int	i;

	i = 1;
	if (infos->f.value != -1)
	{
		free(str);
		errors("Parametre 'F' en double", infos);
	}
	infos->f.r = atoi_colors(str, &i, infos);
	colors_comma(str, &i, infos);
	infos->f.g = atoi_colors(str, &i, infos);
	colors_comma(str, &i, infos);
	infos->f.b = atoi_colors(str, &i, infos);
	if (str[i] != '\0')
	{
		free(str);
		errors("Couleurs du sol incorrectes", infos);
	}
	infos->f.value = infos->f.r * 65536 + infos->f.g * 256 + infos->f.b;
}

void	colors_c(t_infos *infos, char *str)
{
	int	i;

	i = 1;
	if (infos->c.value != -1)
	{
		free(str);
		errors("Parametre 'C' en double", infos);
	}
	infos->c.r = atoi_colors(str, &i, infos);
	colors_comma(str, &i, infos);
	infos->c.g = atoi_colors(str, &i, infos);
	colors_comma(str, &i, infos);
	infos->c.b = atoi_colors(str, &i, infos);
	if (str[i] != '\0')
	{
		free(str);
		errors("Couleurs du plafond incorrectes", infos);
	}
	infos->c.value = infos->c.r * 65536 + infos->c.g * 256 + infos->c.b;
}

void	colors(t_infos *infos, char *str)
{
	int i;

	i = 0;
	if (str[i] == 'F')
		colors_f(infos, str);
	if (str[i] == 'C')
		colors_c(infos, str);
}
