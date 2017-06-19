/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topiece.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 02:01:09 by biremong          #+#    #+#             */
/*   Updated: 2017/06/19 15:35:37 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_octo_in_row(char *piece, int i)
{
	i -= i % 5;
	while (i % 5 < 4)
	{
		if (piece[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

int		ft_octo_in_col(char *piece, int i)
{
	i %= 5;
	while (i / 5 < 4)
	{
		if (piece[i] == '#')
			return (1);
		i += 5;
	}
	return (0);
}

t_piece	*ft_new_piece(char c)
{
	t_piece	*piece;
	char	*s;

	if (!(piece = (t_piece *)malloc(sizeof(t_piece))))
		ft_crash();
	if (!(s = ft_strnew(6)))
		ft_crash();
	*piece = (t_piece){c, 0, 0, s, -1};
	return (piece);
}

t_piece	*ft_topiece(char *s, char c)
{
	t_piece	*piece;
	int		i;

	c < 'Z' + 1 ? piece = ft_new_piece(c) : ft_error();
	i = 0;
	while (s[i])
	{
		piece->w += ft_octo_in_col(s, i);
		piece->h += ft_octo_in_row(s, i);
		if (ft_octo_in_row(s, i) && ft_octo_in_col(s, i))
			*piece->s++ = s[i];
		++i;
	}
	piece->w /= 4;
	piece->h /= 4 + 1;
	piece->s -= piece->w * piece->h;
	piece->id = ft_piece_id(piece->w, piece->s);
	return (piece);
}
