/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:56:49 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/10 17:58:23 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	trim_info(t_parser *pars)
{
	pars->north = ft_strtrim(pars->north, "\n");
	pars->north = ft_strtrim(pars->north, " ");
	pars->south = ft_strtrim(pars->south, "\n");
	pars->south = ft_strtrim(pars->south, " ");
	pars->west = ft_strtrim(pars->west, "\n");
	pars->west = ft_strtrim(pars->west, " ");
	pars->east = ft_strtrim(pars->east, "\n");
	pars->east = ft_strtrim(pars->east, " ");
	pars->floor = ft_strtrim(pars->floor, "\n");
	pars->floor = ft_strtrim(pars->floor, " ");
	pars->ceiling = ft_strtrim(pars->ceiling, "\n");
	pars->ceiling = ft_strtrim(pars->ceiling, " ");
	// if (!pars->north || !pars->south || !pars->west || !pars->east
	// 	|| !pars->floor || !pars->ceiling)
	//return (KO);
}

int	path_textures(t_parser *pars)
{
	int	fd;

	fd = open(pars->north, O_RDONLY);
	if (fd < 0)
		return (KO);
	close(fd);
	fd = open(pars->south, O_RDONLY);
	if (fd < 0)
		return (KO);
	close(fd);
	fd = open(pars->west, O_RDONLY);
	if (fd < 0)
		return (KO);
	close(fd);
	fd = open(pars->east, O_RDONLY);
	if (fd < 0)
		return (KO);
	close(fd);
	return (OK);
}

int	valid_rgb(int *floor, int *ceiling)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (floor[i] < 0 || floor[i] > 255)
			return (KO);
		if (ceiling[i] < 0 || ceiling[i] > 255)
			return (KO);
		i++;
	}
	return (OK);
}

int	rgb_check(char *floor, char *ceiling)
{
	int	int_f[3];
	int	int_c[3];
	int	i;

	if (ft_strlen(floor) > 11 || ft_strlen(floor) < 5)
		return (KO);
	if (ft_strlen(ceiling) > 11 || ft_strlen(ceiling) < 5)
		return (KO);
	if (check_comma_rgb(floor, ceiling) == KO)
		return (KO);
	i = -1;
	while (++i < 3)
	{
		int_f[i] = mod_atoi(floor, i);
		int_c[i] = mod_atoi(ceiling, i);
	}
	if (valid_rgb(int_f, int_c) == KO)
		return (KO);
	return (OK);
}

int	validate_info_map(t_parser *pars)
{
	trim_info(pars); //protect mallocs
	// if (path_textures(pars) == KO)
	// 	return (KO);
	if (rgb_check(pars->floor, pars->ceiling) == KO)
		return (KO);
	return (OK);
}