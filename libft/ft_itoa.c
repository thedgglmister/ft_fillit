/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 10:30:12 by biremong          #+#    #+#             */
/*   Updated: 2016/12/03 13:14:14 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_digits(long myn)
{
	int digits;

	digits = 1;
	while (myn /= 10)
		digits++;
	return (digits);
}

char		*ft_itoa(int n)
{
	char	*array;
	int		digits;
	int		is_neg;
	long	myn;

	myn = (long)n;
	is_neg = myn < 0 ? 1 : 0;
	myn = myn < 0 ? -myn : myn;
	digits = ft_get_digits(myn);
	array = (char*)malloc(sizeof(char) * (digits + is_neg + 1));
	if (!array)
		return (NULL);
	array[digits + is_neg] = '\0';
	while (digits)
	{
		array[digits + is_neg - 1] = '0' + (myn % 10);
		myn /= 10;
		digits--;
	}
	if (is_neg)
		array[0] = '-';
	return (array);
}
