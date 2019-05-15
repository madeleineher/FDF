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

void	clean(t_env *e)
{
	int		i;
	int		j;

	j = -1;
	e->c = 0x000000;
	while (++j < 1224)
	{
		i = -1;
		while (++i < 1632)
			*(int *)&e->i.dt[i * (e->i.bp / 8) + j * e->i.sl] = e->c;
	}
	projection(e);
	draw_lines(e);
	mlx_put_image_to_window(e->w.mp, e->w.wp, e->i.ig, 0, 0);
	texting(e);
}

void	move(t_env *e)
{
	if (e->ks[A])
		e->mx -= 5;
	if (e->ks[D])
		e->mx += 5;
	if (e->ks[W])
		e->my -= 5;
	if (e->ks[S])
		e->my += 5;
	if (e->mx > 2000 || e->mx < -2000)
		e->mx = 0;
	if (e->my > 2000 || e->my < -2000)
		e->my = 0;
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
	if ((e->spax > 150 && e->spay > 150) || (e->spax < -150 && e->spay < -150))
	{
		e->spax = 0;
		e->spay = 0;
	}
}

void	depth(t_env *e)
{
	if (e->ks[Q])
		e->hi += 1;
	if (e->ks[E])
		e->hi -= 1;
	if (e->hi < -100 || e->hi > 100)
		e->hi = 0;
}

int		touch(t_env *e)
{
	if (e->ks[ESC])
	{
		delevr(e, 2);
		mlx_destroy_image(e->w.mp, e->i.ig);
		mlx_destroy_window(e->w.mp, e->w.wp);
		exit(0);
	}
	if (e->ks[A] || e->ks[D] || e->ks[W] || e->ks[S])
		move(e);
	if (e->ks[M] || e->ks[L])
		space(e);
	if (e->ks[K])
		e->r += M_PI/64;
	// if (e->ks[N])
	// 	e->r;
	if (e->ks[Q] || e->ks[E])
		depth(e);
	if (e->ks[KEY_1])
		e->iso_check = 1;
	if (e->ks[KEY_2])
		e->iso_check = 2;
	if (e->ks[KEY_1] || e->ks[KEY_2] || e->ks[Q] || e->ks[E] || e->ks[M]
		|| e->ks[K] || e->ks[N] || e->ks[L] || e->ks[A] || e->ks[D]
		|| e->ks[W] || e->ks[S])
		clean(e);
	return (0);
}
