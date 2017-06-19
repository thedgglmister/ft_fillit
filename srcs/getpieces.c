/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpieces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 02:07:44 by biremong          #+#    #+#             */
/*   Updated: 2017/01/14 15:52:54 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*ft_get_piece(int fd, char c)
{
	char	buf[21];
	char	delimiter;

	ft_bzero(buf, 21);
	if (c > 'A')
	{
		if (!ft_read(fd, &delimiter, 1))
			return (0);
		else if (delimiter != '\n')
			ft_error();
	}
	if (ft_read(fd, buf, 20) != 20)
		ft_error();
	return (ft_topiece(ft_ispiece(buf), c));
}

void	ft_get_pieces(t_game *game, int fd)
{
	t_piece	*piece;
	t_piece	**pieces;
	int		i;

	if (!(pieces = (t_piece **)ft_memalloc(sizeof(t_piece *) * 27)))
		ft_crash();
	i = 0;
	while ((piece = ft_get_piece(fd, 'A' + i)))
		pieces[i++] = piece;
	close(fd);
	game->pieces = pieces;
	game->piece_count = i;
}

void	ft_del_pieces(t_piece **pieces)
{
	int i;

	i = 0;
	while (pieces[i])
	{
		ft_strdel(&pieces[i]->s);
		free(pieces[i]);
		i++;
	}
	free(pieces);
}
