/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:01:19 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/10 21:11:21 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	bottom_row(t_parser *pars)
{
	int	i;

	i = 0;
	while (pars->map[pars->rows][i])
	{
		if (pars->map[pars->rows][i] == '0')
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

int	check_pos_player(char **map, int i, int j, int rows)
{
	int	in_flag;
	int	row_flag;
	int	aux_i;
	int	aux;

	in_flag = 0;
	aux_i = i;
	aux = 0;
	row_flag = 0;
	while (i >= 0)
	{
		if (map[i][j] == '1')
			in_flag = 1;
		i--;
	}
	if (in_flag != 1)
		return (KO);
	i = aux_i;
	in_flag = 0;
	while (i <= rows)
	{
		if (map[i][j] == '1')
			in_flag = 1;
		i++;
	}
	if (in_flag != 1)
		return (KO);
	in_flag = 0;
	i = aux_i;
	while (map[i][aux])
	{
		if (map[i][aux] == '1' && in_flag == 0)
			row_flag = 1;
		if (map[i][aux] == '1' && row_flag == 1 && aux > j)
			in_flag = 1;
		aux++;
	}
	if (in_flag != 1)
		return (KO);
	return (OK);
}

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
				if (check_pos_player(map, i, j, pars->rows) == KO || pars->player)
					return (KO);
				pars->player = map[i][j];
			}
			j++;
		}
		i++;
	}
	return (OK);
}

int	find_space_in(char **map)
{
	int	i;
	int	j;
	int	in_flag;

	i = 0;
	while (map[i])
	{
		j = 0;
		in_flag = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' && in_flag == 0)
				in_flag = 1;
			else if (map[i][j] == ' ' && in_flag == 1)
			{
				while (map[i][j] == ' ')
				{
					
					j++;
				}
				in_flag = 0;
			}
			j++;
		}
		printf("%s", map[i]);
		i++;
	}
	return (OK);
}

int	validate_map(t_parser *pars)
{
	pars->rows = find_n_rows(pars->map) - 1; //!!!!!!REMEMBER THIS!!!!!!!!
	if (top_row(pars) == KO || bottom_row(pars) == KO)
		return (KO);
	if (find_space_in(pars->map) == KO)
		return (KO);
	if (find_player(pars, pars->map) == KO)
		return (KO);
	return (OK);
}