#include "../incl/cub3D.h"

static int space_work(t_cub *cub, int i)
{
	int     j;
	char    *temp;
	int     res;

	j = 0;
	while (cub->map->map[i][j] == ' ')
		j++;
	if (cub->map->map[i][j] == 'W' || cub->map->map[i][j] == 'E' || \
	cub->map->map[i][j] == 'N' || cub->map->map[i][j] == 'S' || \
	cub->map->map[i][j] == 'F' || cub->map->map[i][j] == 'C')
	{
		res = ft_strlen(cub->map->map[i]);
		temp = ft_substr(cub->map->map[i], j, res - j);
		free(cub->map->map[i]);
		cub->map->map[i] = temp;
		return (0);
	}
	return (1);
}

static int if_space(char *str, t_cub *cub)
{
	int value;
	int i;

	value = 2;
	if (!ft_strncmp(str, "F", 1) || !ft_strncmp(str, "C", 1))
		value = 1;
	i = value;
	while (str[value] == ' ')
		value++;
	if (value - i == 0)
		ft_exit("Error: incorrect texture address", 1, cub);
	return (value);
}

static void value_work(char **str, char *value, t_cub *cub, int i)
{
	int	res;
	int	space;

	space = if_space(cub->map->map[i], cub);
	res = space;
	if (!(*str))
	{
		while (value[res] != ' ' && value[res])
			res++;
		while (value[res] == ' ' && value[res])
		{
			res++;
			space++;
		}
		if (value[res] != '\0')
			ft_exit("Error: incorrect texture or color", 1, cub);
		*str = ft_substr(&value[space], 0, res - space);
		if (!(*str))
			ft_exit("Error: can't allocate memory", 1, cub);
	}
	else
		ft_exit("Error: incorrect texture or color", 1, cub);
}

static void if_not_value(t_cub *cub)
{
	if (!cub->map->north_wall || !cub->map->south_wall || \
	!cub->map->east_wall ||!cub->map->west_wall || \
	!cub->map->map_sky || !cub->map->map_floor)
		ft_exit("Error: wrong map", 1, cub);
}

void    texture_and_color_parser(t_cub *cub, int i)
{
	while (cub->map->map[++i])
	{
		if (!ft_strncmp(cub->map->map[i], " ", 1))
			if (space_work(cub, i))
				break ;
		if (!ft_strncmp(cub->map->map[i], "\0", 1))
			;
		else if (!ft_strncmp(cub->map->map[i], "WE", 2))
			value_work(&cub->map->west_wall, cub->map->map[i], cub, i);
		else if (!ft_strncmp(cub->map->map[i], "EA", 2))
			value_work(&cub->map->east_wall, cub->map->map[i], cub, i);
		else if (!ft_strncmp(cub->map->map[i], "NO", 2))
			value_work(&cub->map->north_wall, cub->map->map[i], cub, i);
		else if (!ft_strncmp(cub->map->map[i], "SO", 2))
			value_work(&cub->map->south_wall, cub->map->map[i], cub, i);
		else if (!ft_strncmp(cub->map->map[i], "F", 1))
			value_work(&cub->map->map_floor, cub->map->map[i], cub, i);
		else if (!ft_strncmp(cub->map->map[i], "C", 1))
			value_work(&cub->map->map_sky, cub->map->map[i], cub, i);
		else
			break ;
	}
	if_not_value(cub);
	cub->map->count = i;
}

