/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:21:13 by qrolande          #+#    #+#             */
/*   Updated: 2022/03/09 22:39:55 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

static void	other_close(t_cub *cub)
{
	if (cub->map->east_wall)
		free(cub->map->east_wall);
	if (cub->map->west_wall)
		free(cub->map->west_wall);
	if (cub->map->south_wall)
		free(cub->map->south_wall);
	if (cub->map->north_wall)
		free(cub->map->north_wall);
	if (cub->map->map_sky)
		free(cub->map->map_sky);
	if (cub->map->map_floor)
		free(cub->map->map_floor);
}

static void	free_all(t_cub *cub)
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
	other_close(cub);
}

void	ft_exit(char *str, int flag, t_cub *cub)
{
	if (flag == 2)
	{
		ft_putstr_fd(str, 2);
		write(2, "\n", 1);
		exit (1);
	}
	if (flag == 1)
	{
		ft_putstr_fd(str, 2);
		write(2, "\n", 1);
	}
	free_all(cub);
	exit(flag);
}
