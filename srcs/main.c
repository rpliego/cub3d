/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 01:55:21 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/31 17:07:59 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	render(t_map *map)
{
	mlx_clear_window(map->img->mlx, map->img->win);
	//key_hook_move(map);
	//draw_fractal(*f);
	mlx_put_image_to_window(map->img->mlx, map->img->win, map->img->img, 0, 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_parser	pars;
	t_img		img;
	t_map		map;

	if (ac != 2)
		return(error_parser("WaTh??"));
	check_extension(av[1]);
	parser(av[1], &pars);
	img = init_img();
	map = init_map(pars, img);
	mlx_hook(img.win, 2, (1L << 0), &key_hook, &f);
	mlx_loop_hook(img.mlx, render, &map);
	mlx_loop(img.mlx);
	return (0);
}
