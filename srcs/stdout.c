/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdout.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 01:53:10 by biremong          #+#    #+#             */
/*   Updated: 2017/01/14 14:13:58 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_stdout(t_game *game, t_flags *flags)
{
	int		i;
	int		k;
	int		row_len;
	char	*row_str;

	row_len =\
		flags->zoom\
		* ft_get_equalize_scalar(flags->zoom, flags->equalize)\
		* game->size + 1;
	row_str = ft_memalloc(row_len);
	if (flags->animate)
		ft_80_newlines();
	if (flags->data)
		ft_print_data(game->piece_count, game->placed, game->steps);
	i = 0;
	while (game->board[i])
	{
		ft_get_row_str(game->board[i], row_str, flags);
		k = 0;
		while (k++ < flags->zoom)
			write(1, row_str, row_len);
		i++;
	}
	free(row_str);
}

void	ft_get_row_str(char *row, char *str, t_flags *flags)
{
	int j;
	int step;

	if (flags->equalize)
		step = ft_get_equalize_scalar(flags->zoom, flags->equalize);
	else
		step = flags->zoom;
	j = 0;
	while (row[j])
	{
		ft_memset(str, row[j], step);
		str += step;
		j++;
	}
	*str = '\n';
}

void	ft_stdout_color(t_game *game, t_flags *flags)
{
	int		i;
	int		k;
	char	*row_str;
	int		row_len;

	row_len =\
		((flags->zoom\
		* ft_get_equalize_scalar(flags->zoom, flags->equalize))\
		+ (19 + flags->block * 19))\
		* game->size + 5;
	row_str = ft_memalloc(row_len);
	if (flags->animate)
		ft_80_newlines();
	if (flags->data)
		ft_print_data(game->piece_count, game->placed, game->steps);
	i = 0;
	while (game->board[i])
	{
		ft_get_color_row_str(game->board[i], row_str, flags);
		k = 0;
		while (k++ < flags->zoom)
			write(1, row_str, row_len);
		i++;
	}
	free(row_str);
}

void	ft_get_color_row_str(char *row, char *str, t_flags *flags)
{
	int j;
	int step;
	int ansi_len;

	if (flags->equalize)
		step = ft_get_equalize_scalar(flags->zoom, flags->equalize);
	else
		step = flags->zoom;
	ansi_len = flags->block ? 38 : 19;
	j = 0;
	while (row[j])
	{
		if (row[j] == '.')
			ft_memcpy(str, flags->ansi_array[0], ansi_len);
		else if (flags->strobe)
			ft_memcpy(str, flags->strobe_array[\
				(row[j] - 'A' - (flags->strobe % 12) + 12) % 12 + 1], ansi_len);
		else
			ft_memcpy(str, flags->ansi_array[row[j] - 'A' + 1], ansi_len);
		str += ansi_len;
		ft_memset(str, row[j], step);
		str += step;
		j++;
	}
	ft_memcpy(str, "\x1b[0m\n", 5);
}

int		ft_get_equalize_scalar(int zoom, int equalize)
{
	int i;

	if (!equalize)
		return (1);
	i = 0;
	zoom *= 12;
	while (i * 5 < zoom + 2)
		i++;
	return (--i);
}
