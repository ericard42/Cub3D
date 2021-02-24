/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 12:11:59 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/02/24 14:15:34 by ericard@stu      ###   ########.fr       */
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

int		verify_text(char *texture)
{
	int		fd;
	int		i;

	i = 0;
	while(texture[i] == '.' && (texture[i + 1] == '/' || texture[i + 1] == '.'))
				i++;
	while (texture[i] != '.')
		{
			if (texture[i] == '\0')
				return (0);
			i++;
		}
	if (texture[i + 1] == 'x' && texture[i + 2] == 'p' && texture[i + 3] == 'm'
		&& texture[i + 4] == '\0')
	{	
		fd = open(texture, O_RDONLY);
		if (fd == -1)
			return (0);
	}
	else
		return (0);
	return (1);
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
	{
		free(str);
		errors("Probleme de malloc", infos);
	}
	while(str[i] != '\0')
	{
		texture[j] = str[i];
		i++;
		j++;
	}
	texture[j] = '\0';
	if (verify_text(texture) == 0)
	{
		free(str);
		errors("Probleme de texture", infos);
	}
	return (texture);
}

void	textures(t_infos *infos, char *str)
{
	if(str[0] == 'S' && str[1] != 'O')
	{
		if (infos->s != NULL)
		{
			free(str);
			errors("Parametres en double", infos);
		}
		infos->s = pars_text(str, 1, infos);
	}
	if(str[0] == 'N' && str[1] == 'O')
	{
		if (infos->no != NULL)
		{
			free(str);
			errors("Parametres en double", infos);
		}
		infos->no = pars_text(str, 2, infos);
	}
	if(str[0] == 'S' && str[1] == 'O')
	{
		if (infos->so != NULL)
		{
			free(str);
			errors("Parametres en double", infos);
		}
		infos->so = pars_text(str, 2, infos);
	}
	if(str[0] == 'W' && str[1] == 'E')
	{
		if (infos->we != NULL)
		{
			free(str);
			errors("Parametres en double", infos);
		}
		infos->we = pars_text(str, 2, infos);
	}
	if(str[0] == 'E' && str[1] == 'A')
	{
		if (infos->ea != NULL)
		{
			free(str);
			errors("Parametres en double", infos);
		}
		infos->ea = pars_text(str, 2, infos);
	}
}
