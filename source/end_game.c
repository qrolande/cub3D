#include "../incl/cub3D.h"

int end_game(t_cub *cub)
{
	free(cub->map->west_wall);
	free(cub->map->south_wall);
	free(cub->map->east_wall);
	free(cub->map->north_wall);
	free(cub->wall->north_texture);
	free(cub->wall->south_texture);
	free(cub->wall->west_texture);
	free(cub->wall->east_texture);
	free(cub->map);
	free(cub->plr);
	free(cub->image);
	free(cub->keys);
	free(cub->wall);
	mlx_destroy_window(cub->win->mlx, cub->win->win);
	write(1, "See you later!\n", 15);
	exit(0);
}
