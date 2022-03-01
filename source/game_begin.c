#include "../incl/cub3D.h"

static int check_position(t_cub *cub, double move_y, double move_x)
{
	int i;
	int j;

	i = cub->plr->pos_y + move_y;
	j = cub->plr->pos_x + move_x;
//	i = move_y;
//	j = move_x;
	if (cub->map->map[i][j] == '0')
		return (1);
	return (0);
}

static void move(t_cub *cub, double move_y, double move_x)
{
	int res_x;
	int res_y;

	res_x = check_position(cub, 0, move_x);
	res_y = check_position(cub, move_y, 0);
	if (res_x)
		cub->plr->pos_x += move_x;
	if (res_y)
		cub->plr->pos_y += move_y;
}

static void game_move(t_cub *cub)
{
	double move_x;
	double move_y;

	move_y = cub->plr->dir_y * MOVE_SPEED;
	move_x = cub->plr->dir_x * MOVE_SPEED;
	if (cub->keys->w == 1)
		move(cub, move_y, move_x);
	if (cub->keys->s == 1)
		move(cub, -move_y, -move_x);
	if (cub->keys->d == 1)
		move(cub, -move_x, move_y);
	if (cub->keys->a == 1)
		move(cub, move_x, -move_y);
}

int game_begin(t_cub *cub)
{
	game_move(cub);
	return (0);
}
