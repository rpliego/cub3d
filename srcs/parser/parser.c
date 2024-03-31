/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:27:55 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/31 15:48:49 by dkreise          ###   ########.fr       */
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
}

void	parser(char *file, t_parser *pars)
{
	int	i = 0;

	init_parser(pars);
	extract_map(file, pars);
	i = check_elements(pars);
	clean_map(pars, i);
	validate_map(pars);
	
	// printf("%s\n", pars->north);
	// printf("%s\n", pars->south);
	// printf("%s\n", pars->west);
	// printf("%s\n", pars->east);
	// printf("%s\n", pars->floor);
	// printf("%s\n\n", pars->ceiling);
	int	x = -1;
	// while (pars->board[++x])
	// 	printf("%s\n", pars->board[x]);
	// free(pars->north);
	// free(pars->south);
	// free(pars->west);
	// free(pars->east);
	// free(pars->floor);
	// free(pars->ceiling);
	x = -1;
	while (pars->map[++x])
	{
		free(pars->map[x]);
	}
	free(pars->map);
	x = -1;
	while (pars->board[++x])
	{
		printf("%s\n", pars->board[x]);
	}
	// free(pars->board);
}
