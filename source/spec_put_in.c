/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_put_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:41:24 by akatlyn           #+#    #+#             */
/*   Updated: 2022/03/09 20:41:32 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

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
	t_vect		step_pos;

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
