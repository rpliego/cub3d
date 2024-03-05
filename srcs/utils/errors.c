/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:12:54 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/02 20:22:13 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	error_msg(int exit, char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	return (exit);
}

// int	check_extension(char *str)
// {
// 	int	i;

// 	i = ft_strlen(str) - 1;
// 	if (i < 4)
// 		return (0);
// 	if (str[i--] != 'b')
// 		return (0);
// 	if (str[i--] != 'u')
// 		return (0);
// 	if (str[i--] != 'c')
// 		return (0);
// 	if (str[i--] != '.')
// 		return (0);
// 	if (str[i] == '.')
// 		return (0);
// 	return (TRUE);
// }

int	check_extension(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i < 4)
		return (0);
	if (str[i] != 'b' || str[i - 1] != 'u' || str[i - 2] != 'c' ||
		str[i - 3] != '.' || str[i - 4] == '.')
		return (0);
	return (TRUE);
}