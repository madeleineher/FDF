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

int			error(int i)
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

void		texting(t_env *e)
{
	mlx_string_put(e->w.mp, e->w.wp, 30, 20, 0xFFFFFF, "~ COMMANDS ~");
	mlx_string_put(e->w.mp, e->w.wp,
			e->w.wx - 150, e->w.wy - 60, 0xFFFFFF, "EXIT : ESC");
	mlx_string_put(e->w.mp, e->w.wp, 30, 40, 0xFFFFFF, "PROJECTIONS");
	mlx_string_put(e->w.mp, e->w.wp, 50, 55, 0xFFFFFF, "ISOMETRIC : 2");
	mlx_string_put(e->w.mp, e->w.wp, 50, 70, 0xFFFFFF, "PARALLEL : 1");
	mlx_string_put(e->w.mp, e->w.wp, 30, 90, 0xFFFFFF, "DIRECTIONS");
	mlx_string_put(e->w.mp, e->w.wp, 50, 105, 0xFFFFFF, "UP : A");
	mlx_string_put(e->w.mp, e->w.wp, 50, 120, 0xFFFFFF, "DOWN : S");
	mlx_string_put(e->w.mp, e->w.wp, 50, 135, 0xFFFFFF, "LEFT : A");
	mlx_string_put(e->w.mp, e->w.wp, 50, 150, 0xFFFFFF, "RIGHT : D");
	mlx_string_put(e->w.mp, e->w.wp, 30, 170, 0xFFFFFF, "MAGNIFICATION");
	mlx_string_put(e->w.mp, e->w.wp, 50, 185, 0xFFFFFF, "ZOOM IN : M");
	mlx_string_put(e->w.mp, e->w.wp, 50, 200, 0xFFFFFF, "ZOOM OUT : L");
}

void		window(t_env *e)
{
	e->w.wx = 1632;
	e->w.wy = 1224;
	e->pla.hx = e->w.wx / 2;
	e->pla.hy = e->w.wy / 2;
	e->hi = 5;
	e->zo = 1;
	e->r_check = 0;
	e->r = M_PI / 64;
	e->iso_check = 1;
	e->spax = 30;
	if ((e->pla.lx * e->spax) > (e->w.wx - 50))
		while (e->spax-- >= 5)
			if ((e->pla.lx * e->spax) <= (e->w.wx - 50))
				break ;
	e->spay = 30;
	if ((e->pla.ly * e->spay + e->hi) > (e->w.wy - 50))
		while (e->spay-- >= 5)
			if ((e->pla.ly * e->spay) <= (e->w.wy - 50))
				break ;
	ft_bzero(e->k, sizeof(e->k));
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
		error(1);
	if (fd < 0 && argc == 2)
		error(2);
	if (((ret = reader(fd, e)) > 0))
		error(ret);
	window(e);
	head = e->lines;
	if (!(points(e)))
		error(7);
	if (visualize(e) == -1)
		error(6);
	return (0);
}
