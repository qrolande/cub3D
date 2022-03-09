/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:17:21 by qrolande          #+#    #+#             */
/*   Updated: 2022/03/09 22:43:18 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

static void	save_map(t_map *map, char *str, int i)
{
	map->file = malloc(sizeof(char *) * (i + 2));
	map->fd = open(str, O_RDONLY);
	map->res = 0;
	gnl_work(map);
}

static void	read_file(t_cub *cub, char *str, int i)
{
	int	gnl;

	cub->map->fd = open(str, O_DIRECTORY);
	if (cub->map->fd != -1)
		ft_exit("Error: can't open file", 1, cub);
	cub->map->fd = open(str, O_RDONLY);
	if (cub->map->fd == -1)
		ft_exit("Error: can't open file", 1, cub);
	gnl = 1;
	while (gnl)
	{
		gnl = get_next_line(cub->map->fd, &cub->map->line);
		if (++i < 7)
		{
			cub->map->res = check_line(cub->map->line);
			if (cub->map->res == -1)
			{
				free(cub->map->line);
				--i;
				continue ;
			}
		}
		free(cub->map->line);
	}
	save_map(cub->map, str, i);
}

static void	init_struct_map(t_cub *cub)
{
	cub->map->map = NULL;
	cub->map->file = NULL;
	cub->map->north_wall = NULL;
	cub->map->south_wall = NULL;
	cub->map->west_wall = NULL;
	cub->map->east_wall = NULL;
	cub->map->map_floor = NULL;
	cub->map->map_sky = NULL;
	cub->map->temp = NULL;
	cub->map->line = NULL;
	cub->map->res = 0;
	cub->map->file_len = 0;
	cub->map->player = 0;
	cub->map->x_len = 0;
	cub->map->y_len = 0;
}

void	parser(char **av, t_cub *cub)
{
	int	i;

	i = 0;
	init_struct_map(cub);
	while (av[1] && av[1][i] != '.')
		i++;
	if (ft_strncmp(av[1] + i, ".cub", 4))
		ft_exit("Error: invalid map extension", 1, cub);
	read_file(cub, av[1], -1);
	work_with_map(cub);
	texture_and_color_parser(cub, cub->map, -1);
	floor_and_sky_check(cub);
	validator(cub, -1, -1);
	player_check(cub, -1, -1);
}
