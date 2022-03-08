#include "../incl/cub3D.h"

//static	void	dist_init(t_dist *dist, t_vect ray, t_plr *plr)
//{
//	dist->delta_dist_x = fabs(1 / ray.x);
//	dist->delta_dist_y = fabs(1 / ray.y);
//	dist->x = (int)plr->pos_x;
//	dist->y = (int)plr->pos_y;
//	if (ray.x > 0)
//	{
//		dist->move_x = 1;
//		dist->side_dist_x = (ceil(plr->pos_x) - plr->pos_x) * dist->delta_dist_x;
//	}
//	else
//	{
//		dist->move_x = -1;
//		dist->side_dist_x = (plr->pos_x - floor(plr->pos_x)) * dist->delta_dist_x;
//	}
//	if (ray.y > 0)
//	{
//		dist->move_y = 1;
//		dist->side_dist_y = (ceil(plr->pos_y) - plr->pos_y) * dist->delta_dist_y;
//	}
//	else
//	{
//		dist->move_y = -1;
//		dist->side_dist_y = (plr->pos_y - floor(plr->pos_y)) * dist->delta_dist_y;
//	}
//}
//
//static double	find_dist(t_vect ray, char **map, t_cub *cub, char *side)
//{
//	t_dist	dist;
//	int		fl;
//
//	write(1, "1.1\n", 4);
//	dist_init(&dist, ray, cub->plr);
//	write(1, "1.2\n", 4);
//	while (map[dist.y][dist.x] && map[dist.y][dist.x] != '1')
//	{
//		if (dist.side_dist_x < dist.side_dist_y)
//		{
//			dist.side_dist_x += dist.delta_dist_x;
//			dist.x += dist.move_x;
//			fl = 1;
//		}
//		else
//		{
//			dist.side_dist_y += dist.delta_dist_y;
//			dist.y += dist.move_y;
//			fl = 0;
//		}
//		printf("delta_x = %fl\n delta_y = %fl\n", dist.delta_dist_x, dist.delta_dist_y);
//		printf("x = %d\n y = %d\n", dist.x, dist.y);
//
//	}
//	write(1, "1.3\n", 4);
//	if (fl)
//		*side = 'H';
//	write(1, "1.4\n", 4);
//	if (fl)
//		return ((dist.x - cub->plr->pos_x + (1 - dist.move_x) * 0.5) / ray.x);
//	*side = 'V';
//	return ((dist.y - cub->plr->pos_y + (1 - dist.move_y) * 0.5) / ray.y);
//}
//
//static t_vect	get_data(t_cub *cub, t_vect ray, t_image **texture)
//{
//	t_vect	tmp;
//	double	dist;
//	char	side;
//
//	write(1, "1\n", 2);
//	dist = find_dist(ray, cub->map->map, cub, &side);
//	write(1, "2\n", 2);
//	if (side == 'H')
//	{
//		tmp.x = cub->plr->pos_y + dist * ray.y;
//		if (ray.x > 0)
//			*texture = cub->wall->west_texture;
//		else
//			*texture = cub->wall->east_texture;
//	}
//	else if (side == 'V')
//	{
//		tmp.x = cub->plr->pos_x + dist * ray.x;
//		if (ray.y > 0)
//			*texture = cub->wall->north_texture;
//		else
//			*texture = cub->wall->south_texture;
//	}
//	tmp.x -= floor(tmp.x);
//	tmp.y = dist;
//	return (tmp);
//}
//
//void	create_walls(t_cub *cub)
//{
//	int		i;
//	double	watcher;
//	t_vect	ray;
//	t_vect	tmp;
//	t_image	*texture;
//
//	i = 0;
//	while (i < RES_X)
//	{
//		watcher = (double)i * (2.0 / (double)RES_X) - 1;
//		ray.y = cub->plr->dir_y + cub->plr->plane_y * watcher;
//		ray.x = cub->plr->dir_x + cub->plr->plane_x * watcher;
//		printf("ray.x = %fl\n ray.y = %fl\n", ray.x, ray.y);
//		tmp = get_data(cub, ray, &texture);
//		tmp.y = (double)RES_Y / tmp.y;
//		spec_put_in(cub, tmp, texture, i);
//		i++;
//	}
//}

