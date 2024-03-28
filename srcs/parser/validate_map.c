/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:01:19 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/28 20:04:22 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	find_player(t_parser *pars, char **map)
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
		error_parser("Player not found");
}

void	validate_map(t_parser *pars)
{
	int	open_map;
	char **aux_bool;
	int	i;

	i = -1;
	open_map = 0;
	pars->rows = find_n_rows(pars->board) - 1;
	pars->columms = find_n_columms(pars->board) - 1;
	trim_map(pars);
	replace_space_in(pars);
	find_player(pars, pars->board);
	init_bool(pars, &aux_bool);
	dfs(pars, pars->x_player, pars->y_player, &open_map, aux_bool);
	while (aux_bool[++i])
		free(aux_bool[i]);
	free(aux_bool);
	if (open_map == 1)
		error_parser("Map is open");
}
