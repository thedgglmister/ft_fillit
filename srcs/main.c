/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biremong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:07:34 by biremong          #+#    #+#             */
/*   Updated: 2017/01/14 02:55:14 by biremong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_flags flags;

	if (ac == 1)
		ft_usage();
	ft_handle_flags(av, ac, &flags);
	if (ft_is_flag(av[ac - 1], &flags))
		ft_usage();
	else
		ft_fillit(av[ac - 1], &flags);
	return (0);
}

void	ft_usage(void)
{
	write(1, "\
usage: fillit \
[-C [int > 0] [-B]] \
[-A [0 < int < 100]] \
[-E] \
[-Z [int > 0]] \
[-D] \
file\n", 85);
	ft_putendl("       -C --color [int > 0 [-B --block]]");
	ft_putendl("       -A --animate [0 < int < 100]");
	ft_putendl("       -E --equalize");
	ft_putendl("       -Z --zoom [int > 0]");
	ft_putendl("       -D --data");
	exit(0);
}

int		ft_delay(int percent)
{
	return (ANIM_MAX - (percent + 1) * ((ANIM_MAX - ANIM_MIN) / (99 - 1)));
}

void	ft_handle_flags(char **av, int ac, t_flags *flags)
{
	int	i;
	int	pct;

	*flags = (t_flags) {0, 0, 0, 0, 1, 0, ft_delay(50), 0, 0, 0, 0, 0};
	i = 0;
	while (++i < ac - 1)
	{
		if (ft_is_flag(av[i], flags))
			continue ;
		else if (ft_strequ(av[i - 1], "-Z") && ft_atoi(av[i]))
			flags->zoom = ft_atoi(av[i]);
		else if (ft_strequ(av[i - 1], "-C") && ft_atoi(av[i]) > 0)
			flags->shuffs = ft_atoi(av[i]);
		else if (ft_strequ(av[i - 1], "-A") && (pct = ft_atoi(av[i])))
			pct > 0 && pct < 100 ? flags->delay = ft_delay(pct) : ft_usage();
		else
			ft_usage();
	}
	if (flags->block && !flags->color)
		ft_usage();
}

int		ft_is_flag(char *str, t_flags *flags)
{
	if (ft_strequ(str, "-C"))
		flags->color = 1;
	else if (ft_strequ(str, "-A"))
		flags->animate = 1;
	else if (ft_strequ(str, "-B"))
		flags->block = 1;
	else if (ft_strequ(str, "-E"))
		flags->equalize = 1;
	else if (ft_strequ(str, "-Z"))
		;
	else if (ft_strequ(str, "-S"))
		flags->seg = 1;
	else if (ft_strequ(str, "-D"))
		flags->data = 1;
	else
		return (0);
	return (1);
}
