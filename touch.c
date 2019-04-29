/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:04:51 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/29 18:11:20 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
/*
void	boundaries(t_env *e, int x, int y)
{
	if (e->co[y][x].x2 < -816)
	{
		e->mx = 0;
		e->my = 0;
	}
	if (e->co[y][x].x2 > -612)
	{
		e->mx = 0;
		e->my = 0;
	}
	if (e->co[y][x].y2 < 2448)
	{
		e->mx = 0;
		e->my = 0;
	}
	if (e->co[y][x].y2 > 1836)
	{
		e->mx = 0;
		e->my = 0;
	}
}
*/
void	move(t_env *e)
{
	if (e->ks[A])
		e->mx -= 10;
	if (e->ks[D])
		e->mx += 10;
	if (e->ks[W])
		e->my -= 10;
	if (e->ks[S])
		e->my += 10;
	//if (e->co[y][x].x2 < -816 || e->co[y][x].x2 > -612 
	//	|| e->co[y][x].y2 < 2448 || e->co[y][x].y2 > 1836)
	//	boundaries(e, x, y);
	// call visualize here to redraw the map
	//visualize(e);
}

void	space(t_env *e)
{
	if (e->ks[M])
	{
		e->mx += 10;
		e->my += 10;
	}
	if (e->ks[L])
	{
		e->mx -= 10;
		e->my -= 10;
	}
	printf("mx : [%d] == my :[%d]\n", e->mx, e->my);
}

int		touch(t_env *e)
{
	//if (e->ks[KEY_1] || e->ks[KEY_2])
	//	mlx_clear_window(e->w.mp, e->w.wp);
	//	mlx_put_image_to_window(e->w.mp, e->w.wp, e->i.img, e->w.wx, e->w.wy);
	if (e->ks[ESC])
	{
		delevr(e, 2);
	//	mlx_destroy_window(&e->w.mp, &e->w.wp); // malloc error
	//	mlx_destroy_image(e->w.mp, e->w.wp);
		exit(0);
	}
	if (e->ks[A] || e->ks[D] || e->ks[W] || e->ks[S]) // move the map
	{
		move(e);
		mlx_clear_window(e->w.mp, e->w.wp);
		mlx_put_image_to_window(e->w.mp, e->w.wp, e->i.img, e->w.wx, e->w.wy);
		visualize(e, 1);
	}
	//if (e->ks[C]) // add color
	//	coulour(e);
	//if (e->ks[I] || e->ks[O]) // zoom (?) in on the mqp
	//	zoom(e);
	if (e->ks[KEY_1] || e->ks[KEY_2]) // configure the projection
	{
		projection(e);
		mlx_clear_window(e->w.mp, e->w.wp);
		mlx_put_image_to_window(e->w.mp, e->w.wp, e->i.img, e->w.wx, e->w.wy);
		visualize(e, 1);
	}
	if (e->ks[M] || e->ks[L]) // space between pixels
	{
		space(e);
		mlx_clear_window(e->w.mp, e->w.wp);
		mlx_put_image_to_window(e->w.mp, e->w.wp, e->i.img, e->w.wx, e->w.wy);
		visualize(e, 1);
	}
	//if (e->ks[_] || e->ks[_]) // rotate the map
	//	rotate(e);
	return (0);
}
