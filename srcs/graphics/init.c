/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:14:44 by dkreise           #+#    #+#             */
/*   Updated: 2024/04/11 14:27:17 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_img(t_img *img)
{

	img->mlx = mlx_init();
	if (!img->mlx)
		error_parser("mlx initialization failed");
	img->win = mlx_new_window(img->mlx, WIN_WIDTH, WIN_WIDTH, "cub3d");
	if (!img->win)
		error_parser("mlx window initialization failed");
	img->img = mlx_new_image(img->mlx, WIN_WIDTH, WIN_WIDTH);
	if (!img->img)
		error_parser("mlx image initialization failed");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_len, &img->endian);
	if (!img->addr)
		error_parser("Getting image address failed");
}

void	init_moves(t_move* mov)
{
	mov->w_key = 0;
	mov->a_key = 0;
	mov->s_key = 0;
	mov->d_key = 0;
	mov->arrow_left = 0;
	mov->arrow_right = 0;
}

void	init_map(t_parser pars, t_map *map, t_move *mov)
{
	map->xpos = pars.x_player + 0.5;
	map->ypos = pars.y_player + 0.5;
	init_dirs(map, pars);
	map->rows = pars.rows - 1;
	map->cols = pars.columms - 1;
	map->iminimap = i_minimap(map);
	map->board = pars.board;
	init_moves(mov);
	map->mov = mov;
	save_texture(map, &map->tex[NO], pars.north);
	save_texture(map, &map->tex[SO], pars.south);
	save_texture(map, &map->tex[WE], pars.west);
	save_texture(map, &map->tex[EA], pars.east);
}

t_data	init_data(t_map map, int x)
{
	t_data	d;

	d.alpha = 2 * x / (float) WIN_WIDTH - 1;
	d.xraydir = map.xdir + map.xplane * d.alpha;
	d.yraydir = map.ydir + map.yplane * d.alpha;
	d.xmap = (int) map.xpos;
	d.ymap = (int) map.ypos;
	d.xdeltadist = set_delta(d.xraydir);
	d.ydeltadist = set_delta(d.yraydir);
	d.hit = 0;
	set_step_sidedist(&d, map);
	return (d);
}
