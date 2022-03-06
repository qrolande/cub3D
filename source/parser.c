#include "../incl/cub3D.h"

int check_line(char *line)
{
	int j;

	j = 0;
	if (line[j] == ' ' || !line[j])
	{
		while (line[j] == ' ')
			j++;
		if (!line[j])
			return (-1);
	}
	return (j);
}

static void save_map(t_map *map, char *str, int i)
{
	map->file = malloc(sizeof(char *) * (i + 2));
	map->fd = open(str, O_RDONLY);
	gnl_work(map);
}

static void read_file(t_cub *cub, char *str, int i)
{
	char    *line;
	int     gnl;

	line = NULL;
	cub->map->fd = open(str, O_DIRECTORY);
	if (cub->map->fd != -1)
		ft_exit("Error: can't open file", 1, cub);
	cub->map->fd = open(str, O_RDONLY);
	if (cub->map->fd == -1)
		ft_exit("Error: can't open file", 1, cub);
	gnl = 1;
	while (gnl)
	{
		gnl = get_next_line(cub->map->fd, &line);
		if (check_line(line) == -1 && i < 7)
		{
			free(line);
			continue;
		}
		free(line);
		i++;
	}
	save_map(cub->map, str, i);
}

static void init_struct_map(t_cub *cub)
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
	cub->map->res = 0;
	cub->map->file_len = 0;
	cub->map->player = 0;
	cub->map->x_len = 0;
	cub->map->y_len = 0;
}

void	parser(char **av, t_cub *cub)
{
	int i;

	i = 0;
	init_struct_map(cub);
	while (av[1] && av[1][i] != '.')
		i++;
	if (ft_strncmp(av[1] + i, ".cub", 4))
		ft_exit("Error: invalid map extension", 1, cub);
    read_file(cub, av[1], 0);
	work_with_map(cub);
	texture_and_color_parser(cub, cub->map, -1);
	floor_and_sky_check(cub);
	validator(cub, -1, -1);
//	int j = -1;
//	while (cub->map->file[++j])
//		printf("file = %s\n", cub->map->file[j]);
//	j = -1;
//	while (cub->map->map[++j])
//		printf("map = %s\n", cub->map->map[j]);
//	player_check(cub, -1, -1);
}
