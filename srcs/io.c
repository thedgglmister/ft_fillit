/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 02:00:09 by biremong          #+#    #+#             */
/*   Updated: 2017/01/14 02:00:30 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	exit(!write(1, "error\n", 6));
}

void	ft_crash(void)
{
	exit(!!write(1, "crash\n", 6));
}

int		ft_open(char *f)
{
	int		fd;

	if ((fd = open(f, O_RDONLY)) == -1)
		ft_error();
	return (fd);
}

int		ft_read(int fd, char *buf, int len)
{
	int		ret;

	if ((ret = read(fd, buf, len)) == -1)
		ft_error();
	return (ret);
}

void	ft_close(int fd)
{
	if (close(fd) == -1)
		ft_error();
}
