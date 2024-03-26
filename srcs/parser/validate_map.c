/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:01:19 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/26 20:25:20 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	bottom_row(t_parser *pars)
{
	int	i;

	i = 0;
	while (pars->map[pars->rows - 1][i])
	{
		if (pars->map[pars->rows - 1][i] == '0')
			return (KO);
		i++;
	}
	return (OK);
}

int	top_row(t_parser *pars)
{
	int	i;

	i = 0;
	while (pars->map[0][i])
	{
		if (pars->map[0][i] == '0')
			return (KO);
		i++;
	}
	return (OK);
}

// int	check_pos_player(char **map, int i, int j, int rows)
// {
// 	int	in_flag;
// 	int	row_flag;
// 	int	aux_i;
// 	int	aux;

// 	in_flag = 0;
// 	aux_i = i;
// 	aux = 0;
// 	row_flag = 0;
// 	while (i >= 0)
// 	{
// 		if (map[i][j] == '1')
// 			in_flag = 1;
// 		i--;
// 	}
// 	if (in_flag != 1)
// 		return (KO);
// 	i = aux_i;
// 	in_flag = 0;
// 	while (i <= rows)
// 	{
// 		if (map[i][j] == '1')
// 			in_flag = 1;
// 		i++;
// 	}
// 	if (in_flag != 1)
// 		return (KO);
// 	in_flag = 0;
// 	i = aux_i;
// 	while (map[i][aux])
// 	{
// 		if (map[i][aux] == '1' && in_flag == 0)
// 			row_flag = 1;
// 		if (map[i][aux] == '1' && row_flag == 1 && aux > j)
// 			in_flag = 1;
// 		aux++;
// 	}
// 	if (in_flag != 1)
// 		return (KO);
// 	return (OK);
// }

int	find_player(t_parser *pars, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				// if (check_pos_player(map, i, j, pars->rows) == KO || pars->player)
				// 	return (KO);
				pars->player = map[i][j];
				pars->x_player = i;
				pars->y_player = j;
			}
			j++;
		}
		i++;
	}
	return (OK);
}

int	replace_space_in(t_parser *pars)
{
	int	i;
	int	j;

	i = 0;
	while (pars->map[i])
	{
		j = 0;
		while (pars->map[i][j] && pars->map[i][j] == ' ')
			j++;
		while (pars->map[i][j])
		{
			if (pars->map[i][j] == ' ')
				pars->map[i][j] = '0';
			j++;
		}
		i++;
	}
	return (OK);
}

void	trim_map(t_parser *pars)
{
	int	i;

	i = 0;
	while (pars->map[i])
	{
		pars->map[i] = ft_strtrim(pars->map[i], "\n");
		i++;
	}
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

int	init_bool(t_parser *pars, char ***aux_bool)
{
	int	i;
	int	j;

	i = 0;
	*aux_bool = malloc((4 + 1) * sizeof(char *));
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

int	validate_map(t_parser *pars)
{
	int	open_map;
	char **aux_bool;

	open_map = 0;
	pars->rows = find_n_rows(pars->map) - 1; //!!!!!!REMEMBER THIS!!!!!!!!
	pars->columms = find_n_columms(pars->map) - 1;
	//pars->rows -= 1;
	// if (top_row(pars) == KO || bottom_row(pars) == KO)
	// 	return (KO);
	trim_map(pars); ///proteger malloc
	if (replace_space_in(pars) == KO)
		return (KO);
	if (find_player(pars, pars->map) == KO)
		return (KO);
	init_bool(pars, &aux_bool);
	dfs(pars, pars->x_player, pars->y_player, &open_map, aux_bool);
	if (open_map == 1)
		printf("mapa abiertoooo\n");
	else
		printf("cerrraaadooo\n");
	return (OK);
}
