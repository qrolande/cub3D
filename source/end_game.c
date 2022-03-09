/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:41:29 by qrolande          #+#    #+#             */
/*   Updated: 2022/03/09 22:36:00 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

static void	map_free(t_cub *cub)
{
	int	i;

	i = -1;
	if (cub->map->file && cub->map->file_len > 0)
	{
		while (cub->map->file[++i])
			free(cub->map->file[i]);
		free(cub->map->file);
	}
	i = -1;
	if (cub->map->map && cub->map->y_len > 0)
	{
		while (cub->map->map[++i])
			free(cub->map->map[i]);
		free(cub->map->map);
	}
}

int	end_game(t_cub *cub)
{
	map_free(cub);
	free(cub->map->west_wall);
	free(cub->map->south_wall);
	free(cub->map->east_wall);
	free(cub->map->north_wall);
	free(cub->map->map_floor);
	free(cub->map->map_sky);
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
