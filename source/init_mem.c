#include "../incl/cub3D.h"

void    init_mem(t_cub *cub, int flag)
{
	if (flag == 0)
	{
		cub->plr = malloc(sizeof(t_plr));
		cub->win = malloc(sizeof(t_win));
		cub->keys = malloc(sizeof(t_keys));
		cub->map = malloc(sizeof(t_map));
	}
	if (!cub->plr || !cub->map || !cub->win || !cub->keys)
		ft_exit("Error: can't allocate memory", 1, cub);
}
