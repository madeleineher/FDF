
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:29:44 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/19 11:40:36 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		quit(t_env *e)
{
	(void)e;
	exit(0);
	return (0);
}

int		key_release(int key, t_env *e)
{
	e->ks[key] = 0;
	return (0);
}

int		key_press(int key, t_env *e)
{
	e->ks[key] = 1;
	return (0);
}

int		tmp(t_env *e)
{
	texting(e);
	draw_me(e);
	mlx_hook(e->w.wp, 2, 1L << 2, key_press, e); // these need to be separate from above 
	mlx_hook(e->w.wp, 3, 1L << 3, key_release, e);
	mlx_hook(e->w.wp, 17, 1L << 17, quit, e);
	mlx_loop_hook(e->w.mp, touch, e); // call touch function here !
	mlx_loop(e->w.mp);
	return (0);
}

int		visualize(t_env *e)
{
	if (!(e->w.mp = mlx_init()) 
			|| (!(e->w.wp = mlx_new_window(e->w.mp, e->w.wx, e->w.wy, "FDF"))))
		return (-1);
	if (!(e->i.img = mlx_new_image(e->w.mp, e->w.wx, e->w.wy)))
		return (-1);
	e->i.data = mlx_get_data_addr(e->i.img, &e->i.bpp, &e->i.s_li, &e->i.ed);
	tmp(e);
	return (0);
}
