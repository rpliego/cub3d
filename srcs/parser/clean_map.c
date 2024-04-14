/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:13:12 by rpliego           #+#    #+#             */
/*   Updated: 2024/04/14 19:50:14 by rpliego          ###   ########.fr       */
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

char	**aux_clear(t_parser *pars, int len, int start, char **board)
{
	int		i;
	int		j;

	i = -1;
	while (++i < len)
	{
		j = -1;
		board[i] = malloc((pars->columms + 1) * sizeof (char));
		board[i][pars->columms] = '\0';
		while (++j < pars->columms)
			board[i][j] = '~';
	}
	i = -1;
	while (++i < len)
	{
		j = 0;
		while (j < (int)ft_strlen(pars->map[start]))
		{
			if (pars->map[start][j] != ' ')
				board[i][j] = pars->map[start][j];
			j++;
		}
		start++;
	}
	return (board);
}

char	**clear_board(t_parser *pars, int start)
{
	int		aux;
	int		len;
	int		x;
	char	**board;

	len = 0;
	aux = start;
	while (pars->map[aux] && trash_inside(pars->map[aux]) == FALSE)
	{
		start++;
		aux++;
	}
	pars->columms = find_n_columms(pars->map + start) - 1;
	aux -= 1;
	while (pars->map[++aux] && trash_inside(pars->map[aux]) == TRUE)
		len++;
	x = start - 1;
	while (pars->map[++x])
		pars->map[x] = ft_strtrim(pars->map[x], "\n");
	board = malloc((len + 1) * sizeof(char *));
	if (!board)
		error_parser("Malloc failed");
	board[len] = NULL;
	return (aux_clear(pars, len, start, board));
}

void	find_extra_map(t_parser *pars, int i)
{
	while (pars->map[i] && trash_inside(pars->map[i]) == FALSE)
		i++;
	while (pars->map[i] && trash_inside(pars->map[i]) == TRUE)
		i++;
	while (pars->map[i])
	{
		if (trash_inside(pars->map[i]) == TRUE)
			error_parser("Invalid board");
		i++;
	}
}

void	clean_map(t_parser *pars, int i)
{
	find_extra_map(pars, i);
	valid_characters(pars->map, i);
	pars->board = clear_board(pars, i);
}
