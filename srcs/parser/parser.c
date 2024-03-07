/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:27:55 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/07 17:33:35 by rpliego          ###   ########.fr       */
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
		//exit(2);
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
	//pars->north = ft_strtrim(pars->north, " ");
	printf("%s", pars->north);
	printf("%s", pars->south);
	printf("%s", pars->west);
	printf("%s", pars->east);
	printf("%s", pars->floor);
	printf("%s", pars->ceiling);
	// while (*pars->map)
	// {
	// 	printf("%s", *pars->map);
	// 	pars->map++;
	// }

	
	return (OK);
}
