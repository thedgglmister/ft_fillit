/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:51:44 by biremong          #+#    #+#             */
/*   Updated: 2017/01/14 15:51:47 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fillit(char *f, t_flags *flags)
{
	t_game game;

	ft_get_pieces(&game, ft_open(f));
	game.size = ft_est_board(game.piece_count);
	game.steps = 0;
	game.placed = 0;
	if (flags->color)
		flags->ansi_array = ft_get_ansi_array(game.piece_count, flags);
	while (!ft_solve(&game, flags))
		game.size++;
	if (flags->color)
	{
		flags->animate = 1;
		ft_strobe(&game, flags);
		ft_stdout_color(&game, flags);
		ft_del_board(flags->ansi_array);
		ft_del_board(flags->strobe_array);
	}
	else
		ft_stdout(&game, flags);
	ft_del_pieces(game.pieces);
	ft_del_board(game.board);
}

int		ft_solve(t_game *game, t_flags *flags)
{
	t_point start_coords[19];
	int		i;

	i = 0;
	while (i < 19)
		start_coords[i++] = (t_point) {-1, 0};
	game->board = ft_new_board(game->size);
	if (ft_recurse(game, flags, start_coords, 0))
		return (1);
	else
	{
		ft_del_board(game->board);
		return (0);
	}
}

int		ft_recurse(t_game *game, t_flags *flags, t_point *start_coords, int n)
{
	t_point coords;
	t_point	orig_coords;
	t_piece *piece;

	if (!(piece = game->pieces[n]))
		return (1);
	orig_coords = start_coords[piece->id];
	coords = orig_coords;
	while (ft_tonext_space(game->board, *piece, &coords))
	{
		ft_mod_board(game->board, *piece, coords, piece->c);
		start_coords[piece->id] = coords;
		if (flags->data)
			ft_update_data(&game->steps, &game->placed, n);
		if (flags->animate)
			ft_animate_step(game, flags);
		if (ft_recurse(game, flags, start_coords, n + 1))
			return (1);
		else
			ft_mod_board(game->board, *piece, coords, '.');
	}
	start_coords[piece->id] = orig_coords;
	return (0);
}
