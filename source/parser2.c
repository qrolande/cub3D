#include "../incl/cub3D.h"

int after_line_space(char *line)
{
	int count;
	int i;

	count = 0;
	i = ft_strlen(line) - 1;
	while(i != 0 && line[i] == ' ')
	{
		i--;
		count++;
	}
	return (count);
}

void    gnl_work(t_map *map)
{
	while (get_next_line(map->fd, &map->line))
	{
		if (map->y_len < 7)
		{
			map->res = check_line(map->line);
			if (map->res != -1 && map->y_len == 6)
				map->res = 0;
			if (map->res == -1)
			{
				free(map->line);
				continue;
			}
		}
		map->file[map->y_len] = ft_substr(map->line, map->res, \
		ft_strlen(map->line) - after_line_space(map->line));
		free(map->line);
		map->y_len++;
		map->res = 0;
	}
	map->file[map->y_len] = ft_substr(map->line, map->res , \
	ft_strlen(map->line) - after_line_space(map->line));
	map->file[map->y_len + 1] = NULL;
	map->file_len = map->y_len;
	free(map->line);
	close(map->fd);
}

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
