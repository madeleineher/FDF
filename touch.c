/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:04:51 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/25 18:17:25 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	boundaries(t_env *e, int x, int y)
{
	if (e->co[y][x].x2 < 50)
	{
		e->co[y][x].x2 = 50;
		mlx_pixel_put(e->w.mp, e->w.wp, e->co[y][x].x2,
				e->co[y][x].y2, 0x00FF00);
	}
	if (e->co[y][x].x2 > e->w.wx - 50)
	{
		e->co[y][x].x2 = e->co[y][x].x2 - 50;
		mlx_pixel_put(e->w.mp, e->w.wp, e->co[y][x].x2, 
				e->co[y][x].y2, 0x00FF00);
	}
	if (e->co[y][x].y2 < 50)
	{
		e->co[y][x].y2 = 50;
		mlx_pixel_put(e->w.mp, e->w.wp, e->co[y][x].x2, 
				e->co[y][x].y2, 0x00FF00);
	}
	if (e->co[y][x].y2 > e->w.wy - 50)
	{
		e->co[y][x].y2 = e->co[y][x].y2 - 50;
		mlx_pixel_put(e->w.mp, e->w.wp, e->co[y][x].x2, 
				e->co[y][x].y2, 0x00FF00);
	}
}

void	move(t_env *e)
{
	int	y;
	int	x;

	y = -1;
	while (++y < e->pla.ly)
	{
		x = -1;
		while (++x < e->pla.lx)
		{
			if (e->ks[A])
				e->co[y][x].x2 = e->co[y][x].x2 - 10;
			if (e->ks[D])
				e->co[y][x].x2 = e->co[y][x].x2 + 10;
			if (e->ks[W])
				e->co[y][x].y2 = e->co[y][x].y2 - 10;
			if (e->ks[S])
				e->co[y][x].y2 = e->co[y][x].y2 + 10;
			mlx_pixel_put(e->w.mp, e->w.wp, e->co[y][x].x2, 
					e->co[y][x].y2, 0x00FF00);
			if (e->co[y][x].x2 < 50 || e->co[y][x].x2 > e->w.wx - 50 
					|| e->co[y][x].y2 < 50 || e->co[y][x].y2 > e->w.wy - 50)
				boundaries(e, x, y);
		}
	}// call visualize here to redraw the map
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
}

int		touch(t_env *e)
{
	if (e->ks[ESC])
	{
		// free everything here ! ~
		// mlx_destroy_image(e->w.mp, e->w.wp);
		// mlx_destroy_window(e->w.mp, e->w.wp);
		exit(0);
	}
	if (e->ks[A] || e->ks[D] || e->ks[W] || e->ks[S]) // move the map
		move(e);
	//if (e->ks[C]) // add color
	//	coulour(e);
	//if (e->ks[I] || e->ks[O]) // to zoom in on the mqp
	//	zoom(e);
	if (e->ks[KEY_1] || e->ks[KEY_2]) // configure the projection
		projection(e);
	if (e->ks[M] || e->ks[L]) // space between pixels
		space(e);
	//if (e->ks[_] || e->ks[_]) // rotate the map
	//	rotate(e);
	return (0);
}
