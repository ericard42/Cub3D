/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericard <ericard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:47:33 by ericard           #+#    #+#             */
/*   Updated: 2021/03/30 17:33:48 by ericard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int keycode, t_infos *infos)
{
	if (keycode == KEY_ESC)
		ft_close(infos);
	if (keycode == KEY_W)
		infos->move.w = 1;
	if (keycode == KEY_S)
		infos->move.s = 1;
	if (keycode == KEY_A)
		infos->move.a = 1;
	if (keycode == KEY_D)
		infos->move.d = 1;
	if (keycode == KEY_RIGHT)
		infos->move.right = 1;
	if (keycode == KEY_LEFT)
		infos->move.left = 1;
	return (1);
}

int		key_release(int keycode, t_infos *infos)
{
	if (keycode == KEY_W)
		infos->move.w = 0;
	if (keycode == KEY_S)
		infos->move.s = 0;
	if (keycode == KEY_A)
		infos->move.a = 0;
	if (keycode == KEY_D)
		infos->move.d = 0;
	if (keycode == KEY_RIGHT)
		infos->move.right = 0;
	if (keycode == KEY_LEFT)
		infos->move.left = 0;
	return (1);
}
