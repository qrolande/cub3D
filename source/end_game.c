#include "../incl/cub3D.h"

int end_game(t_cub *cub)
{
	free(cub->map);
	free(cub->plr);
	free(cub->win);
	mlx_destroy_window(cub->win->mlx, cub->win->win);
	exit(0);
}
