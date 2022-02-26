/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:51:08 by qrolande          #+#    #+#             */
/*   Updated: 2022/01/10 17:00:17 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	unsigned char	*a;
	int				i;

	a = (unsigned char *) s;
	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}
