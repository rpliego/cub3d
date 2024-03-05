/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 01:57:41 by rpliego           #+#    #+#             */
/*   Updated: 2024/03/05 20:16:52 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static	int	count_rows(char *file)
{
	int	counter;
	int	 fd;
	char c;

	counter = 1;
	fd = open(file, O_RDONLY);
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			counter++;
	}
	close(fd);
	return (counter);
}

int	extract_map(char *file, t_parser *pars)
{
	int	fd;
	char *line;
	int	i;

	i = 0;
	pars->rows = count_rows(file);
	if (pars->rows <= 8)
		return (KO); //error
	pars->map = malloc((pars->rows + 1) * sizeof(char *));
	fd = open(file, O_RDONLY);
	while (i < pars->rows)
	{
		line = get_next_line(fd);
		pars->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	pars->map[i] = NULL;
	close(fd);
	return (OK);
}
