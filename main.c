/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:04:07 by mhernand          #+#    #+#             */
/*   Updated: 2019/05/10 17:20:39 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int			ft_bad(int i)
{
	if (i == 1)
		ft_putendl("usage: ./fdf map_file.fdf");
	if (i == 2)
		ft_putendl("error: could not read fd.");
	if (i == 3)
		ft_putendl("error: could not read map.");
	if (i == 4)
		ft_putendl("error: poor map.");
	if (i == 5)
		ft_putendl("error: bad variable in map.");
	if (i == 6)
		ft_putendl("error: could not create visualizer.");
	if (i == 7)
		ft_putendl("error: malloc returned NULL.");
	exit(1);
	return (-1);
}

void		win_y(t_env *e)
{
	(void)e;
	if ((e->pla.ly * e->spay + e->hi) < (e->w.wy))
		while (e->hi-- >= 5)
			if ((e->pla.ly * e->spay + e->hi) <= (e->w.wy - 50))
				break ;
	// need to fix y-centering here !
	// printf(, );
}

void		win(t_env *e)
{
	e->w.wx = 1632;
	e->w.wy = 1224;
	e->pla.hx = e->w.wx / 2;
	e->pla.hy = e->w.wy / 2;
	e->hi = 10; // height for the Z
	e->zo = 1;
	e->iso_check = 1;
	e->spax = 30;
	if ((e->pla.lx * e->spax) > (e->w.wx - 100))
		while (e->spax-- >= 5)
			if ((e->pla.lx * e->spax) <= (e->w.wx - 100))
				break ;
	e->spay = 30;
	if ((e->pla.ly * e->spay + e->hi) > (e->w.wy - 100))
		while (e->spay-- >= 5)
			if ((e->pla.ly * e->spay) <= (e->w.wy - 100))
				break ;
	win_y(e);
	ft_bzero(e->ks, sizeof(e->ks));
	e->pla.px = e->pla.hx - ((e->pla.lx * e->spax) / 2);
	e->pla.py = e->pla.hy - ((e->pla.ly * e->spay) / 2);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		ret;
	t_env	*e;
	t_ll	*head;

	if (!(e = (t_env*)malloc(sizeof(t_env))))
		return (0);
	ft_bzero(e, sizeof(t_env));
	fd = open(argv[1], O_RDWR);
	if (argc == 1)
		ft_bad(1);
	if (fd < 0 && argc == 2)
		ft_bad(2);
	if (((ret = reader(fd, e)) > 0))
		ft_bad(ret);
	win(e);
	head = e->lines;
	if (!(points(e)))
		ft_bad(7);
	if (visualize(e) == -1)
		ft_bad(6);
	return (0);
}
