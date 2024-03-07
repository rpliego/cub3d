/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:56:49 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/07 17:32:40 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	trim_info(t_parser *pars)
{
	pars->north = ft_strtrim(pars->north, " ");
	pars->south = ft_strtrim(pars->south, " ");
	pars->west = ft_strtrim(pars->west, " ");
	pars->east = ft_strtrim(pars->east, " ");
	pars->floor = ft_strtrim(pars->floor, " ");
	pars->ceiling = ft_strtrim(pars->ceiling, " ");
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

int	rgb_check(t_parser *pars)
{
	
}

int	validate_info_map(t_parser *pars)
{
	trim_info(pars); //protect mallocs
	if (path_textures(pars) == KO)
		return (KO);
	if (rgb_check(pars) == KO)
		return (KO);
	return (OK);
}