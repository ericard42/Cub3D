/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_res.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:48:26 by ericard           #+#    #+#             */
/*   Updated: 2021/03/29 15:48:28 by ericard          ###   ########.fr       */
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
	{
		free(str);
		errors("Resolution incorrecte", infos);
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		ret = 10 * ret + (str[*i] - '0');
		*i += 1;
	}
	return (ret);
}

void	resolution(t_infos *infos, char *str)
{
    int	i;

    i = 0;
    if (str[i] == 'R')
    {
		if (infos->resx != 0 && infos->resy != 0)
		{
			free(str);
			errors("Parametres en double", infos);
		}
		i++;
        infos->resx = atoi_res(str, &i, infos);
		infos->resy = atoi_res(str, &i, infos);
		if (str[i] != '\0')
		{
			free(str);
			errors("Resolution incorrecte", infos);
		}
    }
}
