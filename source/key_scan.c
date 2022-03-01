#include "../incl/cub3D.h"

int	key_unpress(int keycode, t_cub *cub)
{
	if (keycode == W_KEY)
		cub->keys->w = 0;
	else if (keycode == S_KEY)
		cub->keys->s = 0;
	else if (keycode == D_KEY)
		cub->keys->d = 0;
	else if (keycode == A_KEY)
		cub->keys->a = 0;
	else if (keycode == L_ARROW_KEY)
		cub->keys->left_arrow = 0;
	else if (keycode == R_ARROW_KEY)
		cub->keys->right_arrow = 0;
	return (0);
}

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == W_KEY)
		cub->keys->w = 1;
	else if (keycode == S_KEY)
		cub->keys->s = 1;
	else if (keycode == D_KEY)
		cub->keys->d = 1;
	else if (keycode == A_KEY)
		cub->keys->a = 1;
	else if (keycode == L_ARROW_KEY)
		cub->keys->left_arrow = 1;
	else if (keycode == R_ARROW_KEY)
		cub->keys->right_arrow = 1;
	if (keycode == ESC_KEY)
		end_game(cub);
	return (0);
}

