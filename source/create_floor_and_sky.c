/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_floor_and_sky.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:29:36 by akatlyn           #+#    #+#             */
/*   Updated: 2022/03/09 20:31:06 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

void	ft_miracle(t_cub *cub, int x, int y, int rgb)
{
	char	*tmp;

	tmp = cub->image->addr + (y * cub->image->line_length + \
		x * (cub->image->bits / 8));
	*(unsigned int *)tmp = rgb;
}

void	create_floor_and_sky(t_cub *cub, int x, int y)
{
	y = 0;
	while (y < RES_Y)
	{
		x = 0;
		while (x < RES_X)
		{
			if (y > (RES_Y / 2))
				ft_miracle(cub, x, y, cub->win->floor);
			else
				ft_miracle(cub, x, y, cub->win->sky);
			x++;
		}
		y++;
	}
}
