/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard@student.42.fr <ericard>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:01:27 by ericard@stu       #+#    #+#             */
/*   Updated: 2021/03/04 21:50:27 by ericard@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int keycode, t_infos *infos)
{
	if (keycode == KEY_ESC)
		ft_close(infos);
	if (keycode == KEY_W)
		key_w_s(infos, 'w');
	if (keycode == KEY_S)
		key_w_s(infos, 's');
	if (keycode == KEY_A)
		if (infos->map[infos->departy][infos->departx - 1] != '1')
			infos->departx--;
	if (keycode == KEY_D)
		if (infos->map[infos->departy][infos->departx + 1] != '1')
			infos->departx++;
	return (1);
}