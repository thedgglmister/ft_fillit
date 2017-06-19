/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 01:34:22 by biremong          #+#    #+#             */
/*   Updated: 2017/01/14 14:10:48 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_animate_step(t_game *game, t_flags *flags)
{
	int	k;
	int	i;
	int	j;

	if (flags->seg && game->steps == 100)
	{
		write(1, "zsh: segmentation fault ./fillit", 32);
		i = 0;
		while (i < 7)
		{
			j = 0;
			while (j < 2000000000)
				j++;
			i++;
		}
	}
	if (flags->color)
		ft_stdout_color(game, flags);
	else
		ft_stdout(game, flags);
	k = 0;
	while (k < flags->delay)
		k++;
}

void	ft_strobe(t_game *game, t_flags *flags)
{
	int	orig_shuffs;
	int	i;
	int	k;

	orig_shuffs = flags->shuffs;
	flags->shuffs = 0;
	flags->strobe_array = ft_get_ansi_array(12, flags);
	flags->delay = ft_delay(95);
	i = 0;
	while (i++ < 23)
	{
		flags->strobe = i;
		ft_stdout_color(game, flags);
		k = 0;
		while (k < flags->delay)
			++k;
	}
	flags->shuffs = orig_shuffs;
	flags->strobe = 0;
}

void	ft_update_data(int *steps, int *placed, int n)
{
	(*steps)++;
	*placed = n + 1;
}

void	ft_80_newlines(void)
{
	write(1, "\
		\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\
		\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\
		\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\
		\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", 80);
}

void	ft_print_data(int piece_count, int placed, int steps)
{
	char	*placed_str;
	char	*piece_count_str;
	char	*steps_str;

	placed_str = ft_itoa(placed);
	piece_count_str = ft_itoa(piece_count);
	steps_str = ft_itoa(steps);
	write(1, "PIECES PLACED: ", 15);
	if (placed < 10)
		write(1, " ", 1);
	write(1, placed_str, ft_strlen(placed_str));
	write(1, " / ", 3);
	if (piece_count < 10)
		write(1, " ", 1);
	write(1, piece_count_str, ft_strlen(piece_count_str));
	write(1, "     STEPS: ", 12);
	write(1, steps_str, ft_strlen(steps_str));
	write(1, "\n\n", 2);
	free(placed_str);
	free(piece_count_str);
	free(steps_str);
}
