/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:27:55 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/05 15:11:24 by rpliego          ###   ########.fr       */
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
}

void	trim_info(t_parser *pars)
{
	int	i;

	i = 0;
	while (pars->map[i] && pars)
	{
		
	}
	
}

int	parser(char *file, t_parser *pars)
{
	init_parser(pars);
	extract_map(file, pars);
	//trim_info(pars);
	check_elements(pars);
	//if (pars->n_elements < 6)

	printf("%i\n\n", pars->n_elements);
	printf("%s", pars->north);
	printf("%s\n", pars->south);
	printf("%s", pars->west);
	printf("%s\n", pars->east);
	printf("%s", pars->floor);
	printf("%s\n", pars->ceiling);
	return (OK);
}
