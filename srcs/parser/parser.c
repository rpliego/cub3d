/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:27:55 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/27 21:19:35 by rpliego          ###   ########.fr       */
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

int	parser(char *file, t_parser *pars)
{
	init_parser(pars);
	if (extract_map(file, pars) == KO)
	{
		printf("error extracting\n");
		exit(1);
	}
	if (check_elements(pars) == KO)
	{
		printf("error checking elements\n");
		exit(2);
	}
	if (clean_map(pars) == KO)
	{
		printf("error saving the board\n");
		exit(3);
	}
	if (validate_map(pars) == KO)
	{
		printf("error validating map\n");
		exit(4);
	}
	// printf("%i\n\n", pars->n_elements);
	// printf("%s\n", pars->north);
	// printf("%s\n", pars->south);
	// printf("%s\n", pars->west);
	// printf("%s\n", pars->east);
	// printf("%s\n", pars->floor);
	// printf("%s\n", pars->ceiling);
	// while (*pars->map)
	// {
	// 	printf("%s\n", *pars->map);
	// 	pars->map++;
	// }
	free(pars->north);
	free(pars->south);
	free(pars->west);
	free(pars->floor);
	free(pars->ceiling);
	int	x = -1;
	while (pars->map[++x])
		free(pars->map[x]);
	//free(pars->map);
	return (OK);
}
