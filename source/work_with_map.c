/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:22:31 by qrolande          #+#    #+#             */
/*   Updated: 2022/03/09 22:57:13 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

static int	aftermap_check(t_cub *cub, char **line)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = cub->map->file_len;
	res = 0;
	while ((line[j][i] == ' ' || !line[j][i]) && cub->map->file_len)
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

static char	*work_with_space(t_cub *cub, int res)
{
	int		sum;
	char	*space;

	sum = -1;
	space = NULL;
	space = malloc(sizeof(char) * (res + 1));
	if (!space)
		ft_exit("Error: can't allocate memory", 1, cub);
	while (++sum < res)
		space[sum] = ' ';
	space[res] = '\0';
	return (space);
}

static void	work_with_map_2(t_cub *cub)
{
	int		start;
	int		i;
	int		end;
	char	*space;

	start = 6;
	i = 0;
	end = aftermap_check(cub, cub->map->file);
	cub->map->y_len = cub->map->file_len - start - end + 1;
	if (cub->map->y_len <= 0)
		ft_exit("Error: empty map", 1, cub);
	cub->map->map = malloc(sizeof(char *) * (cub->map->y_len + 1));
	if (!cub->map->map)
		ft_exit("Error: can't allocate memory", 1, cub);
	while (i < cub->map->y_len)
	{
		space = work_with_space(cub, cub->map->x_len \
			- ft_strlen(cub->map->file[start]));
		cub->map->map[i] = ft_strjoin(cub->map->file[start], space);
		free(space);
		i++;
		start++;
	}
	cub->map->map[i] = NULL;
}

void	work_with_map(t_cub *cub)
{
	int	i;

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
