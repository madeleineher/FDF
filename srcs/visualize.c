/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:29:44 by mhernand          #+#    #+#             */
/*   Updated: 2020/01/21 16:09:38 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		quit(t_env *e)
{
	(void)e;
	exit(0);
	return (0);
}

int		key_release(int key, t_env *e)
{
	e->k[key] = 0;
	return (0);
}

int		key_press(int key, t_env *e)
{
	e->k[key] = 1;
	return (0);
}

int		redraw(t_env *e)
{
	draw_lines(e);
	mlx_put_image_to_window(e->w.mp, e->w.wp, e->i.ig, 0, 0);
	texting(e);
	mlx_hook(e->w.wp, 2, 1L << 2, key_press, e);
	mlx_hook(e->w.wp, 3, 1L << 3, key_release, e);
	mlx_hook(e->w.wp, 17, 1L << 17, quit, e);
	mlx_loop_hook(e->w.mp, touch, e);
	mlx_loop(e->w.mp);
	return (0);
}

int		visualize(t_env *e)
{
	if (!(e->w.mp = mlx_init())
		|| (!(e->w.wp = mlx_new_window(e->w.mp, e->w.wx, e->w.wy, e->title))))
		return (-1);
	if (!(e->i.ig = mlx_new_image(e->w.mp, e->w.wx, e->w.wy)))
		return (-1);
	if (!(e->i.dt = mlx_get_data_addr(e->i.ig, &e->i.bp, &e->i.sl, &e->i.ed)))
		return (-1);
	redraw(e);
	return (0);
}
