/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:57:06 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/26 21:27:06 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	init_bool(t_parser *pars, char ***aux_bool)
{
	int	i;
	int	j;

	i = 0;
	*aux_bool = malloc((pars->rows + 1) * sizeof(char *));
	if (!(*aux_bool))
		return KO;
	(*aux_bool)[pars->rows] = NULL;
	while (i < pars->rows + 1)
	{
		j = -1;
		(*aux_bool)[i] = malloc(ft_strlen(pars->map[i]) + 1);
		if (!(*aux_bool)[i])
			return (KO); //free____all;
		while (pars->map[i][++j])
			(*aux_bool)[i][j] = '0';
		(*aux_bool)[i][j] = '\0';
		i++;
	}
	return (OK);
}

void	dfs(t_parser *pars, int	x, int y, int *flag, char **aux_bool)
{
	if (x < 0 || y < 0 || x > pars->rows || y > pars->columms)
	{
		*flag = 1;
		return ;
	}
	if (aux_bool[x][y] == '1' || pars->map[x][y] == '1')
		return ;
	aux_bool[x][y] = '1';
	dfs(pars, x + 1, y, flag, aux_bool);
	dfs(pars, x, y + 1, flag, aux_bool);
	dfs(pars, x - 1, y, flag, aux_bool);
	dfs(pars, x, y - 1, flag, aux_bool);
}
