/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:19:22 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/27 20:08:42 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static	int	check_no_so(t_parser *pars, char *parse)
{
	if (parse[0] == 'N' && parse[1] == 'O' && parse[2] == ' ')
	{
		if (pars->north == NULL)
		{
			pars->north = ft_substr(parse, 3, ft_strlen(parse));
			pars->n_elements += 1;
		}
		else
			return (KO);
	}
	else if(parse[0] == 'S' && parse[1] == 'O' && parse[2] == ' ')
	{
		if (pars->south == NULL)
			pars->south = ft_substr(parse, 3, ft_strlen(parse));
		else
			return (KO);
		pars->n_elements += 1;
	}
	return (OK);
}

static	int	check_we_ea(t_parser *pars, char *parse)
{
	if (parse[0] == 'W' && parse[1] == 'E' && parse[2] == ' ')
	{
		if (pars->west == NULL)
			pars->west = ft_substr(parse, 3, ft_strlen(parse));
		else
			return (KO);
		pars->n_elements += 1;
	}
	else if(parse[0] == 'E' && parse[1] == 'A' && parse[2] == ' ')
	{
		if (pars->east == NULL)
			pars->east = ft_substr(parse, 3, ft_strlen(parse));
		else
			return (KO);
		pars->n_elements += 1;
	}
	return(OK);
}

static	int	check_f_c(t_parser *pars, char *parse)
{
	if (parse[0] == 'F' && parse[1] == ' ')
	{
		if (pars->floor == NULL)
			pars->floor = ft_substr(parse, 2, ft_strlen(parse));
		else
			return (KO);
		pars->n_elements += 1;
	}
	else if(parse[0] == 'C' && parse[1] == ' ')
	{
		if (pars->ceiling == NULL)
			pars->ceiling = ft_substr(parse, 2, ft_strlen(parse));
		else
			return (KO);
		pars->n_elements += 1;
	}
	return (OK);
}

int	trash_inside(char *str)
{
	if (str[0] == '\n' && str[1] == '\0')
		return (OK);
	return (KO);
}

void	trim_to_check(t_parser *pars)
{
	int	i;

	i = 0;
	while (pars->map[i])
	{
		pars->map[i] = ft_strtrim(pars->map[i], " ");
		i++;
	}
}

int	check_elements(t_parser *pars)
{
	int	aux;

	trim_to_check(pars);
	while (*pars->map)
	{
		aux = pars->n_elements;
		if (check_no_so(pars, *pars->map) == KO)
			return (KO);
		if (check_we_ea(pars, *pars->map) == KO)
			return (KO);
		if (check_f_c(pars, *pars->map) == KO)
			return (KO);
		if (trash_inside(*pars->map) == KO && aux == pars->n_elements)
			return (KO);
		free(*pars->map);
		pars->map++;
		if (pars->n_elements == 6)
			break ;
	}
	if (pars->n_elements != 6)
		return(KO);
	if (validate_info_map(pars) == KO)
		return (KO);
	return (OK);
}
