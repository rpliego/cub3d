/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:20:35 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/28 19:59:05 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	check_extension(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i < 4)
		error_parser("Invalid file, try a .cub file");
	if (str[i] != 'b' || str[i - 1] != 'u' || str[i - 2] != 'c' ||
		str[i - 3] != '.' || str[i - 4] == '.')
		error_parser("Invalid file, try a .cub file");
}

void	trim_map(t_parser *pars)
{
	int	i;

	i = 0;
	while (pars->board[i])
	{
		pars->board[i] = ft_strtrim(pars->board[i], "\n");
		if (!pars->board[i])
			error_parser("Malloc failed");
		i++;
	}
}

void	replace_space_in(t_parser *pars)
{
	int	i;
	int	j;

	i = 0;
	while (pars->board[i])
	{
		j = 0;
		while (pars->board[i][j] && pars->board[i][j] == ' ')
			j++;
		while (pars->board[i][j])
		{
			if (pars->board[i][j] == ' ')
				pars->board[i][j] = '0';
			j++;
		}
		i++;
	}
}
