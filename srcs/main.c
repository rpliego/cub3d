/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 01:55:21 by rpliego           #+#    #+#             */
/*   Updated: 2024/04/10 18:10:09 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	render(t_map *map)
{
	mlx_clear_window(map->img->mlx, map->img->win);
	key_hook_move(map);
	key_hook_rotate(map);
	minimap(*map);
	draw(*map);
	minimap(*map);
	mlx_put_image_to_window(map->img->mlx, map->img->win, map->img->img, 0, 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_parser	pars;
	t_img		img;
	t_map		map;

	if (ac != 2)
		return(error_parser("Error: Invalid number of arguments"));
	check_extension(av[1]);
	parser(av[1], &pars);

	img = init_img();
	map = init_map(pars, img);
	mlx_hook(img.win, 2, (1L << 0), &key_hook, &map);
	mlx_hook(img.win, 3, (1L << 0), &key_hook_release, &map);
	mlx_hook(img.win, 17, 0, &ft_close, &map);
	mlx_loop_hook(img.mlx, render, &map);
	mlx_loop(img.mlx);
	return (0);
}