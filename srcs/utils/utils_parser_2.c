/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:20:35 by rpliego           #+#    #+#             */
/*   Updated: 2024/04/16 17:00:17 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	check_extension(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i < 4)
		error_parser("Invalid file, try a .cub file");
	if (str[i] != 'b' || str[i - 1] != 'u' || str[i - 2] != 'c'
		|| str[i - 3] != '.' || str[i - 4] == '.')
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
		while (pars->board[i][j])
		{
			if (pars->board[i][j] == ' ')
				pars->board[i][j] = '0';
			j++;
		}
		i++;
	}
}

int	error_parser(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

int	only_special_char(char **board, int colum, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (board[i][colum] != '~')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
