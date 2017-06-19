/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 01:45:16 by biremong          #+#    #+#             */
/*   Updated: 2017/01/14 14:11:14 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_est_board(int piece_count)
{
	int		n;
	int		i;

	n = piece_count * 4;
	i = 0;
	while (i * i < n)
		i++;
	return (i);
}

char	**ft_new_board(int size)
{
	char	**board;
	int		i;

	if (!(board = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
		ft_crash();
	i = 0;
	while (i < size)
	{
		if (!(board[i] = ft_strnew(size)))
			ft_crash();
		ft_memset(board[i++], '.', size);
	}
	return (board);
}

void	ft_mod_board(char **board, t_piece piece, t_point coords, char c)
{
	int		i;
	int		j;

	i = 0;
	while (i < piece.h)
	{
		j = 0;
		while (j < piece.w)
		{
			if (*piece.s == '#')
				board[coords.y + i][coords.x + j] = c;
			++piece.s;
			++j;
		}
		++i;
	}
}

void	ft_del_board(char **board)
{
	int		i;

	i = 0;
	while (board[i])
		ft_strdel(&board[i++]);
	free(board);
}
