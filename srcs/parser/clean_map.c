/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:13:12 by rpliego           #+#    #+#             */
/*   Updated: 2024/04/04 15:43:55 by rpliego          ###   ########.fr       */
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
	int	aux;
	int	len;

	len = 0;
	aux = start;
	while (pars->map[aux] && trash_inside(pars->map[aux]) == FALSE)
	{
		start++;
		aux++;
	}
	while (pars->map[aux] && trash_inside(pars->map[aux]) == TRUE)
	{
		aux++;
		len++;
	}
	board = malloc((len + 1) * sizeof(char *));
	if (!board)
		error_parser("Malloc failed");
	i = 0;
	while (i < len)
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
	valid_characters(pars->map, i);
	pars->board = find_start_board(pars, i);
}
