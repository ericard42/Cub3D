/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:03:18 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/02/19 15:05:57 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		textlen(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(str[i] != '.')
		i++;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

char	*pars_text(char *str, int i)
{
	int		j;
	char	*texture;

	j = 0;
	while (str[i] != '.')
	{
		if (str[i] != '.' && str[i] != ' ')
			errors("Textures incorrectes");
		i++;
	}
	if (!(texture = (char*)(malloc(sizeof(char) * (textlen(str) + 1)))))
		errors("Probleme de malloc");
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
			errors("Parametres en double");
		infos->s = pars_text(str, 1);
	}
	if(str[0] == 'N' && str[1] == 'O')
	{
		if (infos->no != NULL)
			errors("Parametres en double");
		infos->no = pars_text(str, 2);
	}
	if(str[0] == 'S' && str[1] == 'O')
	{
		if (infos->so != NULL)
			errors("Parametres en double");
		infos->so = pars_text(str, 2);
	}
	if(str[0] == 'W' && str[1] == 'E')
	{
		if (infos->we != NULL)
			errors("Parametres en double");
		infos->we = pars_text(str, 2);
	}
	if(str[0] == 'E' && str[1] == 'A')
	{
		if (infos->ea != NULL)
			errors("Parametres en double");
		infos->ea = pars_text(str, 2);
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
        resolution(&infos, str);
		colors(&infos, str);
		textures(&infos, str);
		size_map(&infos, str);
        free(str);
	}
	close(fd);
	map_parse(&infos, file);
	map_is_valid(infos);
}
