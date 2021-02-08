/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:59:05 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/02/05 23:05:35 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] != '.')
		{
			if (av[1][i] == '\0')
			{
				printf("Error\n");
				exit(0);
			}
			i++;
		}
		if (av[1][i + 1] == 'c' && av[1][i + 2] == 'u' && av[1][i + 3] == 'b'
			&& av[1][i + 4] == '\0')
			parsing(av[1]);
		else
			printf("Error\n");
	}
	else
		printf("Error\n");
}