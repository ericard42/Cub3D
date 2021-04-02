/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:48:34 by ericard           #+#    #+#             */
/*   Updated: 2021/04/02 15:48:20 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		textlen(char *str, int i)
{
	int j;

	j = 0;
	while (str[i] == ' ' || str[i] == '\t')
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
	while (texture[i] == '.' && (texture[i + 1] == '/'
		|| texture[i + 1] == '.'))
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

	j = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!(texture = (char*)(malloc(sizeof(char) * (textlen(str, i) + 1)))))
	{
		free(str);
		errors("Probleme de malloc", infos);
	}
	while (str[i] != '\0')
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

void	double_textures(t_infos *infos, char *str, char *tex, char *par)
{
	if (tex != NULL)
	{
		free(str);
		printf("Error\nParametre '%s' en double\n", par);
		ft_close(infos);
	}
}

void	textures(t_infos *infos, char *str)
{
	if (str[0] == 'S' && str[1] != 'O')
	{
		double_textures(infos, str, infos->s, "S");
		infos->s = pars_text(str, 1, infos);
	}
	if (str[0] == 'N' && str[1] == 'O')
	{
		double_textures(infos, str, infos->no, "NO");
		infos->no = pars_text(str, 2, infos);
	}
	if (str[0] == 'S' && str[1] == 'O')
	{
		double_textures(infos, str, infos->so, "SO");
		infos->so = pars_text(str, 2, infos);
	}
	if (str[0] == 'W' && str[1] == 'E')
	{
		double_textures(infos, str, infos->we, "WE");
		infos->we = pars_text(str, 2, infos);
	}
	if (str[0] == 'E' && str[1] == 'A')
	{
		double_textures(infos, str, infos->ea, "EA");
		infos->ea = pars_text(str, 2, infos);
	}
}
