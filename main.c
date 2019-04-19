/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:04:07 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/19 19:44:39 by mhernand         ###   ########.fr       */
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

void		win(t_env *ev)
{
	ev->win.wx = 1632;
	ev->win.wy = 1224;
	ev->pla.hx = ev->win.wx / 2;
	ev->pla.hy = ev->win.wy / 2;
	ev->spa = 30;
	ft_bzero(ev->ks, sizeof(ev->ks));
	ev->pla.px = ev->pla.hx - ((ev->pla.lx * ev->spa) / 2);
	ev->pla.py = ev->pla.hy - ((ev->pla.ly * ev->spa) / 2);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		ret;
	t_env	*ev;
	t_ll	*head;

	if (!(ev = (t_env*)malloc(sizeof(t_env))))
		return (0);
	ft_bzero(ev, sizeof(t_env));
	fd = open(argv[1], O_RDWR);
	if (argc == 1)
		ft_bad(1);
	if (fd < 0 && argc == 2)
		ft_bad(2);
	if (((ret = reader(fd, ev)) > 0))
		ft_bad(ret);
	win(ev);
	head = ev->lines;
	if (!(points(ev)))
		ft_bad(7);
	if (visualize(ev) == -1)
		ft_bad(6);
	return (0);
}
