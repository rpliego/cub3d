/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:01:19 by rpliego           #+#    #+#             */
/*   Updated: 2024/04/14 19:35:41 by rpliego          ###   ########.fr       */
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
				if (pars->player)
					error_parser("More than one player");
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
	char	**aux_bool;
	int		i;

	i = -1;
	trim_map(pars);
	pars->columms = find_n_columms(pars->board) - 1;
	pars->rows = find_n_rows(pars->board) - 1;
	replace_space_in(pars);
	find_player(pars, pars->board);
	init_bool(pars, &aux_bool);
	dfs(pars, pars->x_player, pars->y_player, aux_bool);
	while (++i <= pars->rows)
		free(aux_bool[i]);
	free(aux_bool);
}
