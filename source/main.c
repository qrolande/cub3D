#include "../incl/cub3D.h"

//void	search_width(t_map *map)
//{
//	int	i;
//
//	i = map->count;
//	map->len_x = 0;
//	while (map->map[i])
//	{
//		if (ft_strlen(map->map[i]) > map->len_x)
//			map->len_x = ft_strlen(map->map[i]);
//		i++;
//	}
//}
//
//static void	number_players(t_map *map, t_plr *plr)
//{
//	int i;
//	int j;
//	int player;
//
//	i = -1;
//	player = 0;
//	while (++i < map->len_y)
//	{
//		j = -1;
//		while (++j < map->len_x)
//		{
//			if (map->map[i][j] == 'N' || map->map[i][j] == 'S' || \
//			map->map[i][j] == 'W' || map->map[i][j] == 'E')
//			{
//				map->start = map->map[i][j];
//				plr->pos_x = j;
//				plr->pos_y = i;
//				map->map[i][j] = '0';
//				player++;
//			}
//		}
//	}
//}
//
//void    parser(char **av, t_map *map)
//{
//	char    *line;
//	int     gnl;
//
//	line = NULL;
//	map->len_y = 0;
//	map->fd = open(av[1], O_RDONLY);
//	gnl = get_next_line(map->fd, &line);
//	while (gnl)
//	{
//		free(line);
//		gnl = get_next_line(map->fd, &line);
//		map->len_y++;
//	}
//	map->map = malloc(sizeof(char *) * (map->len_y + 2));
//	map->len_y = 0;
//	map->fd = open(av[1], O_RDONLY);
//	while (get_next_line(map->fd, &line))
//	{
//		map->map[map->len_y] = line;
//		map->len_y++;
//	}
//	map->map[map->len_y] = line;
//	map->len_y++;
//	map->map[map->len_y] = NULL;
//	search_width(map);
//}
//
//void	put_square(t_win *win, int x, int y, int color)
//{
//	int	i;
//	int	j;
//
//	j = y;
//	while (j < y + 58)
//	{
//		i = x;
//		while (i < x + 58)
//		{
//			mlx_pixel_put(win->mlx, win->win, i, j, color);
//			i++;
//		}
//		j++;
//	}
//}
//
//void    set_dir(t_cub *cub)
//{
//	if (cub->map->start == 'N')
//	{
//		cub->plr->dir_x = -0.66;
//		cub->plr->dir_y = 0;
//	}
//	if (cub->map->start == 'S')
//	{
//		cub->plr->dir_x = 0.66;
//		cub->plr->dir_y = 0;
//	}
//	if (cub->map->start == 'W')
//	{
//		cub->plr->dir_x = 0;
//		cub->plr->dir_y = -0.66;
//	}
//	if (cub->map->start == 'E')
//	{
//		cub->plr->dir_x = 0;
//		cub->plr->dir_y = 0.66;
//	}
//}

int main(int ac, char **av)
{
	t_cub cub;
//	int x;
//	int y = -1;

	if (ac < 2)
		error_out(0);
	if (ac == 2)
	{
		init_mem(&cub, 0);
		parser(av, &cub);
//		number_players(cub.map, cub.plr);
//		set_dir(&cub);
//		cub.win->mlx = mlx_init();
//		cub.win->win = mlx_new_window(cub.win->mlx, RES_X, RES_Y, "CUB3D");
//		while (cub.map->map[++y]) {
//			x = -1;
//			while (cub.map->map[y][++x]) {
//				if (cub.map->map[y][x] == '1')
//					put_square(cub.win, (x + 10) * SCALE, (y + 5) * SCALE, 0XFFFFFF);
//				else
//					put_square(cub.win, (x + 10) * SCALE, (y + 5) * SCALE, 0X0000ff);
//			}
//		}
//		mlx_hook(cub.win->win, 17, 0L, end_game, &cub);
//		mlx_hook(cub.win->win, 2, 0, key_press, &cub);
//		mlx_hook(cub.win->win, 3, 0, key_unpress, &cub);
//		mlx_loop_hook(cub.win->mlx, game_begin, &cub);
//		mlx_loop(cub.win->mlx);
	}
	else
		error_out(2);
	return  (0);
}