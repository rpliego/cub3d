#include "../../inc/cub3d.h"

int	ft_close(t_fractal *f)
{
	mlx_destroy_window(f->img->mlx, f->img->win);
	exit(1);
	return (0);
}

int	key_hook(int key, t_fractal *f)
{
	if (key == ESC)
		ft_close(f);
	// if (key == ARROW_LEFT)
	// 	f->mov->arrow_left = 1;
	// if (key == ARROW_RIGHT)
	// 	f->mov->arrow_right = 1;
	// if (key == ARROW_DOWN)
	// 	f->mov->arrow_down = 1;
	// if (key == ARROW_UP)
	// 	f->mov->arrow_up = 1;
	return (0);
}