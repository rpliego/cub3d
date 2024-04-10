/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:14:36 by dkreise           #+#    #+#             */
/*   Updated: 2024/04/10 17:45:03 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	set_hit_side(t_data *d, t_map map)
{
	while (d->hit == 0)
	{
		if (d->xsidedist < d->ysidedist)
		{
			d->xsidedist += d->xdeltadist;
			d->xmap += d->xstep;
			if (d->xraydir > 0)
				d->side = NO;
			else
				d->side = SO;
		}
		else
		{
			d->ysidedist += d->ydeltadist;
			d->ymap += d->ystep;
			if (d->yraydir > 0)
				d->side = WE;
			else
				d->side = EA;
		}
		if (map.board[d->xmap][d->ymap] == '1')
			d->hit = 1;
	}
}

void	set_walldist(t_data *d)
{
	if (d->side == NO || d->side == SO)
		d->walldist = (d->xsidedist - d->xdeltadist);
	else
		d->walldist = (d->ysidedist - d->ydeltadist);
}

void	set_line(t_data *d)
{
	d->height_line = (int) (WIN_WIDTH / d->walldist) / 3;
	d->start_line = WIN_WIDTH / 2 - d->height_line / 2;
	if (d->start_line < 0)
		d->start_line = 0;
	d->end_line = WIN_WIDTH / 2 + d->height_line / 2;
	if (d->end_line > WIN_WIDTH)
		d->end_line = WIN_WIDTH - 1;
}

void	set_wall_coord(t_data *d, t_map map)
{
	if (d->side == NO || d->side == SO)
		d->xwall = map.ypos + d->walldist * d->yraydir;
	else
		d->xwall = map.xpos + d->walldist * d->xraydir;
	d->xwall -= floor(d->xwall);
}

void	set_tex_coord(t_data *d, t_map map)
{
	d->xtex = (int) (d->xwall * (float) map.tex[d->side].width);
	if (d->side == NO || d->side == EA)
		d->xtex = map.tex[d->side].width - d->xtex - 1;
	d->texstep = (float) map.tex[d->side].height / d->height_line;
	d->texpos = (d->start_line - WIN_WIDTH / 2 +
		d->height_line / 2) * d->texstep;
	if (d->height_line < WIN_WIDTH)
		d->texpos = 0;
}
