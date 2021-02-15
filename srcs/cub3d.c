/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:59:05 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/02/13 21:18:43 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vrf_file(char *file)
{
	int i;

	i = 0;
	while (file[i] != '.')
		{
			if (file[i] == '\0')
				errors();
			i++;
		}
	if (file[i + 1] == 'c' && file[i + 2] == 'u' && file[i + 3] == 'b'
		&& file[i + 4] == '\0')
		parsing(file);
	else
		errors();
}

int		main(int ac, char **av)
{
	if (ac == 2)
		vrf_file(av[1]);
	else
		errors();
}