/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:13:12 by rpliego           #+#    #+#             */
/*   Updated: 2024/04/01 17:36:13 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	valid_characters(char **map, int i)
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
				error_parser("Invalid characters in map");
			j++;
		}
		i++;
	}
}

char	**find_start_board(t_parser *pars, int start)
{
	char **board;
	int	i;

	i = 0;
	while (pars->map[i])
		i++;
	board = malloc((i - start + 1) * sizeof(char *));
	if (!board)
		error_parser("Malloc failed");
	i = 0;
	while (pars->map[start])
	{
		board[i] = ft_strdup(pars->map[start]);
		if (!board[i])
			error_parser("Malloc failed");
		i++;
		start++;
	}
	board[i] = NULL;
	return (board);
}

void	clean_map(t_parser *pars, int i)
{
	int	j;

	j = -1;
	valid_characters(pars->map, i);
	pars->board = find_start_board(pars, i);
}
