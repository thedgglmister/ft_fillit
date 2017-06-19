/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ispiece.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 02:08:59 by biremong          #+#    #+#             */
/*   Updated: 2017/01/14 02:09:33 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_octo_faces(char *piece, int i)
{
	int		faces;

	if (!(faces = (\
		i < 18 && piece[i + 1] == '#') + (\
		i < 14 && piece[i + 5] == '#') + (\
		i > 00 && piece[i - 1] == '#') + (\
		i > 04 && piece[i - 5] == '#')))
		ft_error();
	return (faces);
}

char	*ft_ispiece(char *piece)
{
	int		octos;
	int		faces;
	int		i;

	octos = 0;
	faces = 0;
	i = 0;
	while (piece[i] == '.' || piece[i] == '#' || piece[i] == '\n')
	{
		if (i % 5 < 4)
		{
			if (piece[i] == '#')
				++octos && (faces += ft_octo_faces(piece, i));
		}
		else if (piece[i] != '\n')
			ft_error();
		++i;
	}
	if (piece[i] || octos != 4 || faces < 6)
		ft_error();
	return (piece);
}
