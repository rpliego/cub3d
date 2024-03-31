#include "../../inc/cub3d.h"



void	draw(t_map map)
{
	int		x;
	t_data	d;

	x = 0;
	while (x < WIN_WIDTH)
	{
		d = init_data(map);
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
			if (map.board[d.xmap][d.ymap] > 0)
				d.hit = 1;
		}
		if (d.side == 0)
			d.walldist = (d.xsidedist - d.xdeltadist)
	}
}