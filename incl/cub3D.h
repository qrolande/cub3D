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

# define RES_X			1920
# define RES_Y			1080

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
	long	    ceiling;
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
	int		    x_len;
	int		    y_len;
	int			file_len;
	int		    num_col;
	int		    num_com;
	int         player;
	int         res;
	char	    **map;
	char        **file;
	char	    start;
	char	    *space;
	char 		*temp;
	char	    *map_sky;
	char	    *east_wall;
	char	    *map_floor;
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

typedef struct  s_cub
{
	t_map 	    *map;
	t_win	    *win;
	t_plr	    *plr;
	t_keys	    *keys;
}				t_cub;

int     end_game(t_cub *cub);
int     game_begin(t_cub *cub);
int     check_line(char *line);
void    work_with_map(t_cub *cub);
int     after_line_space(char *line);
void	parser(char **av, t_cub *cub);
void    floor_and_sky_check(t_cub *cub);
void    gnl_work(t_map *map);
int	    key_press(int keycode, t_cub *cub);
void    validator(t_cub *cub, int i, int j);
int	    key_unpress(int keycode, t_cub *cub);
void    ft_exit(char *str, int flag, t_cub *cub);
void    texture_and_color_parser(t_cub *cub, t_map *map, int i);



#endif