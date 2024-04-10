/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:56:13 by dkreise           #+#    #+#             */
/*   Updated: 2024/04/10 18:00:32 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	w_hook(t_map *map)
{
	if (map->board[(int) (map->xpos + map->xdir * SPEED)][(int) map->ypos]
			!= '1')
		map->xpos += map->xdir * SPEED;
	if (map->board[(int) map->xpos][(int) (map->ypos + map->ydir * SPEED)]
			!= '1')
		map->ypos += map->ydir * SPEED;
}

void	a_hook(t_map *map)
{
	if (map->board[(int) (map->xpos - map->ydir * SPEED)][(int) map->ypos]
			!= '1')
		map->xpos -= map->ydir * SPEED;
	if (map->board[(int) map->xpos][(int) (map->ypos + map->xdir * SPEED)]
			!= '1')
		map->ypos += map->xdir * SPEED;
}

void	s_hook(t_map *map)
{
	if (map->board[(int) (map->xpos - map->xdir * SPEED)][(int) map->ypos]
			!= '1')
		map->xpos -= map->xdir * SPEED;
	if (map->board[(int) map->xpos][(int) (map->ypos - map->ydir * SPEED)]
			!= '1')
		map->ypos -= map->ydir * SPEED;
}

void	d_hook(t_map *map)
{
	if (map->board[(int) (map->xpos + map->ydir * SPEED)][(int) map->ypos]
			!= '1')
		map->xpos += map->ydir * SPEED;
	if (map->board[(int) map->xpos][(int) (map->ypos - map->xdir * SPEED)]
			!= '1')
		map->ypos -= map->xdir * SPEED;
}
