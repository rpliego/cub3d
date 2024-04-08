/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:00:50 by dkreise           #+#    #+#             */
/*   Updated: 2024/04/08 19:41:32 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_minimap(t_map map, int x, int y, unsigned int color)
{
	int	i;
	int	j;
	int	k;

	i = map.iminimap;
	j = 0;
	k = 0;
	while (j < i)
	{
		k = 0;
		while (k < i)
		{
			my_mlx_pixel_put(map.img, x * i + j, y * i + k, color);
			k ++;
		}
		j ++;
	}
}

int		i_minimap(t_map *map)
{
	int	i;
	int	max;

	if (map->rows > map->cols)
		max = map->rows;
	else
		max = map->cols;
	i = 1;
	while (max * i < 100)
		i ++;
	return (i);
}

unsigned int	set_color(t_map map, int x, int y)
{
	unsigned int	color;

	color = 0;
	if (x == (int) map.xpos && y == (int) map.ypos)
		color = RED;
	else if (map.board[x][y] == '0')
		color = BLACK;
	else if (map.board[x][y] == '1')
		color = WHITE;
	return (color);
}

void	minimap(t_map map)
{
	int				x;
	int				y;
	unsigned int	color;
	
	x = 0;
	y = 0;
	while (x < map.rows + 1)
	{
		y = 0;
		while (y < map.cols)
		{
			color = set_color(map, x, y);
			draw_minimap(map, x, y, color);
			y ++;
		}
		x ++;
	}
}
