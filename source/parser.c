#include "../incl/cub3D.h"

static void	check_valid_file(char *str)
{
    while (*str && *str != '.')
        str++;
    if (ft_strncmp(str, ".cub", 4))
        error_out(3);
}

static void save_map(t_map *map, char *str, int i)
{
	char    *line;

	line = NULL;
	map->map = malloc(sizeof(char *) * (i + 2));
	map->fd = open(str, O_RDONLY);
	while (get_next_line(map->fd, &line))
	{
		map->map[map->y_len] = line;
		map->y_len++;
	}
	map->map[map->y_len + 1] = NULL;
	free(line);
	close(map->fd);
}

static void read_file(t_map *map, char *str)
{
	char    *line;
	int     gnl;
	int		i;

	line = NULL;
	i = 0;
	map->fd = open(str, O_DIRECTORY);
	if (map->fd != -1)
		error_out((4));
	map->fd = open(str, O_RDONLY);
	if (map->fd == -1)
		error_out((4));
	gnl = get_next_line(map->fd, &line);
	while (gnl)
	{
		free(line);
		gnl = get_next_line(map->fd, &line);
		i++;
	}
	free(line);
	save_map(map, str, i);
}

void	parser(char **av, t_cub *cub)
{
	cub->map->map = NULL;
	cub->map->north_wall = NULL;
	cub->map->south_wall = NULL;
	cub->map->west_wall = NULL;
	cub->map->east_wall = NULL;
	cub->map->map_floor = NULL;
	cub->map->map_ceil = NULL;
	cub->map->x_len = 0;
	cub->map->y_len = 0;
    check_valid_file(av[1]);
    read_file(cub->map, av[1]);
}
