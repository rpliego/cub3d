/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:19:22 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/05 15:24:07 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static	void	check_no_so(t_parser *pars)
{
	int	i;
	int	j;

	i = 0;
	j = 0; //rondas
	while (pars->map[i] && j < 2)
	{
		if (pars->map[i][0] == 'N' && pars->map[i][1] == 'O' && pars->north == NULL)
		{
			pars->north = ft_substr(pars->map[i], 3, ft_strlen(pars->map[i]));
			pars->n_elements += 1;
		}
		else if(pars->map[i][0] == 'S' && pars->map[i][1] == 'O' && pars->south == NULL)
		{
			pars->south = ft_substr(pars->map[i], 3, ft_strlen(pars->map[i]));
			pars->n_elements += 1;
		}
		i++;
		if (pars->map[i] == NULL && pars->n_elements < 2 && j < 2)
		{
			i = 0;
			j++;
		}
	}
}

static	void	check_we_ea(t_parser *pars)
{
	int	i;
	int	j;

	i = 0;
	j = 0; //rondas
	while (pars->map[i] && j < 4)
	{
		if (pars->map[i][0] == 'W' && pars->map[i][1] == 'E' && pars->west == NULL)
		{
			pars->west = ft_substr(pars->map[i], 3, ft_strlen(pars->map[i]));
			pars->n_elements += 1;
		}
		else if(pars->map[i][0] == 'E' && pars->map[i][1] == 'A' && pars->east == NULL)
		{
			pars->east = ft_substr(pars->map[i], 3, ft_strlen(pars->map[i]));
			pars->n_elements += 1;
		}
		i++;
		if (pars->map[i] == NULL && pars->n_elements < 4 && j < 4)
		{
			i = 0;
			j++;
		}
	}
}

static	void	check_f_c(t_parser *pars)
{
	int	i;
	int	j;

	i = 0;
	j = 0; //rondas
	while (pars->map[i] && j < 6)
	{
		if (pars->map[i][0] == 'F' && pars->floor == NULL)
		{
			pars->floor = ft_substr(pars->map[i], 2, ft_strlen(pars->map[i]));
			pars->n_elements += 1;
		}
		else if(pars->map[i][0] == 'C' && pars->ceiling == NULL)
		{
			pars->ceiling = ft_substr(pars->map[i], 2, ft_strlen(pars->map[i]));
			pars->n_elements += 1;
		}
		i++;
		if (pars->map[i] == NULL && pars->n_elements < 6 && j < 6)
		{
			i = 0;
			j++;
		}
	}
}

int	check_elements(t_parser *pars)
{
	check_no_so(pars);
	check_we_ea(pars);
	check_f_c(pars);
	//trim_info();
	pars->north = ft_strtrim(pars->north, "\n"); //mod_trim malloc added
	if (pars->n_elements != 7)
		return (KO);
}