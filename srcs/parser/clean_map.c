/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:13:12 by rpliego           #+#    #+#             */
/*   Updated: 2024/04/05 13:47:56 by rpliego          ###   ########.fr       */
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
	pars->columms = find_n_columms(pars->map + start) - 1;
	aux -= 1;
	while (pars->map[++aux] && trash_inside(pars->map[aux]) == TRUE)
		len++;
	board = malloc((len + 1) * sizeof(char *));
	if (!board)
		error_parser("Malloc failed");
	board[len] = NULL;
	i = -1;
	int	j;
	while (++i < len)
	{
		// board[i] = ft_strdup(pars->map[start]);
		// if (!board[i])
		// 	error_parser("Malloc failed");
		j = -1;
		//printf("columms-->%i\n", pars->columms);
		board[i] = malloc((pars->columms + 1) * sizeof (char));
		board[i][pars->columms] = '\0';
		while (++j < pars->columms)
		{
			//printf("%i\n", j);
			board[i][j] = '~';
		}
	}
	int x = start - 1;
	while (pars->map[++x])
		pars->map[x] = ft_strtrim(pars->map[x], "\n");
	x = start - 1;
	// while (pars->map[++x])
	// 	printf("%s\n", pars->map[x]);
	// printf("\n\n");
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < (int)ft_strlen(pars->map[start]))
		{
			if (pars->map[start][j] != ' ')
				board[i][j] = pars->map[start][j];
			j++;
		}
		i++;
		start++;
	}
	//board[len] = NULL;
	return (board);
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
	find_extra_map(pars, i); //doingggg!!!!!!!!!
	valid_characters(pars->map, i);
	pars->board = find_start_board(pars, i);
	
	// int	x = -1;
	// while (pars->board[++x])
	// 	printf("%s\n", pars->board[x]);

}
