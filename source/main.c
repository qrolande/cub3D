#include "../incl/cub3D.h"

static void    init_mem(t_cub *cub)
{
	cub->plr = malloc(sizeof(t_plr));
	cub->win = malloc(sizeof(t_win));
	cub->keys = malloc(sizeof(t_keys));
	cub->map = malloc(sizeof(t_map));
	if (!cub->plr || !cub->map || !cub->win || !cub->keys)
		ft_exit("Error: can't allocate memory", 1, cub);
}

int main(int ac, char **av)
{
	t_cub cub;
//	int x;
//	int y = -1;

	if (ac < 2)
		ft_exit("Error: not enough arguments", 2, &cub);
	if (ac == 2)
	{
		init_mem(&cub);
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
		ft_exit("Error: arguments more than 2", 2, &cub);
	return  (0);
}