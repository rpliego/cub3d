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
		map->xdir = 0;
		map->yplane = 0;
		if (pars.player == 'N')
			map->ydir = 1;
		else
			map->ydir = -1;
		map->xplane = map->ydir;
	}
	else if (pars.player == 'E' || pars.player == 'W')
	{
		map->ydir = 0;
		map->xplane = 0;
		if (pars.player == 'E')
			map->xdir = 1;
		else
			map->xdir = -1;
		map->yplane = (-1) * map->xdir;
	}
}

t_map	init_map(t_parser pars, t_img img)
{
	t_map	map;

	map.xpos = pars.y_player+0.3;
	map.ypos = pars.x_player - 1 + 0.6;
	init_dirs(&map, pars);
	map.board = pars.board;
	map.img = &img;
	return (map);
}

float	set_delta(float raydir)
{
	if (raydir == 0)
		return (0.00001); // or smth else?
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
	// if (x == 5)
	// 	printf("%f, %f, %f, %i, %i, %f, %f, %i|\n", d.alpha, d.xraydir, d.yraydir, d.xmap, d.ymap, \
	// 	 d.xdeltadist, d.ydeltadist, d.hit);
	set_step_sidedist(&d, map);
	if (x == 250)
		printf("xpos and ypos:: %f and %f\n", map.xpos, map.ypos);
	if (x == 250)
		printf("%f, %f, %f, %f\n", d.xsidedist, d.ysidedist, d.xdeltadist, d.ydeltadist);
	return (d);
}