/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:59:05 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/02/24 16:14:16 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vrf_file(char *file, t_infos *infos)
{
	int i;

	i = 0;
	while(file[i] == '.' && (file[i + 1] == '/' || file[i + 1] == '.'))
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

int		main(int ac, char **av)
{
	t_infos	infos;

	infos_init(&infos);
	if (ac == 2)
		vrf_file(av[1], &infos);
	else
	{
		printf("Error\nErreur de fichier\n");
		exit(0);
	}
}