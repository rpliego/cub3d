/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:57:06 by rpliego           #+#    #+#             */
/*   Updated: 2024/04/04 15:38:10 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_bool(t_parser *pars, char ***aux_bool)
{
	int	i;
	int	j;

	i = 0;
	*aux_bool = malloc((pars->rows + 1) * sizeof(char *));
	if (!(*aux_bool))
		error_parser("Malloc failed");
	(*aux_bool)[pars->rows] = NULL;
	while (i < pars->rows + 1)
	{
		j = -1;
		(*aux_bool)[i] = malloc(ft_strlen(pars->board[i]) + 1);
		if (!(*aux_bool)[i])
			error_parser("Malloc failed");
		while (pars->board[i][++j])
			(*aux_bool)[i][j] = '0';
		(*aux_bool)[i][j] = '\0';
		i++;
	}
}

void	dfs(t_parser *pars, int	x, int y, int *flag, char **aux_bool)
{
	if (x < 0 || y < 0 || x > pars->rows || y > (int)ft_strlen(pars->board[x]))
	{
		*flag = 1;
		return ;
	}
	if (aux_bool[x][y] == '1' || pars->board[x][y] == '1')
		return ;
	aux_bool[x][y] = '1';
	dfs(pars, x + 1, y, flag, aux_bool);
	dfs(pars, x, y + 1, flag, aux_bool);
	dfs(pars, x - 1, y, flag, aux_bool);
	dfs(pars, x, y - 1, flag, aux_bool);
}
