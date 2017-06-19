/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 01:39:04 by biremong          #+#    #+#             */
/*   Updated: 2017/01/14 01:41:55 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_tonext_space(char **board, t_piece piece, t_point *coords)
{
	int		i;
	int		j;

	i = coords->y;
	j = coords->x + 1;
	while (board[piece.h - 1 + i])
	{
		if (i != coords->y)
			j = 0;
		while (board[piece.h - 1 + i][piece.w - 1 + j])
		{
			if ((board[i][j] == '.' || *piece.s == '.') &&
					ft_isopen_space(board, piece, j, i))
			{
				coords->x = j;
				coords->y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_isopen_space(char **board, t_piece piece, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < piece.h)
	{
		j = 0;
		while (j < piece.w)
		{
			if (*piece.s == '#' && board[y + i][x + j] != '.')
				return (0);
			++piece.s;
			++j;
		}
		++i;
	}
	return (1);
}
