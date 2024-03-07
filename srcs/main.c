/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 01:55:21 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/07 19:31:43 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_parser pars;

	if (ac != 2)
		return(error_msg(1, "WaTh??"));
	if (check_extension(av[1]) == FALSE)
		return (error_msg(1, "Invalid file, try a .cub file"));
	if (parser(av[1], &pars) == KO)
		exit(1);
	return (0);
}
