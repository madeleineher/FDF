/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:04:07 by mhernand          #+#    #+#             */
/*   Updated: 2019/05/24 16:52:02 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	exit(0);
	return (-1);
}

void		texting(t_env *e)
{
	mlx_string_put(e->w.mp, e->w.wp, 30, 20, 0xFFFFFF, "~ COMMANDS ~");
	mlx_string_put(e->w.mp, e->w.wp,
			e->w.wx - 150, e->w.wy - 60, 0xFFFFFF, "EXIT : ESC");
	mlx_string_put(e->w.mp, e->w.wp, 30, 40, 0xFFFFFF, "PROJECTIONS");
	mlx_string_put(e->w.mp, e->w.wp, 50, 55, 0xFFFFFF, "PARALLEL : 1");
	mlx_string_put(e->w.mp, e->w.wp, 50, 70, 0xFFFFFF, "ISOMETRIC : 2");
	mlx_string_put(e->w.mp, e->w.wp, 30, 90, 0xFFFFFF, "DIRECTIONS");
	mlx_string_put(e->w.mp, e->w.wp, 50, 105, 0xFFFFFF, "UP : W");
	mlx_string_put(e->w.mp, e->w.wp, 50, 120, 0xFFFFFF, "DOWN : S");
	mlx_string_put(e->w.mp, e->w.wp, 50, 135, 0xFFFFFF, "LEFT : A");
	mlx_string_put(e->w.mp, e->w.wp, 50, 150, 0xFFFFFF, "RIGHT : D");
	mlx_string_put(e->w.mp, e->w.wp, 30, 170, 0xFFFFFF, "MAGNIFICATION");
	mlx_string_put(e->w.mp, e->w.wp, 50, 185, 0xFFFFFF, "ZOOM IN : M");
	mlx_string_put(e->w.mp, e->w.wp, 50, 200, 0xFFFFFF, "ZOOM OUT : L");
	mlx_string_put(e->w.mp, e->w.wp, 30, 220, 0xFFFFFF, "ALTITUDE");
	mlx_string_put(e->w.mp, e->w.wp, 50, 235, 0xFFFFFF, "INCREASE : Q");
	mlx_string_put(e->w.mp, e->w.wp, 50, 250, 0xFFFFFF, "DECREASE : E");
	mlx_string_put(e->w.mp, e->w.wp, 30, 270, 0xFFFFFF, "ROTATE");
	mlx_string_put(e->w.mp, e->w.wp, 50, 285, 0xFFFFFF, "COUNTER : K");
	mlx_string_put(e->w.mp, e->w.wp, 50, 300, 0xFFFFFF, "CLOCK : N");
	mlx_string_put(e->w.mp, e->w.wp, 30, 320, 0xFFFFFF, "RESET : R");
	mlx_string_put(e->w.mp, e->w.wp, e->w.wx - 80, 20, 0xFFFFFF, "FDF");
}

void		window(t_env *e)
{
	e->w.wx = 1632;
	e->w.wy = 1224;
	e->pl.hx = e->w.wx / 2;
	e->pl.hy = e->w.wy / 2;
	e->hi = 5;
	e->zo = 1;
	e->r_check = 0;
	e->r = M_PI / 74;
	e->iso_check = 1;
	e->spax = 30;
	if ((e->pl.lx * e->spax) > (e->w.wx - 50))
		while (e->spax-- >= 5)
			if ((e->pl.lx * e->spax) <= (e->w.wx - 50))
				break ;
	e->spay = 30;
	if ((e->pl.ly * e->spay + e->hi) > (e->w.wy - 50))
		while (e->spay-- >= 5)
			if ((e->pl.ly * e->spay) <= (e->w.wy - 50))
				break ;
	ft_bzero(e->k, sizeof(e->k));
	e->pl.px = e->pl.hx - ((e->pl.lx * e->spax) / 2);
	e->pl.py = e->pl.hy - ((e->pl.ly * e->spay) / 2);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		ret;
	t_env	*e;
	t_ll	*head;

	if (argc != 2)
		error(1);
	if (!(e = (t_env*)malloc(sizeof(t_env))))
		return (0);
	ft_bzero(e, sizeof(t_env));
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		error(2);
	if (((ret = reader(fd, e)) > 0))
		error(ret);
	if ((e->pl.lx <= 2 && e->pl.ly <= 1) || (e->pl.lx <= 1 && e->pl.ly <= 2))
		return (4);
	window(e);
	head = e->lines;
	if (!(points(e)))
		error(7);
	e->title = argv[1];
	if (visualize(e) == -1)
		error(6);
	return (0);
}
