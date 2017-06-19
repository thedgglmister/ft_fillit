/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieceid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 02:03:31 by biremong          #+#    #+#             */
/*   Updated: 2017/01/14 02:04:11 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_piece_id(int w, char *s)
{
	if (w == 4)
		return (0);
	else if (w == 1)
		return (1);
	else if (w == 2)
		return (ft_piece_id_w2(s));
	else
		return (ft_piece_id_w3(s));
}

int		ft_piece_id_w2(char *s)
{
	if (ft_strequ(s, "####"))
		return (2);
	else if (ft_strequ(s, "#.###."))
		return (3);
	else if (ft_strequ(s, ".###.#"))
		return (4);
	else if (ft_strequ(s, ".#.###"))
		return (5);
	else if (ft_strequ(s, "###.#."))
		return (6);
	else if (ft_strequ(s, "#.#.##"))
		return (7);
	else if (ft_strequ(s, "##.#.#"))
		return (8);
	else if (ft_strequ(s, ".####."))
		return (9);
	else
		return (10);
}

int		ft_piece_id_w3(char *s)
{
	if (ft_strequ(s, "###.#."))
		return (11);
	else if (ft_strequ(s, ".#.###"))
		return (12);
	else if (ft_strequ(s, "..####"))
		return (13);
	else if (ft_strequ(s, "####.."))
		return (14);
	else if (ft_strequ(s, "###..#"))
		return (15);
	else if (ft_strequ(s, "#..###"))
		return (16);
	else if (ft_strequ(s, "##..##"))
		return (17);
	else
		return (18);
}
