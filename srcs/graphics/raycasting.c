/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:14:36 by dkreise           #+#    #+#             */
/*   Updated: 2024/04/02 18:46:32 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_line(t_map map, int x, int start, int end, unsigned int color)
{
	int	y;

	y = 0;
	while (y < WIN_WIDTH)
	{
		if (x < map.rows * map.iminimap && y < map.cols * map.iminimap)
			;
		else if (y >= start && y <= end)
			my_mlx_pixel_put(map.img, x, y, color);
		else if (y < start)
			my_mlx_pixel_put(map.img, x, y, BLUE);
		else if (y > end)
			my_mlx_pixel_put(map.img, x, y, GREEN);
		else
			my_mlx_pixel_put(map.img, x, y, BLACK);
		y ++;
	}
}

void	draw(t_map map)
{
	int				x;
	t_data			d;
	unsigned int	color;

	x = 0;
	while (x < WIN_WIDTH)
	{
		d = init_data(map, x);
		while (d.hit == 0)
		{
			if (d.xsidedist < d.ysidedist)
			{
				d.xsidedist += d.xdeltadist;
				d.xmap += d.xstep;
				d.side = 0;
			}
			else
			{
				d.ysidedist += d.ydeltadist;
				d.ymap += d.ystep;
				d.side = 1;
			}
			if (map.board[d.xmap][d.ymap] == '1')
				d.hit = 1;
		}
		if (d.side == 0)
			d.walldist = (d.xsidedist - d.xdeltadist);
		else
			d.walldist = (d.ysidedist - d.ydeltadist);
		d.height_line = (int) (WIN_WIDTH / d.walldist) / 3;
		d.start_line = WIN_WIDTH / 2 - d.height_line / 2;
		if (d.start_line < 0)
			d.start_line = 0;
		d.end_line = WIN_WIDTH / 2 + d.height_line / 2;
		if (d.end_line > WIN_WIDTH)
			d.end_line = WIN_WIDTH - 1;
		color = COLOR;
		if (d.side == 1)
			color = color / 2;
		draw_line(map, x, d.start_line, d.end_line, color);
		x ++;
	}
}
