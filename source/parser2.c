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
	char    *line;

	line = NULL;
	while (get_next_line(map->fd, &line))
	{
		if (map->y_len < 7)
		{
			map->res = check_line(line);
			if (map->res == -1)
			{
				free(line);
				continue;
			}
		}
		map->file[map->y_len] = ft_substr(line, map->res, \
		ft_strlen(line) - after_line_space(line));
		free(line);
		map->y_len++;
	}
	map->file[map->y_len] = ft_substr(line, map->res , \
		ft_strlen(line) - after_line_space(line));
	map->file[map->y_len + 1] = NULL;
	map->file_len = map->y_len;
	free(line);
	close(map->fd);
}