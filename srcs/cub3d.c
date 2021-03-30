/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:46:47 by ericard           #+#    #+#             */
/*   Updated: 2021/03/30 17:30:26 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vrf_file(char *file, t_infos *infos)
{
	int i;

	i = 0;
	while (file[i] == '.' && (file[i + 1] == '/' || file[i + 1] == '.'))
		i++;
	while (file[i] != '.')
	{
		if (file[i] == '\0')
		{
			printf("Error\nErreur de fichier\n");
			exit(0);
		}
		i++;
	}
	if (file[i + 1] == 'c' && file[i + 2] == 'u' && file[i + 3] == 'b'
		&& file[i + 4] == '\0')
		parsing(file, infos);
	else
	{
		printf("Error\nErreur de fichier\n");
		exit(0);
	}
}

int		is_save(char *str)
{
	if (str[0] == '-' && str[1] == '-' && str[2] == 's' && str[3] == 'a'
		&& str[4] == 'v' && str[5] == 'e' && str[6] == '\0')
		return (1);
	else
		return (0);
}

int		main(int ac, char **av)
{
	t_infos	infos;

	infos_init(&infos);
	if (ac == 2 || (ac == 3 && is_save(av[2]) == 1))
	{
		if (ac == 3)
			infos.save = 1;
		vrf_file(av[1], &infos);
	}
	else
	{
		printf("Error\nArguments invalides\n");
		exit(0);
	}
}
