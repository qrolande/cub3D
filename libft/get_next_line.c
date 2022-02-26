/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:15:33 by qrolande          #+#    #+#             */
/*   Updated: 2022/02/23 17:03:12 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*rem_check(char *mmry, char **line)
{
	char	*buff;

	buff = ft_strchr(mmry, '\n');
	if ((!*mmry))
		return (buff);
	if (buff)
	{
		*buff++ = '\0';
		*line = ft_strjoin_free(*line, mmry);
		if (!(*line))
			return (NULL);
		ft_strcpy(mmry, buff);
	}
	else
	{
		*line = ft_strjoin_free(*line, mmry);
		if (!(*line))
			return (NULL);
	}
	return (buff);
}

int	get_next_line(int fd, char **line)
{
	static char	mmry[BUFF_SIZE + 1];
	char		*temp;
	int			rd;

	if (BUFF_SIZE < 1 || fd < 0 || (read(fd, mmry, 0)) < 0)
		return (-1);
	*line = ft_strdup("");
	if (!(*line))
		return (-1);
	rd = 1;
	temp = rem_check(mmry, line);
	while (!temp && rd)
	{
		rd = read(fd, mmry, BUFF_SIZE);
		mmry[rd] = '\0';
		temp = rem_check(mmry, line);
	}
	if (rd == 0)
		return (0);
	else
		return (1);
}
