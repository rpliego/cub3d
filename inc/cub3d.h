/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:31:58 by rpliego           #+#    #+#             */
/*   Updated: 2024/04/17 00:10:05 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../inc/libft/libft.h"
# include "../inc/mlx/mlx.h"

# define FALSE 0
# define TRUE 1
# define KO 1
# define OK 0

# define WIN_WIDTH 1000
# define BLACK 0xFFFFFFFF
# define COLOR 0x00F8F4F5
# define RED 0x33DD0000
# define WHITE 0x00000000

# define SPEED 0.05
# define ROTATE 0.05
# define NO 0
# define SO 1
# define WE 2
# define EA 3

# define ESC 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_parser
{
	char	**map;
	int		n_elements;
	int		rows;
	int		columms;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	int		f_nums[3];
	char	*ceiling;
	int		c_nums[3];
	char	player;
	int		x_player;
	int		y_player;
	char	**board;
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

typedef struct s_move
{
	int	w_key;
	int	a_key;
	int	s_key;
	int	d_key;
	int	arrow_left;
	int	arrow_right;
}				t_move;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}			t_texture;

typedef struct s_map
{
	float		xpos;
	float		ypos;
	float		xdir;
	float		ydir;
	float		xplane;
	float		yplane;
	int			rows;
	int			cols;
	int			iminimap;
	char		**board;
	t_img		img;
	t_move		*mov;
	t_texture	tex[4];
	t_parser	*pars;
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
	float	xwall;
	int		xtex;
	float	texstep;
	float	texpos;
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
void	dfs(t_parser *pars, int x, int y, char **aux_bool);
void	init_bool(t_parser *pars, char ***aux_bool);
int		find_n_rows(char **map);
int		find_n_columms(char **map);
void	replace_space_in(t_parser *pars);
void	trim_map(t_parser *pars);
int		trash_inside(char *str);
int		only_special_char(char **board, int colum, int rows);

//~~~~~~~~~~~~~UTILS~~~~~~~~~~~~~~~~//
int		mod_atoi(char *str, int comma);
int		check_comma_rgb(char *floor, char *ceiling);
int		error_parser(char *msg);

//~~~~~~~~~~~~~GRAPHICS~~~~~~~~~~~~~~~~//
void	init_img(t_img *img);
void	init_map(t_parser pars, t_map *map, t_move *mov);
t_data	init_data(t_map map, int x);
void	init_dirs(t_map *map, t_parser pars);
void	save_texture(t_map *map, t_texture *tex, char *path);
float	set_delta(float raydir);
void	set_step_sidedist(t_data *d, t_map map);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw(t_map map);
void	set_hit_side(t_data *d, t_map map);
void	set_walldist(t_data *d);
void	set_line(t_data *d);
void	set_wall_coord(t_data *d, t_map map);
void	set_tex_coord(t_data *d, t_map map);
int		i_minimap(t_map *map);
void	minimap(t_map map);

//~~~~~~~~~~~~~HOOKS~~~~~~~~~~~~~~~~//
int		ft_close(t_map *map);
int		key_hook(int key, t_map *map);
void	key_hook_move(t_map *map);
void	key_hook_rotate(t_map *map);
int		key_hook_release(int key, t_map *map);
void	w_hook(t_map *map);
void	a_hook(t_map *map);
void	s_hook(t_map *map);
void	d_hook(t_map *map);

#endif