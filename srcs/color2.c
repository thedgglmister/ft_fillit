/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 01:46:22 by biremong          #+#    #+#             */
/*   Updated: 2017/01/14 01:51:56 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_rgb	level_5(int mod)
{
	t_rgb rgb;

	rgb = (t_rgb) {255, 0, 255 - mod};
	return (rgb);
}

t_rgb	get_that_rgb(int i, int n)
{
	int	grad;
	int	level;
	int	mod;

	grad = i * (255 * 6) / n;
	level = grad / 255;
	mod = grad % 255;
	if (level == 0)
		return (level_0(mod));
	else if (level == 1)
		return (level_1(mod));
	else if (level == 2)
		return (level_2(mod));
	else if (level == 3)
		return (level_3(mod));
	else if (level == 4)
		return (level_4(mod));
	else
		return (level_5(mod));
}

int		ft_scramble(int i, int n)
{
	if (i % 2 == 0)
		return (i / 2);
	else
		return ((n + 1) / 2 + i / 2);
}

char	**ft_get_ansi_array(int piece_count, t_flags *flags)
{
	char	**arr;
	t_rgb	rgb;
	int		i;
	int		k;
	int		shuff_i;

	if (!(arr = (char**)malloc(sizeof(char*) * (piece_count + 2))))
		ft_crash();
	if (flags->block)
		arr[0] = ft_strdup("\x1b[48;2;031;031;031m\x1b[38;2;031;031;031m");
	else
		arr[0] = ft_strdup("\x1b[38;2;255;255;255m");
	i = 0;
	while (i < piece_count + 1)
	{
		k = 0;
		shuff_i = i;
		while (k++ < flags->shuffs)
			shuff_i = ft_scramble(shuff_i, piece_count);
		rgb = get_that_rgb(shuff_i, piece_count);
		arr[i + 1] = ft_get_ansi(rgb, flags->block);
		i++;
	}
	arr[i] = 0;
	return (arr);
}

char	*ft_get_ansi(t_rgb rgb, int block_flag)
{
	char *ansi;
	char *red;
	char *green;
	char *blue;

	red = ft_itoa(rgb.r + 1000) + 1;
	green = ft_itoa(rgb.g + 1000) + 1;
	blue = ft_itoa(rgb.b + 1000) + 1;
	if (block_flag)
	{
		ansi = ft_strdup("\x1b[48;2;000;000;000m\x1b[38;2;000;000;000m");
		ft_memcpy(ansi + 26, red, 3);
		ft_memcpy(ansi + 30, green, 3);
		ft_memcpy(ansi + 34, blue, 3);
	}
	else
		ansi = ft_strdup("\x1b[38;2;000;000;000m");
	ft_memcpy(ansi + 7, red, 3);
	ft_memcpy(ansi + 11, green, 3);
	ft_memcpy(ansi + 15, blue, 3);
	free(red - 1);
	free(green - 1);
	free(blue - 1);
	return (ansi);
}
