/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 12:30:08 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/03/02 12:41:31 by ericard@stu      ###   ########.fr       */
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
	if (str[*i] == '-' || str[*i] == '+')
	{
		free(str);
		errors("Couleurs incorrectes", infos);
	}
	if (str[*i] == '\0')
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

void	colors(t_infos *infos, char *str)
{
	int	i;

    i = 0;
    if (str[i] == 'F')
    {
		if (infos->f.value != -1)
		{
			free(str);
			errors("Parametres en double", infos);
		}
		i++;
        infos->f.r = atoi_colors(str, &i, infos);
		colors_comma(str, &i, infos);
		infos->f.g= atoi_colors(str, &i, infos);
		colors_comma(str, &i, infos);
		infos->f.b= atoi_colors(str, &i, infos);
		if (str[i] != '\0')
		{
			free(str);
			errors("Couleurs du sol incorrectes", infos);
		}
		infos->f.value = infos->f.r * 65536 + infos->f.g * 256 + infos->f.b;
    }
	if (str[i] == 'C')
	{
		if (infos->c.value != -1)
		{
			free(str);
			errors("Parametres en double", infos);
		}
		i++;
        infos->c.r = atoi_colors(str, &i, infos);
		colors_comma(str, &i, infos);
		infos->c.g= atoi_colors(str, &i, infos);
		colors_comma(str, &i, infos);
		infos->c.b= atoi_colors(str, &i, infos);
		if (str[i] != '\0')
		{
			free(str);
			errors("Couleurs du plafond incorrectes", infos);
		}
		infos->c.value = infos->c.r * 65536 + infos->c.g * 256 + infos->c.b;
	}
}