/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 12:11:59 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/02/23 14:25:13 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		textlen(char *str, int i)
{
	int j;

	j = 0;
	while(str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

char	*pars_text(char *str, int i, t_infos *infos)
{
	int		j;
	char	*texture;
	int		len;

	j = 0;
	len = textlen(str, i);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!(texture = (char*)(malloc(sizeof(char) * (len + 1)))))
		errors("Probleme de malloc", infos);
	while(str[i] != '\0')
	{
		texture[j] = str[i];
		i++;
		j++;
	}
	texture[j] = '\0';
	return (texture);
}

void	textures(t_infos *infos, char *str)
{
	if(str[0] == 'S' && str[1] != 'O')
	{
		if (infos->s != NULL)
			errors("Parametres en double", infos);
		infos->s = pars_text(str, 1, infos);
	}
	if(str[0] == 'N' && str[1] == 'O')
	{
		if (infos->no != NULL)
			errors("Parametres en double", infos);
		infos->no = pars_text(str, 2, infos);
	}
	if(str[0] == 'S' && str[1] == 'O')
	{
		if (infos->so != NULL)
			errors("Parametres en double", infos);
		infos->so = pars_text(str, 2, infos);
	}
	if(str[0] == 'W' && str[1] == 'E')
	{
		if (infos->we != NULL)
			errors("Parametres en double", infos);
		infos->we = pars_text(str, 2, infos);
	}
	if(str[0] == 'E' && str[1] == 'A')
	{
		if (infos->ea != NULL)
			errors("Parametres en double", infos);
		infos->ea = pars_text(str, 2, infos);
	}
}
