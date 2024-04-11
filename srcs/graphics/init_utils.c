/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:25:28 by dkreise           #+#    #+#             */
/*   Updated: 2024/04/11 14:26:18 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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

void	save_texture(t_map *map, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(map->img.mlx, path, &tex->width,
			&tex->height);
	if (!tex->img)
		error_parser("Converting xpm file to image failed");
	if (tex->width != 64 || tex->height != 64)
		error_parser("Image is not 64x64");
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_len, &tex->endian);
	if (!tex->addr)
		error_parser("Getting image address failed");
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
