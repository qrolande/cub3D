/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:31:41 by qrolande          #+#    #+#             */
/*   Updated: 2022/03/09 20:38:53 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

static void	map_wall_check(t_cub *cub, t_map *map, int i)
{
	while (++i < map->y_len)
	{
		if (!(map->map[i][0] == '1' || map->map[i][0] == ' '))
			ft_exit("Error: walls are not built", 1, cub);
		if (!(map->map[i][map->x_len - 1] == '1'
			|| map->map[i][map->x_len - 1] == ' '))
			ft_exit("Error: walls are not built", 1, cub);
	}
	i = -1;
	while (++i < cub->map->x_len)
	{
		if (!(map->map[0][i] == '1' || map->map[0][i] == ' '))
			ft_exit("Error: walls are not built", 1, cub);
		if (!(map->map[map->y_len - 1][i] == '1'
			|| map->map[map->y_len - 1][i] == ' '))
			ft_exit("Error: walls are not built", 1, cub);
	}
}

static int	map_symbol_check(t_map *map, int i, int j)
{
	if (!(map->map[i][j] == '0' || map->map[i][j] == ' ' || \
	map->map[i][j] == '1' || map->map[i][j] == 'N' || \
	map->map[i][j] == 'S' || map->map[i][j] == 'W' || \
	map->map[i][j] == 'E'))
		return (1);
	return (0);
}

static void	ft_chess(t_cub *cub, int i, int j)
{
	if (cub->map->map[i][j] == ' ' || cub->map->map[i][j] == '\0')
		ft_exit("Error: invalid map", 1, cub);
}

static void	surround_check(t_cub *cub, int i, int j)
{
	ft_chess(cub, i - 1, j - 1);
	ft_chess(cub, i, j - 1);
	ft_chess(cub, i + 1, j + 1);
	ft_chess(cub, i - 1, j);
	ft_chess(cub, i + 1, j);
	ft_chess(cub, i - 1, j + 1);
	ft_chess(cub, i, j + 1);
	ft_chess(cub, i + 1, j + 1);
}

void	validator(t_cub *cub, int i, int j)
{
	map_wall_check(cub, cub->map, -1);
	while (++i < cub->map->y_len)
	{
		j = -1;
		while (++j < cub->map->x_len)
		{
			if (map_symbol_check(cub->map, i, j))
				ft_exit("Error: invalid map", 1, cub);
			if (cub->map->map[i][j] == '0' || cub->map->map[i][j] == 'N' || \
			cub->map->map[i][j] == 'S' || cub->map->map[i][j] == 'W' || \
			cub->map->map[i][j] == 'E')
				surround_check(cub, i, j);
		}
	}
}
