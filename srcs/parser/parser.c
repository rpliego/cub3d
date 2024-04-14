/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:27:55 by rpliego           #+#    #+#             */
/*   Updated: 2024/04/14 19:38:44 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_parser(t_parser *pars)
{
	pars->columms = 0;
	pars->rows = 0;
	pars->n_elements = 0;
	pars->north = NULL;
	pars->south = NULL;
	pars->west = NULL;
	pars->east = NULL;
	pars->floor = NULL;
	pars->ceiling = NULL;
	pars->player = 0;
	pars->x_player = 0;
	pars->y_player = 0;
}

void	get_cols_rows(t_parser *pars)
{
	pars->rows = find_n_rows(pars->board);
	pars->columms = find_n_columms(pars->board);
}

void	parser(char *file, t_parser *pars)
{
	int	i;
	int	x;

	i = 0;
	x = -1;
	init_parser(pars);
	extract_map(file, pars);
	i = check_elements(pars);
	clean_map(pars, i);
	validate_map(pars);
	get_cols_rows(pars);
	while (pars->map[++x])
		free(pars->map[x]);
	free(pars->map);
}
