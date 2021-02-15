/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:03:18 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/02/15 14:02:32 by ericard@stu      ###   ########.fr       */
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

void	pars_text(char *str, char **texture, int i)
{
	int	j;

	j = 0;
	if (*texture != NULL)
		errors();
	while (str[i] != '.')
	{
		if (str[i] != '.' && str[i] != ' ')
			errors();
		i++;
	}
	if (!(*texture = (char *)(malloc(sizeof(char) * (textlen(str) + 1)))))
		errors();
	while(str[i] != '\0')
	{
		*texture[j] = str[i];
		i++;
		j++;
	}
	*texture[j] = '\0';
}

void	textures(t_infos *infos, char **str)
{
	if(*str[0] == 'S' && *str[1] != '0')
		pars_text(*str, &infos->s, 1);
	//if(*str[0] == 'N' && *str[1] == 'O')
	//	pars_text(*str, &infos->no, 2);
	//if(*str[0] == 'S' && *str[1] == 'O')
	//	pars_text(*str, &infos->so, 2);
	//if(*str[0] == 'W' && *str[1] == 'E')
	//	pars_text(*str, &infos->we, 2);
	//if(*str[0] == 'E' && *str[1] == 'A')
	//	pars_text(*str, &infos->ea, 2);
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
        resolution(&infos, &str);
		couleurs(&infos, &str);
		textures(&infos, &str);
        free(str);
	}
	printf("%s\n%s\n%s\n%s\n%s\n", infos.s, infos.so, infos.no, infos.we, infos.ea);
}
