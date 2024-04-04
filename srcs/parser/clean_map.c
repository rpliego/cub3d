/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:13:12 by rpliego           #+#    #+#             */
/*   Updated: 2024/04/04 19:18:39 by rpliego          ###   ########.fr       */
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
	aux = start - 1;
	while (pars->map[++aux] && trash_inside(pars->map[aux]) == FALSE)
		start++;
	pars->columms = find_n_columms(pars->map + start);
	// printf("%i\n", pars->columms);
	aux -= 1;
	while (pars->map[++aux] && trash_inside(pars->map[aux]) == TRUE)
		len++;
	board = malloc((len + 1) * sizeof(char *));
	if (!board)
		error_parser("Malloc failed");
	i = -1;
	int	j;
	while (++i < len)
	{
		// board[i] = ft_strdup(pars->map[start]);
		// if (!board[i])
		// 	error_parser("Malloc failed");
		j = -1;
		board[i] = ft_calloc(pars->columms, sizeof (char));
		while (++j < pars->columms - 1)
			board[i][j] = '0';
	}
	board[i] = NULL;
	i = 0;
	while (pars->map[start])
	{
		j = 0;
		while (j < (int)ft_strlen(pars->map[start]))
		{
			if (pars->map[start][j] != '\n')
				board[i][j] = pars->map[start][j];
			j++;
		}
		i++;
		start++;
	}
	//board[i] = NULL;
	// i = -1;
	// while (board[++i])
	// 	printf("%s\n", board[i]);
	return (board);
}

void	clean_map(t_parser *pars, int i)
{
	valid_characters(pars->map, i);
	pars->board = find_start_board(pars, i);
}
