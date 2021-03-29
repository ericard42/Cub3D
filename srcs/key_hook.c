/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:47:33 by ericard           #+#    #+#             */
/*   Updated: 2021/03/29 15:47:35 by ericard          ###   ########.fr       */
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
		key_a_d(infos, 'a');
	if (keycode == KEY_D)
		key_a_d(infos, 'd');
	if (keycode == KEY_RIGHT)
		key_left_right(infos, 'r');
	if (keycode == KEY_LEFT)
		key_left_right(infos, 'l');
	return (1);
}