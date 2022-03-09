/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:14:39 by qrolande          #+#    #+#             */
/*   Updated: 2022/03/09 22:34:00 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

static void	init_mem(t_cub *cub)
{
	cub->plr = malloc(sizeof(t_plr));
	cub->win = malloc(sizeof(t_win));
	cub->map = malloc(sizeof(t_map));
	cub->wall = malloc(sizeof(t_wall));
	cub->keys = malloc(sizeof(t_keys));
	cub->image = malloc(sizeof(t_image));
	if (!cub->plr || !cub->map || !cub->win || !cub->keys
		|| !cub->wall || !cub->image)
		ft_exit("Error: can't allocate memory", 1, cub);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac < 2)
		ft_exit("Error: not enough arguments", 2, &cub);
	if (ac == 2)
	{
		init_mem(&cub);
		parser(av, &cub);
		init_game(&cub);
		cub.win->win = mlx_new_window(cub.win->mlx, RES_X, RES_Y, "CUB3D");
		if (!cub.win->win)
			ft_exit("Error: can't allocate memory", 1, &cub);
		mlx_hook(cub.win->win, 17, 0L, end_game, &cub);
		mlx_hook(cub.win->win, 2, 0, key_press, &cub);
		mlx_hook(cub.win->win, 3, 0, key_unpress, &cub);
		mlx_loop_hook(cub.win->mlx, game_begin, &cub);
		mlx_loop(cub.win->mlx);
	}
	else
		ft_exit("Error: arguments more than 2", 2, &cub);
	return (0);
}
