/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 01:57:41 by rpliego           #+#    #+#             */
/*   Updated: 2024/04/01 17:38:43 by dkreise          ###   ########.fr       */
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
	if (fd < 0)
		error_parser("Open failed");
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			counter++;
	}
	close(fd);
	return (counter);
}

void	extract_map(char *file, t_parser *pars)
{
	int	fd;
	char *line;
	int	i;

	i = -1;
	pars->rows = count_rows(file);
	if (pars->rows <= 8)
		error_parser("Map too small");
	printf("rows:%i|\n", pars->rows);
	pars->map = ft_calloc((pars->rows + 1), sizeof(char *));
	if (!pars->map)
		error_parser("malloc failed");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_parser("Open failed");
	while (++i < pars->rows)
	{
		line = get_next_line(fd);
		pars->map[i] = ft_strdup(line);
		if (!pars->map[i])
			error_parser("malloc failed");
		free(line);
	}
	// pars->map[i] = NULL;
	close(fd);
}
