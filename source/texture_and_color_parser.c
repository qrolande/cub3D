/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_and_color_parser.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:27:21 by qrolande          #+#    #+#             */
/*   Updated: 2022/03/09 20:30:31 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

static char	*value_work(char *str, t_cub *cub)
{
	int	i;
	int	len;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	len = ft_strlen(&str[i]);
	if (len < 4 || ft_strncmp(&str[i] + len - 4, ".xpm", 5))
		ft_exit("Error: invalid texture extension", 1, cub);
	if (str[i] != '.' || str[i + 1] != '/')
		ft_exit("Error: wrong texture address!", 1, cub);
	return (ft_strdup(&str[i]));
}

static char	*rgb_work(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	return (ft_strdup(&str[i]));
}

static void	if_not_value(t_cub *cub)
{
	if (!cub->map->north_wall || !cub->map->south_wall \
		|| !cub->map->east_wall ||!cub->map->west_wall \
		|| !cub->map->map_sky || !cub->map->map_floor)
		ft_exit("Error: wrong map", 1, cub);
}

void	texture_and_color_parser(t_cub *cub, t_map *map, int i)
{
	while (map->file[++i])
	{
		if (!ft_strncmp(map->file[i], "WE", 2))
			cub->map->west_wall = value_work(map->file[i], cub);
		else if (!ft_strncmp(map->file[i], "EA", 2))
			cub->map->east_wall = value_work(map->file[i], cub);
		else if (!ft_strncmp(map->file[i], "NO", 2))
			cub->map->north_wall = value_work(map->file[i], cub);
		else if (!ft_strncmp(map->file[i], "SO", 2))
			cub->map->south_wall = value_work(map->file[i], cub);
		else if (!ft_strncmp(map->file[i], "F", 1))
			cub->map->map_floor = rgb_work(map->file[i]);
		else if (!ft_strncmp(map->file[i], "C", 1))
			cub->map->map_sky = rgb_work(map->file[i]);
		else
			break ;
	}
	if_not_value(cub);
}
