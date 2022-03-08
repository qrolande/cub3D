#include "../incl/cub3D.h"

static int aftermap_check(t_cub *cub, char **line)
{
	int i;
	int j;
	int res;

	i = 0;
	j = cub->map->file_len;
	res = 0;
	while (line[j][i] == ' ' || !line[j][i])
	{
		i = 0;
		while (line[j][i] == ' ')
			i++;
		if (!line[j][i])
		{
			res++;
			j--;
		}
	}
	return (res);
}

static void work_with_space(t_cub *cub, int res)
{
	int sum;

	sum = -1;
	cub->map->space = malloc(sizeof(char) * (res + 1));
	if (!cub->map->space)
		ft_exit("Error: can't allocate memory", 1, cub);
	while (++sum < res)
		cub->map->space[sum] = ' ';
	cub->map->space[res] = '\0';
}

static void work_with_map_2(t_cub *cub)
{
	int start;
	int i;
	int end;

	start = 6;
	i = 0;
	end = aftermap_check(cub, cub->map->file);
	cub->map->y_len = cub->map->file_len - start - end + 1;
	cub->map->map = malloc(sizeof(char *) * (cub->map->y_len + 1));
	if (!cub->map->map)
		ft_exit("Error: can't allocate memory", 1, cub);
	while (i < cub->map->y_len)
	{
		if (cub->map->x_len >= ft_strlen(cub->map->file[start]))
		{
			work_with_space(cub, cub->map->x_len - ft_strlen(cub->map->file[start]));
			cub->map->map[i] = ft_strjoin( cub->map->file[start], cub->map->space);
		}
		i++;
		start++;
	}
	cub->map->map[i] = NULL;
}

void    work_with_map(t_cub *cub)
{
	int     i;

	i = 6;
	while (cub->map->file[i])
	{
		if (cub->map->x_len < ft_strlen(cub->map->file[i]))
			cub->map->x_len = ft_strlen(cub->map->file[i]);
		i++;
	}
	work_with_map_2(cub);
	if (cub->map->x_len < 3 && cub->map->y_len < 3)
		ft_exit("Error: invalid map size", 1, cub);
}
