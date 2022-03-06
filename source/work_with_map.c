#include "../incl/cub3D.h"

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

	start = 6;
	i = 0;
	cub->map->y_len = cub->map->file_len - start + 1;
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
