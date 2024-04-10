/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:25:38 by dkreise           #+#    #+#             */
/*   Updated: 2024/04/10 20:32:47 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	tex_color(t_texture tex, int xtex, int ytex)
{
	char *pix;

	pix = tex.addr + (ytex * tex.line_len + xtex * (tex.bits_per_pixel / 8));
	return (*(int *)pix);
}

static int	f_c_color(int *rgb)
{
	return((rgb[0] << 16) + (rgb[1] << 8) + (rgb[2]));
}

static void	draw_line(t_map map, int x, t_data d)
{
	int	y;

	y = 0;
	while (y < WIN_WIDTH)
	{
		if (y >= d.start_line && y <= d.end_line)
		{
			my_mlx_pixel_put(map.img, x, y, tex_color(map.tex[d.side],
				d.xtex, (int) d.texpos));
			d.texpos += d.texstep;
		}
		else if (y < d.start_line)
			my_mlx_pixel_put(map.img, x, y, f_c_color(map.pars->c_nums));
		else if (y > d.end_line)
			my_mlx_pixel_put(map.img, x, y, f_c_color(map.pars->f_nums));
		y ++;
	}
}

void	draw(t_map map)
{
	int				x;
	t_data			d;

	x = 0;
	while (x < WIN_WIDTH)
	{
		d = init_data(map, x);
		set_hit_side(&d, map);
		set_walldist(&d);
		set_line(&d);
		set_wall_coord(&d, map);
		set_tex_coord(&d, map);
		draw_line(map, x, d);
		x ++;
	}
}
