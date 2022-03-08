#include "../incl/cub3D.h"

static void check_string_second(char *str, t_cub *cub, int j)
{
	char    *tmp;
	int     res;

	res = ft_strlen(str) - j;
	tmp = ft_substr(str, j, res);
	if (ft_strlen(tmp) > 3)
	{
		free(tmp);
		ft_exit("Error: wrong color number", 1, cub);
	}
	res = ft_atoi(tmp);
	free(tmp);
	if (res > 255 || res < 0)
		ft_exit("Error: wrong color number", 1, cub);
	cub->map->num_col += 1;
	if (cub->map->num_com != 2 && cub->map->num_col != 3)
		ft_exit("Error: wrong color number", 1, cub);
}

static void check_string(char *str, t_cub *cub, int i, int j)
{
	char    *tmp;
	int     res;

	while (str[++i])
	{
		if (str[i] != ',' && !ft_isalnum(str[i]))
			ft_exit("Error: wrong color number", 1, cub);
		else if (str[i] == ',' || str[i] == '\0')
		{
			tmp = ft_substr(str, j, i - j);
			if (ft_strlen(tmp) > 3)
			{
				free(tmp);
				ft_exit("Error: wrong color number", 1, cub);
			}
			j = i + 1;
			res = ft_atoi(tmp);
			free(tmp);
			if (res > 255 || res < 0)
				ft_exit("Error: wrong color number", 1, cub);
			cub->map->num_col += 1;
			cub->map->num_com += 1;
		}
	}
	check_string_second(str, cub, j);
}

void    floor_and_sky_check(t_cub *cub)
{
	cub->map->num_col = 0;
	cub->map->num_com = 0;
	check_string(cub->map->map_floor, cub, -1, 0);
	cub->map->num_col = 0;
	cub->map->num_com = 0;
	check_string(cub->map->map_sky, cub, -1, 0);
}