static void	init_dist(t_dist *dist, t_vect ray, t_plr *plr)
{
	dist->delta_dist_x = fabs(1 / ray.x);
	dist->delta_dist_y = fabs(1 / ray.y);
	dist->x = (int)plr->pos_x;
	dist->y = (int)plr->pos_y;
//	printf("pos_x = %f, pos_y = %f\n", plr->pos_x, plr->pos_y);
//	printf("dist.x = %d, dist.y = %d\n", dist->x, dist->y);
//	printf("dist.x = %d, dist.y = %d\n", dist.x, dist.y);
//	printf("ray.x = %f, ray.y = %f\n", ray.x, ray.y);
//	printf("delta_dist_x = %f, delta_dist_y = %f\n", dist.delta_dist_x, dist.delta_dist_y);
//	printf("sidedistx = %f, sidedisty = %f\n", dist.side_dist_x, dist.side_dist_y);
//	if (!ray.y)
//		exit (1);
	if (ray.x > 0)
	{
		dist->move_x = 1;
		dist->side_dist_x = (ceil(plr->pos_x) - plr->pos_x) * dist->delta_dist_x;
	}
	else
	{
		dist->move_x = -1;
		dist->side_dist_x = (plr->pos_x - floor(plr->pos_x)) * dist->delta_dist_x;
	}
	if (ray.y > 0)
	{
		dist->move_y = 1;
		dist->side_dist_y = (ceil(plr->pos_y) - plr->pos_y) * dist->delta_dist_y;
	}
	else
	{
		dist->move_y = -1;
		dist->side_dist_y = (plr->pos_y - floor(plr->pos_y)) * dist->delta_dist_y;
	}
}

static double	find_dist(t_vect ray, t_plr *plr, char **map, char *side)
{
	t_dist	dist;
	int		fl;

	init_dist(&dist, ray, plr);
	while (map[dist.y][dist.x] != '1')
	{
		if (dist.side_dist_x < dist.side_dist_y)
		{
			dist.side_dist_x += dist.delta_dist_x;
			dist.x += dist.move_x;
			fl = 1;
		}
		else
		{
			dist.side_dist_y += dist.delta_dist_y;
			dist.y += dist.move_y;
			fl = 0;
		}
	}
	if (fl)
		*side = 'H';
	if (fl)
		return ((dist.x - plr->pos_x + (1 - dist.move_x) * 0.5) / ray.x);
	*side = 'V';
	return ((dist.y - plr->pos_y + (1 - dist.move_y) * 0.5) / ray.y);
}

static t_vect	get_tex_data(t_vect ray, t_plr *plr, t_cub *cub, t_image **tex)
{
	t_vect	trash;
	double		dist;
	char		side;

	dist = find_dist(ray, plr, cub->map->map, &side);
	if (side == 'V')
	{
		trash.x = plr->pos_x + dist * ray.x;
		if (ray.y > 0)
			*tex = cub->wall->north_texture;
		else
			*tex = cub->wall->south_texture;
	}
	else if (side == 'H')
	{
		trash.x = plr->pos_y + dist * ray.y;
		if (ray.x > 0)
			*tex = cub->wall->west_texture;
		else
			*tex = cub->wall->east_texture;
	}
	trash.x -= floor(trash.x);
	trash.y = dist;
	return (trash);
}

void	create_walls(t_cub *cub)
{
	int			x;
	double		camerax;
	t_image		*tex;
	t_vect	    ray;
	t_vect	    trash;

	x = 0;
//	for (int i = 0; cub->map->map[i]; ++i) {
//		printf("map = |%s|\n", cub->map->map[i]);
//	}
	while (x < RES_X)
	{
		camerax = (double)x * (2.0 / (double)RES_X) - 1;
		ray.x = cub->plr->dir_x + cub->plr->plane_x * camerax;
		ray.y = cub->plr->dir_y + cub->plr->plane_y * camerax;
		trash = get_tex_data(ray, cub->plr, cub, &tex);
		trash.y = (double)RES_Y / trash.y;
		put_tex_stripe(cub, x, trash, tex);
		x++;
	}
}