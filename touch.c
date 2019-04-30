/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:04:51 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/30 19:24:36 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

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
	if (e->mx < -e->pla.hx || e->my > -e->pla.hy)
	{
		if (e->mx > 2 * e->w.wx || e->mx < -e->w.wx)
			e->mx = 0;
		if (e->my >  2 * e->w.wy || e->my < -e->w.wy)
			e->mx = 0;
	}
}

void	space(t_env *e)
{
	if (e->ks[M])
	{
		e->spax += 1;
		e->spay += 1;
	}
	if (e->ks[L])
	{
		e->spax -= 1;
		e->spay -= 1;
	}
}

void	depth(t_env *e)
{
	if (e->ks[Q])
		e->hi += 2;
	if (e->ks[E])
		e->hi -= 2;
}

int		touch(t_env *e)
{
	if (e->ks[ESC])
	{
		delevr(e, 2);
		mlx_destroy_image(e->w.mp, e->i.img);
		mlx_destroy_window(e->w.mp, e->w.wp);
		exit(0);
	}
	if (e->ks[A] || e->ks[D] || e->ks[W] || e->ks[S])
	{
		move(e);
		projection(e);
		mlx_clear_window(e->w.mp, e->w.wp);
		mlx_put_image_to_window(e->w.mp, e->w.wp, e->i.img, e->w.wx, e->w.wy);
		draw_me(e);
		tmp(e);
	}
	if (e->ks[M] || e->ks[L])
	{
		space(e);
		projection(e);
		mlx_clear_window(e->w.mp, e->w.wp);
		mlx_put_image_to_window(e->w.mp, e->w.wp, e->i.img, e->w.wx, e->w.wy);
		draw_me(e);
		tmp(e);
	}
	if (e->ks[Q] || e->ks[E])
	{
		depth(e);
		projection(e);
		mlx_clear_window(e->w.mp, e->w.wp);
		mlx_put_image_to_window(e->w.mp, e->w.wp, e->i.img, e->w.wx, e->w.wy);
		draw_me(e);
		tmp(e);
	}

	if (e->ks[KEY_1])
	{
		e->iso_check = 1;
		projection(e);
		mlx_clear_window(e->w.mp, e->w.wp);
		mlx_put_image_to_window(e->w.mp, e->w.wp, e->i.img, e->w.wx, e->w.wy);
		draw_me(e);
		tmp(e);
	}
	if (e->ks[KEY_2])
	{
		e->iso_check = 2; 
		projection(e);
		mlx_clear_window(e->w.mp, e->w.wp);
		mlx_put_image_to_window(e->w.mp, e->w.wp, e->i.img, e->w.wx, e->w.wy);
		draw_me(e);
		tmp(e);
	}
	return (0);
}
