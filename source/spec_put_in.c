#include "../incl/cub3D.h"

//static unsigned int	*set_color(t_image *image, int x, int y)
//{
//	return ((unsigned *)(image->addr + y * image->line_length + x * image->bits));
//}
//
//void	spec_put_in(t_cub *cub, t_vect tmp, t_image *texture, int i)
//{
//	t_vect		position;
//	int			player_x;
//	int			player_y;
//	int			start;
//	int			finish;
//
//	position.x = (double)SCALE / tmp.y;
//	start = (RES_Y - (int)tmp.y) / 2;
//	if (start < 0)
//		start = 0;
//	finish = RES_Y - start;
//	player_x = (int)((double)SCALE * tmp.x);
//	position.y = (start + ((int)tmp.y - RES_Y) * 0.5) * position.x;
//	while (start < finish)
//	{
//		player_y = (int)position.y & (SCALE - 1);
//		ft_miracle(cub, i, start, *set_color(texture, player_x, player_y));
//		position.y += position.x;
//		start++;
//	}
//}

static unsigned int	*set_color(t_image *img, int x, int y)
{
	return ((unsigned *)(img->addr + y * img->line_length + x * img->bits));
}

void	put_tex_stripe(t_cub *cub, int x, t_vect trash, t_image *tex)
{
	int			p_x;
	int			p_y;
	int			start;
	int			finish;
	t_vect  	step_pos;

	step_pos.x = (double)SCALE / trash.y;
	start = (RES_Y - (int)trash.y) / 2;
	if (start < 0)
		start = 0;
	finish = RES_Y - start;
	p_x = (int)((double)SCALE * trash.x);
	step_pos.y = (start + ((int)trash.y - RES_Y) * 0.5) * step_pos.x;
	while (start < finish)
	{
		p_y = (int)step_pos.y & (SCALE - 1);
		ft_miracle(cub, x, start, *set_color(tex, p_x, p_y));
		step_pos.y += step_pos.x;
		start++;
	}
}
