/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:04:51 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/26 17:10:01 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

/*void	boundaries(t_env *e, int x, int y)
{
	if (e->co[y][x].x2 < 50)
		e->mm += 50;
	if (e->co[y][x].x2 > e->w.wx - 50)
		e->mm -= 50;
	if (e->co[y][x].y2 < 50)
		e->mm += 50;
	if (e->co[y][x].y2 > e->w.wy - 50)
		e->mm -= 50;
}*/

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
	//if (e->co[y][x].x2 < 50 || e->co[y][x].x2 > e->w.wx - 50 
	//	|| e->co[y][x].y2 < 50 || e->co[y][x].y2 > e->w.wy - 50)
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
}

int		touch(t_env *e)
{
	if (e->ks[KEY_1] || e->ks[KEY_2] || e->ks[A] || e->ks[D] || e->ks[S] || e->ks[W])
		mlx_clear_window(e->w.mp, e->w.wp);
		mlx_put_image_to_window(e->w.mp, e->w.wp, e->i.img, e->w.wx, e->w.wy);
	if (e->ks[ESC])
	{
		delevr(e, 2);
		//mlx_destroy_window(e->w.mp, e->w.wp); // malloc error
		//mlx_destroy_image(e->w.mp, e->w.wp);
		exit(0);
	}
	if (e->ks[A] || e->ks[D] || e->ks[W] || e->ks[S]) // move the map
		move(e);
	//if (e->ks[C]) // add color
	//	coulour(e);
	//if (e->ks[I] || e->ks[O]) // zoom (?) in on the mqp
	//	zoom(e);
	if (e->ks[KEY_1] || e->ks[KEY_2]) // configure the projection
		projection(e);
	if (e->ks[M] || e->ks[L]) // space between pixels
		space(e);
	//if (e->ks[_] || e->ks[_]) // rotate the map
	//	rotate(e);
	return (0);
}
