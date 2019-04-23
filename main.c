/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:04:07 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/23 19:12:50 by mhernand         ###   ########.fr       */
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

void		win(t_env *e)
{
	e->w.wx = 1632;
	e->w.wy = 1224;
	e->pla.hx = e->w.wx / 2;
	e->pla.hy = e->w.wy / 2;
	e->spa = 30;
	ft_bzero(e->ks, sizeof(e->ks));
	e->pla.px = e->pla.hx - ((e->pla.lx * e->spa) / 2);
	e->pla.py = e->pla.hy - ((e->pla.ly * e->spa) / 2);
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
