/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:13:12 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/27 21:41:41 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	valid_characters(char **map, int i)
{
	int		j;
	char	aux;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			aux = map[i][j];
			if (aux != '0' && aux != '1' && aux != ' ' && aux != 'N'
				&& aux != 'S' && aux != 'E' && aux != 'W' && aux != '\n'
				&& aux != '\0')
				return (KO);
			j++;
		}
		i++;
	}
	return (OK);
}

void	find_start_board(t_parser *pars)
{
	int	i;

	while (*pars->map)
	{
		if (*pars->map[0] != '\n')
			break ;
		free(*pars->map);
		pars->map++;
	}
}

int	clean_map(t_parser *pars, int i)
{
	if (valid_characters(pars->map, i) == KO)
		return (KO);
	find_start_board(pars);
	return (OK);
}
