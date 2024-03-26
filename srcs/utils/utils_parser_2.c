/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:20:35 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/26 21:24:05 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_extension(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i < 4)
		return (0);
	if (str[i] != 'b' || str[i - 1] != 'u' || str[i - 2] != 'c' ||
		str[i - 3] != '.' || str[i - 4] == '.')
		return (FALSE);
	return (TRUE);
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
