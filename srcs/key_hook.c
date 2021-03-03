/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:01:27 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/03/03 12:07:05 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int keycode, t_infos *infos)
{
	if (keycode == KEY_ESC)
		ft_close(infos);
	if (keycode == KEY_W)
		if (infos->map[infos->departy - 1][infos->departx] != '1')
			infos->departy--;
	if (keycode == KEY_S)
		if (infos->map[infos->departy + 1][infos->departx] != '1')
			infos->departy++;
	if (keycode == KEY_A)
		if (infos->map[infos->departy][infos->departx - 1] != '1')
			infos->departx--;
	if (keycode == KEY_D)
		if (infos->map[infos->departy][infos->departx + 1] != '1')
			infos->departx++;
	return (1);
}