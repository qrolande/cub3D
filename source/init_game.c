#include "../incl/cub3D.h"

static long rgb_converter(t_cub *cub, char *line)
{
	char	**tmp;
	int 	rgb[3];
	int 	i;

	i = -1;
	tmp = ft_split(line, ',');
	if (!tmp)
		ft_exit("Error: can't allocate memory", 1, cub);
	rgb[0] = ft_atoi(tmp[0]);
	rgb[1] = ft_atoi(tmp[1]);
	rgb[2] = ft_atoi(tmp[2]);
	while (tmp[++i])
		free(tmp[i]);
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

static void	texture_init(t_cub *cub)
{
	cub->wall->east_texture = NULL;
	cub->wall->west_texture = NULL;
	cub->wall->north_texture = NULL;
	cub->wall->south_texture = NULL;
	cub->win->mlx = mlx_init();
	if (!cub->win->mlx)
		ft_exit("Error: can't initialize mlx", 1, cub);
	cub->image->img = mlx_new_image(cub->win->mlx, RES_X, RES_Y);
	if (!cub->image->img)
		ft_exit("Error: can't create new image", 1, cub);
	cub->image->addr = mlx_get_data_addr(cub->image->img, &cub->image->bits, \
		&cub->image->line_length, &cub->image->endian);
	if (!cub->image->addr)
		ft_exit("Error: can't create image address", 1, cub);
}

static void	upload_texture(t_cub *cub, char *path, t_image *image)
{
	int width;
	int height;

	image->img = mlx_xpm_file_to_image(cub->win->mlx, path, &width, &height);
	if (!image->img)
		ft_exit("Error: can't open xpm", 1, cub);
	if (height != SCALE || width != height)
		ft_exit("Error: incorrect width or height in xpm", 1, cub);
	image->addr = mlx_get_data_addr(image->img, &image->bits, \
		&image->line_length, &image->endian);
	image->bits = image->bits / 8;
}

static void	 put_texture_in_file(t_cub *cub)
{
	cub->wall->south_texture = malloc(sizeof(t_image));
	cub->wall->north_texture = malloc(sizeof(t_image));
	cub->wall->east_texture = malloc(sizeof(t_image));
	cub->wall->west_texture = malloc(sizeof(t_image));
	if (!cub->wall->south_texture || !cub->wall->north_texture || \
	!cub->wall->east_texture || !cub->wall->west_texture)
		ft_exit("Error: can't allocate memory", 1, cub);
	upload_texture(cub, cub->map->south_wall, cub->wall->south_texture);
	upload_texture(cub, cub->map->north_wall, cub->wall->north_texture);
	upload_texture(cub, cub->map->east_wall, cub->wall->east_texture);
	upload_texture(cub, cub->map->west_wall, cub->wall->west_texture);
}

void	init_game(t_cub *cub)
{
	cub->keys->w = -1;
	cub->keys->a = -1;
	cub->keys->s= -1;
	cub->keys->d = -1;
	cub->keys->left_arrow = -1;
	cub->keys->right_arrow = -1;
	cub->win->floor = rgb_converter(cub, cub->map->map_floor);
	cub->win->sky = rgb_converter(cub, cub->map->map_sky);
	player_gps(cub);
	texture_init(cub);
	put_texture_in_file(cub);
}