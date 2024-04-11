/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:14:26 by dkreise           #+#    #+#             */
/*   Updated: 2024/04/11 12:00:56 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_close(t_map *map)
{
	mlx_destroy_window(map->img.mlx, map->img.win);
	exit(1);
	return (0);
}

int	key_hook(int key, t_map *map)
{
	if (key == ESC)
		ft_close(map);
	if (key == ARROW_LEFT)
		map->mov->arrow_left = 1;
	if (key == ARROW_RIGHT)
		map->mov->arrow_right = 1;
	if (key == W)
		map->mov->w_key = 1;
	if (key == A)
		map->mov->a_key = 1;
	if (key == S)
		map->mov->s_key = 1;
	if (key == D)
		map->mov->d_key = 1;
	return (0);
}

void	key_hook_rotate(t_map *map)
{
	float	oldxdir;
	float	oldxplane;

	if (map->mov->arrow_left == 1)
	{
		oldxdir = map->xdir;
		map->xdir = map->xdir * cosf(ROTATE) - map->ydir * sinf(ROTATE);
		map->ydir = oldxdir * sinf(ROTATE) + map->ydir * cosf(ROTATE);
		oldxplane = map->xplane;
		map->xplane = map->xplane * cosf(ROTATE) - map->yplane * sinf(ROTATE);
		map->yplane = oldxplane * sinf(ROTATE) + map->yplane * cosf(ROTATE);
	}
	if (map->mov->arrow_right == 1)
	{
		oldxdir = map->xdir;
		map->xdir = map->xdir * cosf(-ROTATE) - map->ydir * sinf(-ROTATE);
		map->ydir = oldxdir * sinf(-ROTATE) + map->ydir * cosf(-ROTATE);
		oldxplane = map->xplane;
		map->xplane = map->xplane * cosf(-ROTATE) - map->yplane * sinf(-ROTATE);
		map->yplane = oldxplane * sinf(-ROTATE) + map->yplane * cosf(-ROTATE);
	}
}

void	key_hook_move(t_map *map)
{
	if (map->mov->w_key == 1)
		w_hook(map);
	if (map->mov->a_key == 1)
		a_hook(map);
	if (map->mov->s_key == 1)
		s_hook(map);
	if (map->mov->d_key == 1)
		d_hook(map);
}

int	key_hook_release(int key, t_map *map)
{
	if (key == ESC)
		ft_close(map);
	if (key == ARROW_LEFT)
		map->mov->arrow_left = 0;
	if (key == ARROW_RIGHT)
		map->mov->arrow_right = 0;
	if (key == W)
		map->mov->w_key = 0;
	if (key == A)
		map->mov->a_key = 0;
	if (key == S)
		map->mov->s_key = 0;
	if (key == D)
		map->mov->d_key = 0;
	return (0);
}
