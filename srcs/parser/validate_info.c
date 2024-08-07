/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:56:49 by rpliego           #+#    #+#             */
/*   Updated: 2024/04/14 19:39:02 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	trim_info(t_parser *pars)
{
	pars->north = ft_strtrim(pars->north, "\n");
	if (pars->north[0] == ' ')
		pars->north = ft_strtrim(pars->north, " ");
	pars->south = ft_strtrim(pars->south, "\n");
	if (pars->south[0] == ' ')
		pars->south = ft_strtrim(pars->south, " ");
	pars->west = ft_strtrim(pars->west, "\n");
	if (pars->west[0] == ' ')
		pars->west = ft_strtrim(pars->west, " ");
	pars->east = ft_strtrim(pars->east, "\n");
	if (pars->east[0] == ' ')
		pars->east = ft_strtrim(pars->east, " ");
	pars->floor = ft_strtrim(pars->floor, "\n");
	if (pars->floor[0] == ' ')
		pars->floor = ft_strtrim(pars->floor, " ");
	pars->ceiling = ft_strtrim(pars->ceiling, "\n");
	if (pars->ceiling[0] == ' ')
		pars->ceiling = ft_strtrim(pars->ceiling, " ");
	if (!pars->north || !pars->south || !pars->west || !pars->east
		|| !pars->floor || !pars->ceiling)
		error_parser("Malloc failed");
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

int	rgb_check(char *floor, char *ceiling, t_parser *pars)
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
	pars->f_nums[0] = int_f[0];
	pars->f_nums[1] = int_f[1];
	pars->f_nums[2] = int_f[2];
	pars->c_nums[0] = int_c[0];
	pars->c_nums[1] = int_c[1];
	pars->c_nums[2] = int_c[2];
	return (OK);
}

void	validate_info_map(t_parser *pars)
{
	trim_info(pars);
	if (path_textures(pars) == KO)
		error_parser("Wrong path to textures");
	if (rgb_check(pars->floor, pars->ceiling, pars) == KO)
		error_parser("Invalid rgb");
}
