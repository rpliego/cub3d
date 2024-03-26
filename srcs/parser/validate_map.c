/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:01:19 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/26 21:30:21 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	find_player(t_parser *pars, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				pars->player = map[i][j];
				pars->x_player = i;
				pars->y_player = j;
			}
			j++;
		}
		i++;
	}
	if (pars->player == 0)
		return (KO);
	return (OK);
}

int	validate_map(t_parser *pars)
{
	int	open_map;
	char **aux_bool;

	open_map = 0;
	pars->rows = find_n_rows(pars->map) - 1;
	pars->columms = find_n_columms(pars->map) - 1;
	trim_map(pars); //proteger malloc
	if (replace_space_in(pars) == KO)
		return (KO);
	if (find_player(pars, pars->map) == KO)
		return (KO);
	init_bool(pars, &aux_bool);
	dfs(pars, pars->x_player, pars->y_player, &open_map, aux_bool);
	if (open_map == 1)
		printf("mapa abiertoooo\n");
	else
		printf("cerradoo\n"); //quitar
	return (OK);
}
