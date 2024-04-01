#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../inc/libft/libft.h"
# include "../inc/mlx/mlx.h"

# define FALSE 0
# define TRUE 1
# define KO 1
# define OK 0

# define WIN_WIDTH 500
# define BLACK 0xFFFFFFFF
# define COLOR 0x00F8F4F5

# define ESC 53

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
	char player;
	int	x_player;
	int	y_player;
	char **board;
}		t_parser;

typedef struct s_img
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_len;
	int				endian;
}				t_img;

typedef struct s_map
{
	float	xpos;
	float	ypos;
	float	xdir;
	float	ydir;
	float	xplane;
	float	yplane;
	char	**board;
	t_img	*img;
}				t_map;

typedef struct s_data
{
	float	alpha;
	float	xraydir;
	float	yraydir;
	int		xmap;
	int		ymap;
	float	xsidedist;
	float	ysidedist;
	float	xdeltadist;
	float	ydeltadist;
	float	walldist;
	int		xstep;
	int		ystep;
	int		hit;
	int		side;
	int		height_line;
	int		start_line;
	int		end_line;
	t_map	*map;
}				t_data;


//~~~~~~~~~~~~~PARSER~~~~~~~~~~~~~~~~//
void	check_extension(char *str);
void	parser(char *map, t_parser *prser);
void	extract_map(char *file, t_parser *pars);
int		check_elements(t_parser *pars);
void	clean_map(t_parser *pars, int i);
void	validate_map(t_parser *pars);
void	validate_info_map(t_parser *pars);
void	dfs(t_parser *pars, int	x, int y, int *flag, char **aux_bool);
void	init_bool(t_parser *pars, char ***aux_bool);
int		find_n_rows(char **map);
int		find_n_columms(char **map);
void	replace_space_in(t_parser *pars);
void	trim_map(t_parser *pars);

//~~~~~~~~~~~~~UTILS~~~~~~~~~~~~~~~~//
int		mod_atoi(char *str, int comma);
int		check_comma_rgb(char *floor, char *ceiling);
int		error_parser(char *msg);

//~~~~~~~~~~~~~GRAPHICS~~~~~~~~~~~~~~~~//
t_img	init_img(void);
t_map	init_map(t_parser pars, t_img img);
t_data	init_data(t_map map, int x);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw(t_map map);

//~~~~~~~~~~~~~HOOKS~~~~~~~~~~~~~~~~//
int	key_hook(int key, t_map *map);

#endif