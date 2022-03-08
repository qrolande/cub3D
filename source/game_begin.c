#include "../incl/cub3D.h"

static int	check_step(char **mapi, t_cub *cub, double step_x, \
					double step_y)
{
	step_x = cub->plr->pos_x + step_x;
	step_y = cub->plr->pos_y + step_y;
	if (mapi[(int)step_y][(int)step_x] == '0')
		return (1);
	return (0);
}

static void	trav_step(t_cub *cub, double step_x, double step_y)
{
	if (check_step(cub->map->map, cub, step_x, 0))
		cub->plr->pos_x += step_x;
	if (check_step(cub->map->map, cub, 0, step_y))
		cub->plr->pos_y += step_y;
}

static void	trav_arrow(t_plr *plr, double speed)
{
	double	olddirx;
	double	oldplanex;

	olddirx = plr->dir_x;
	plr->dir_x = plr->dir_x * cos(speed) - plr->dir_y * sin(speed);
	plr->dir_y = olddirx * sin(speed) + plr->dir_y * cos(speed);
	oldplanex = plr->plane_x;
	plr->plane_x = plr->plane_x * cos(speed) - plr->plane_y * sin(speed);
	plr->plane_y = oldplanex * sin(speed) + plr->plane_y * cos(speed);
}

void	game_move(t_cub *cub, double step_x, double step_y)
{
	step_x = cub->plr->dir_x * MOVE_SPEED;
	step_y = cub->plr->dir_y * MOVE_SPEED;
	if (cub->keys->w == 1)
		trav_step(cub, step_x, step_y);
	if (cub->keys->s == 1)
		trav_step(cub, -step_x, -step_y);
	if (cub->keys->d == 1)
		trav_step(cub, -step_y, step_x);
	if (cub->keys->a == 1)
		trav_step(cub, step_y, -step_x);
	if (cub->keys->left_arrow == 1)
		trav_arrow(cub->plr, -ROTATE_SPEED);
	if (cub->keys->right_arrow == 1)
		trav_arrow(cub->plr, ROTATE_SPEED);
}

int game_begin(t_cub *cub)
{
	game_move(cub, 0, 0);
	create_floor_and_sky(cub, 0, 0);
	create_walls(cub);
	mlx_put_image_to_window(cub->win->mlx, cub->win->win, cub->image->img, 0, 0);
	return (0);
}
