/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:14:36 by dkreise           #+#    #+#             */
/*   Updated: 2024/04/09 17:07:25 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	tex_color(t_texture tex, int xtex, int ytex)
{
	char *pix;

	pix = tex.addr + (ytex * tex.line_len + xtex * (tex.bits_per_pixel / 8));
	return (*(int *)pix);
}

void	draw_line(t_map map, int x, t_data d)
{
	int	y;

	y = 0;
	while (y < WIN_WIDTH)
	{
		if (y >= d.start_line && y <= d.end_line)
		{
			my_mlx_pixel_put(map.img, x, y, tex_color(map.tex[d.side], d.xtex, (int) d.texpos));
			d.texpos += d.texstep;
		}
		else if (y < d.start_line)
			my_mlx_pixel_put(map.img, x, y, BLUE);
		else if (y > d.end_line)
			my_mlx_pixel_put(map.img, x, y, GREEN);
		y ++;
	}
}

// void	draw_line(t_map map, int x, int start, int end, unsigned int color)
// {
// 	int	y;

// 	y = 0;
// 	while (y < WIN_WIDTH)
// 	{
// 		// if (x < map.cols * map.iminimap && y < map.rows * map.iminimap)
// 		// 	;
// 		if (y >= start && y <= end)
// 			my_mlx_pixel_put(map.img, x, y, color);
// 		else if (y < start)
// 			my_mlx_pixel_put(map.img, x, y, BLUE);
// 		else if (y > end)
// 			my_mlx_pixel_put(map.img, x, y, GREEN);
// 		else
// 			my_mlx_pixel_put(map.img, x, y, BLACK);
// 		y ++;
// 	}
// }

void	draw(t_map map)
{
	int				x;
	t_data			d;
	//unsigned int	color;

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
				if (d.xraydir > 0)
					d.side = NO;
				else
					d.side = SO;
			}
			else
			{
				d.ysidedist += d.ydeltadist;
				d.ymap += d.ystep;
				if (d.yraydir > 0)
					d.side = WE;
				else
					d.side = EA;
			}
			if (map.board[d.xmap][d.ymap] == '1')
				d.hit = 1;
		}
		if (d.side == NO || d.side == SO)
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

		// where exactly the wall was hit
		if (d.side == NO || d.side == SO)
			d.xwall = map.ypos + d.walldist * d.yraydir;
		else
			d.xwall = map.xpos + d.walldist * d.xraydir;
		d.xwall -= floor(d.xwall);

		// x-coordinate on the texture
		d.xtex = (int) (d.xwall * (float) map.tex[d.side].width);
		if (d.side == NO || d.side == EA)
			d.xtex = map.tex[d.side].width - d.xtex - 1;

		d.texstep = (float) map.tex[d.side].height / d.height_line;
		d.texpos = (d.start_line - WIN_WIDTH / 2 + d.height_line / 2) * d.texstep;
		if (d.height_line < WIN_WIDTH)
			d.texpos = 0;

		draw_line(map, x, d);
		x ++;
	}
}
