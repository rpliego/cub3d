/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 01:55:21 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/04 19:16:57 by rpliego          ###   ########.fr       */
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



	
	// int	i = 0;
	// while (pars.map[i])
	// {
	// 	printf("%s", pars.map[i]);
	// 	i++;
	// }
	return (0);
}
