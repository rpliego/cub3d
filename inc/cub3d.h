#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include "../inc/libft/libft.h"
# include "../inc/mlx/mlx.h"

# define FALSE 0
# define TRUE 1
# define KO 1
# define OK 0

typedef struct s_parser
{
	char **map;
	int	n_elements;
	int	rows;
	int	columms;
	char *north;
	char *south;
	char *west;
	char *east;
	char *floor;
	char *ceiling;
}		t_parser;

int		error_msg(int exit, char *msg);
int		check_extension(char *str);
int		parser(char *map, t_parser *prser);
int		extract_map(char *file, t_parser *pars);
int		check_elements(t_parser *pars);
int		clean_map(t_parser *pars);
int		validate_map(t_parser *pars);
int		validate_info_map(t_parser *pars);

//~~~~~~~~~~~~~UTILS~~~~~~~~~~~~~~~~//
int		mod_atoi(char *str, int comma);
int		check_comma_rgb(char *floor, char *ceiling);

#endif