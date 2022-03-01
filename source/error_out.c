#include "../incl/cub3D.h"

void    error_out(int flag)
{
	if (flag == 0)
		ft_putstr_fd("Error: not enough arguments", 2);
	if (flag == 1)
		ft_putstr_fd("Error: can't allocate memory", 2);
	if (flag == 2)
		ft_putstr_fd("Error: arguments more than 2", 2);
	if (flag == 3)
	    ft_putstr_fd("Error: invalid map extension", 2);
	if (flag == 4)
		ft_putstr_fd("Error: can't open file", 2);
	write(2, "\n", 1);
	exit(1);
}
