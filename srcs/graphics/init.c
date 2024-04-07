/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:14:44 by dkreise           #+#    #+#             */
/*   Updated: 2024/04/04 14:20:59 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_img	init_img(void)
{
	t_img	img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, WIN_WIDTH, WIN_WIDTH, "cub3d");
	img.img = mlx_new_image(img.mlx, WIN_WIDTH, WIN_WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_len, &img.endian);
	return (img);
}

void	init_dirs(t_map *map, t_parser pars)
{
	if (pars.player == 'N' || pars.player == 'S')
	{
		map->ydir = 0;
		map->xplane = 0;
		if (pars.player == 'S')
			map->xdir = 1;
		else
			map->xdir = -1;
		map->yplane = (-1.5) * map->xdir;
	}
	else if (pars.player == 'E' || pars.player == 'W')
	{
		map->xdir = 0;
		map->yplane = 0;
		if (pars.player == 'E')
			map->ydir = 1;
		else
			map->ydir = -1;
		map->xplane = 1.5 * map->ydir;
	}
}

// void	init_dirs(t_map *map, t_parser pars)
// {
// 	if (pars.player == 'N' || pars.player == 'S')
// 	{
// 		map->xdir = -1; //0
// 		map->yplane = 1.5; //0
// 		if (pars.player == 'N')
// 			map->ydir = 0; //1
// 		else
// 			map->ydir = -1;
// 		map->xplane = 1.5 * map->ydir;
// 	}
// 	else if (pars.player == 'E' || pars.player == 'W')
// 	{
// 		map->ydir = 0;
// 		map->xplane = 0;
// 		if (pars.player == 'E')
// 			map->xdir = 1;
// 		else
// 			map->xdir = -1;
// 		map->yplane = (-1.5) * map->xdir;
// 	}
// }

t_move	init_moves(void)
{
	t_move	mov;

	mov.w_key = 0;
	mov.a_key = 0;
	mov.s_key = 0;
	mov.d_key = 0;
	mov.arrow_left = 0;
	mov.arrow_right = 0;
	return (mov);
}

t_map	init_map(t_parser pars, t_img img)
{
	t_map	map;
	t_move	mov;

	map.xpos = pars.x_player;
	map.ypos = pars.y_player;
	printf("xpos: %i, ypos: %i\n", (int) map.xpos, (int) map.ypos);
	init_dirs(&map, pars);
	map.rows = pars.rows - 1;
	map.cols = pars.columms + 1; // shoud be smth dif
	map.iminimap = i_minimap(map);
	map.board = pars.board;
	map.img = &img;
	mov = init_moves();
	map.mov = &mov;
	return (map);
}

float	set_delta(float raydir)
{
	if (raydir == 0)
		return (10000000);
	else
		return (fabsf(1 / raydir));
}

void	set_step_sidedist(t_data *d, t_map map)
{
	if (d->xraydir < 0)
	{
		d->xstep = -1;
		d->xsidedist = (map.xpos - d->xmap) * d->xdeltadist;
	}
	else
	{
		d->xstep = 1;
		d->xsidedist = (d->xmap + 1.0 - map.xpos) * d->xdeltadist;
	}
	if (d->yraydir < 0)
	{
		d->ystep = -1;
		d->ysidedist = (map.ypos - d->ymap) * d->ydeltadist;
	}
	else
	{
		d->ystep = 1;
		d->ysidedist = (d->ymap + 1.0 - map.ypos) * d->ydeltadist;
	}
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
	// if (x == 250)
	// 	printf("xpos and ypos:: %f and %f\n", map.xpos, map.ypos);
	// if (x == 250)
	// {
	// 	printf("sidedist: %f, %f\n", d.xsidedist, d.ysidedist);
	// 	printf("deltadist: %f, %f\n", d.xdeltadist, d.ydeltadist);
	// }
	return (d);
}
