/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 01:55:21 by rpliego           #+#    #+#             */
/*   Updated: 2024/04/02 20:42:58 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_parser pars;

	if (ac != 2)
		return(error_parser("WaTh??"));
	check_extension(av[1]);
	parser(av[1], &pars);
	int	x = -1;
	while (pars.board[++x])
	{
		printf("%s\n", pars.board[x]);
	}
	return (0);
}
