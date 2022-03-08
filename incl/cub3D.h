#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# define SCALE			64
# define MOVE_SPEED		0.05
# define ROTATE_SPEED	0.05

# define RES_X			1280
# define RES_Y			720

# define W_KEY			13
# define A_KEY			0
# define S_KEY			1
# define D_KEY			2
# define L_ARROW_KEY	123
# define R_ARROW_KEY	124
# define ESC_KEY		53

typedef struct  s_win
{
	void	    *mlx;
	void	    *win;
	int		    width;
	int		    height;
	long    	floor;
	long	    sky;
}	            t_win;

typedef struct  s_plr
{
	double	    pos_x;
	double	    pos_y;
	double	    dir_x;
	double	    dir_y;
	double	    plane_x;
	double	    plane_y;
	double	    angle;
}			    t_plr;

typedef struct  s_map
{
	int	        fd;
	int         res;
	int		    x_len;
	int		    y_len;
	int         player;
	int		    num_com;
	int		    num_col;
	int			file_len;
	char 		*temp;
	char 		*line;
	char	    **map;
	char	    start;
	char        **file;
	char	    *space;
	char	    *map_sky;
	char	    *map_floor;
	char	    *east_wall;
	char	    *west_wall;
	char	    *south_wall;
	char	    *north_wall;
}               t_map;

typedef struct  s_keys
{
	int		    w;
	int		    a;
	int		    s;
	int		    d;
	int		    left_arrow;
	int		    right_arrow;
}				t_keys;

typedef struct	s_image
{
	void		*img;
	char		*addr;
	int			bits;
	int			line_length;
	int			endian;
}				t_image;

typedef struct	s_vect
{
	double		x;
	double		y;
}				t_vect;

typedef struct	s_dist
{
	int			x;
	int			y;
	int			move_x;
	int			move_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
}				t_dist;

typedef struct	s_wall
{
	t_image		*north_texture;
	t_image		*south_texture;
	t_image		*west_texture;
	t_image		*east_texture;
}				t_wall;

typedef struct	s_cub
{
	t_map 	    *map;
	t_win	    *win;
	t_plr	    *plr;
	t_wall 		*wall;
	t_keys	    *keys;
	t_image		*image;
}				t_cub;

int     end_game(t_cub *cub);
void    gnl_work(t_map *map);
void	init_game(t_cub *cub);
int     game_begin(t_cub *cub);
void	player_gps(t_cub *cub);
int     check_line(char *line);
void	create_walls(t_cub *cub);
void    work_with_map(t_cub *cub);
int     after_line_space(char *line);
void	parser(char **av, t_cub *cub);
void    floor_and_sky_check(t_cub *cub);
int	    key_press(int keycode, t_cub *cub);
void    validator(t_cub *cub, int i, int j);
int	    key_unpress(int keycode, t_cub *cub);
void 	player_check(t_cub *cub, int i, int j);
void    ft_exit(char *str, int flag, t_cub *cub);
void	ft_miracle(t_cub *cub, int x, int y, int rgb);
void	create_floor_and_sky(t_cub *cub, int i, int j);
void    texture_and_color_parser(t_cub *cub, t_map *map, int i);
//void	spec_put_in(t_cub *cub, t_vect tmp, t_image *texture, int i);
void	put_tex_stripe(t_cub *cub, int x, t_vect trash, t_image *tex);


#endif