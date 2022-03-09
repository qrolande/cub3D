/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:39:02 by qrolande          #+#    #+#             */
/*   Updated: 2022/03/09 20:39:29 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

void	player_gps(t_cub *cub)
{
	if (cub->map->start == 'N')
	{
		cub->plr->dir_x = -0.66;
		cub->plr->dir_y = 0;
	}
	if (cub->map->start == 'S')
	{
		cub->plr->dir_x = 0.66;
		cub->plr->dir_y = 0;
	}
	if (cub->map->start == 'W')
	{
		cub->plr->dir_x = 0;
		cub->plr->dir_y = -0.66;
	}
	if (cub->map->start == 'E')
	{
		cub->plr->dir_x = 0;
		cub->plr->dir_y = 0.66;
	}
	cub->plr->plane_x = -cub->plr->dir_y * tan(85 * M_PI / 360);
	cub->plr->plane_y = cub->plr->dir_x * tan(85 * M_PI / 360);
}

void	player_check(t_cub *cub, int i, int j)
{
	cub->plr->pos_x = 0;
	cub->plr->pos_y = 0;
	cub->plr->dir_x = 0;
	cub->plr->dir_y = 0;
	cub->plr->angle = 0;
	while (++i < cub->map->y_len)
	{
		j = -1;
		while (++j < cub->map->x_len)
		{
			if (cub->map->map[i][j] == 'N' || cub->map->map[i][j] == 'S' || \
			cub->map->map[i][j] == 'W' || cub->map->map[i][j] == 'E')
			{
				cub->map->start = cub->map->map[i][j];
				cub->plr->pos_y = i;
				cub->plr->pos_x = j;
				cub->map->map[i][j] = '0';
				cub->map->player++;
			}
		}
	}
	if (cub->map->player != 1)
		ft_exit("Error: wrong number of players", 1, cub);
}
