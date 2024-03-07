/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:13:12 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/07 13:37:21 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	valid_characters(char **map)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
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
	//save in pars->board;
}

int	clean_map(t_parser *pars)
{
	if (valid_characters(pars->map) == KO)
		return (KO);
	find_start_board(pars);
	while (*pars->map)
	{
		printf("%s", *pars->map);
		pars->map++;
	}
	return (OK);
}
