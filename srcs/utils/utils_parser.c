/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:52:27 by rpliego           #+#    #+#             */
/*   Updated: 2024/04/01 17:37:07 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	find_n_columms(char **map)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	ret = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
			j++;
		if (j > ret)
			ret = j;
		i++;
	}
	return (ret);
}

int	find_n_rows(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		// printf("%i|%s|\n", i, map[i]);
		j = 0;
		while (map[i][j])
			j++;
		i++;
	}
	return (i);
}

void	moded_part(char *str, int comma, int *i)
{
	int	aux;

	aux = 0;
	while (aux < comma && str[*i])
	{
		if (str[*i] == ',')
			aux++;
		*i += 1;
	}
}

int	mod_atoi(char *str, int comma)
{
	int	n;
	int	sign;
	int	i;

	n = 0;
	sign = 1;
	i = 0;
	moded_part(str, comma, &i);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n * sign);
}

int	check_comma_rgb(char *floor, char *ceiling)
{
	int	i;
	int	comma_n;

	comma_n = 0;
	i = -1;
	while(floor[++i])
	{
		if (floor[i] == ',')
			++comma_n;
	}
	i = -1;
	while (ceiling[++i])
	{
		if (ceiling[i] == ',')
			++comma_n;
	}
	if (comma_n != 4)
		return (KO);
	return (OK);
}
