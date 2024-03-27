/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:19:22 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/27 21:53:32 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static	int	check_no_so(t_parser *pars, char *parse)
{
	int	i;

	i = 0;
	while (parse[i] == ' ' && parse[i])
		i++;
	if (parse[i] == 'N' && parse[i + 1] == 'O' && parse[i + 2] == ' ')
	{
		if (pars->north == NULL)
		{
			pars->north = ft_substr(parse, i + 3, ft_strlen(parse));
			pars->n_elements += 1;
		}
		else
			return (KO);
	}
	else if(parse[i] == 'S' && parse[i + 1] == 'O' && parse[i + 2] == ' ')
	{
		if (pars->south == NULL)
			pars->south = ft_substr(parse, i + 3, ft_strlen(parse));
		else
			return (KO);
		pars->n_elements += 1;
	}
	return (OK);
}

static	int	check_we_ea(t_parser *pars, char *parse)
{
	int	i;

	i = 0;
	while (parse[i] == ' ' && parse[i])
		i++;
	if (parse[i] == 'W' && parse[i + 1] == 'E' && parse[i + 2] == ' ')
	{
		if (pars->west == NULL)
			pars->west = ft_substr(parse, i + 3, ft_strlen(parse));
		else
			return (KO);
		pars->n_elements += 1;
	}
	else if(parse[i] == 'E' && parse[i + 1] == 'A' && parse[i + 2] == ' ')
	{
		if (pars->east == NULL)
			pars->east = ft_substr(parse, i + 3, ft_strlen(parse));
		else
			return (KO);
		pars->n_elements += 1;
	}
	return(OK);
}

static	int	check_f_c(t_parser *pars, char *parse)
{
	int	i;

	i = 0;
	while (parse[i] == ' ' && parse[i])
		i++;
	if (parse[i] == 'F' && parse[i + 1] == ' ')
	{
		if (pars->floor == NULL)
			pars->floor = ft_substr(parse, i + 2, ft_strlen(parse));
		else
			return (KO);
		pars->n_elements += 1;
	}
	else if(parse[i] == 'C' && parse[i + 1] == ' ')
	{
		if (pars->ceiling == NULL)
			pars->ceiling = ft_substr(parse, i + 2, ft_strlen(parse));
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

int	check_elements(t_parser *pars)
{
	int	aux;
	int	i = 0;

	while (pars->map[i])
	{
		aux = pars->n_elements;
		if (check_no_so(pars, pars->map[i]) == KO)
			return (KO);
		if (check_we_ea(pars, pars->map[i]) == KO)
			return (KO);
		if (check_f_c(pars, pars->map[i]) == KO)
			return (KO);
		if (trash_inside(pars->map[i]) == KO && aux == pars->n_elements)
			return (KO);
		i++;
		if (pars->n_elements == 6)
			break ;
	}
	if (pars->n_elements != 6)
		return(KO);
	if (validate_info_map(pars) == KO)
		return (KO);
	return (i);
}
