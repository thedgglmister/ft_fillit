/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:51:06 by biremong          #+#    #+#             */
/*   Updated: 2017/01/14 15:51:10 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_rgb	level_0(int mod)
{
	t_rgb rgb;

	rgb = (t_rgb) {255, mod, 0};
	return (rgb);
}

t_rgb	level_1(int mod)
{
	t_rgb rgb;

	rgb = (t_rgb) {255 - mod, 255, 0};
	return (rgb);
}

t_rgb	level_2(int mod)
{
	t_rgb rgb;

	rgb = (t_rgb) {0, 255, mod};
	return (rgb);
}

t_rgb	level_3(int mod)
{
	t_rgb rgb;

	rgb = (t_rgb) {0, 255 - mod, 255};
	return (rgb);
}

t_rgb	level_4(int mod)
{
	t_rgb rgb;

	rgb = (t_rgb) {mod, 0, 255};
	return (rgb);
}
