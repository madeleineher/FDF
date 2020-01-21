/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:04:51 by mhernand          #+#    #+#             */
/*   Updated: 2020/01/21 16:09:30 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

void	space(t_env *e)
{
	if (e->k[M])
	{
		e->spax += 1;
		e->spay += 1;
	}
	if (e->k[L])
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

void	move(t_env *e)
{
	if (e->k[A])
		e->mx -= 5;
	if (e->k[D])
		e->mx += 5;
	if (e->k[W])
		e->my -= 5;
	if (e->k[S])
		e->my += 5;
	if (e->mx > 2000 || e->mx < -2000)
		e->mx = 0;
	if (e->my > 2000 || e->my < -2000)
		e->my = 0;
	if (e->k[Q])
		e->hi += 1;
	if (e->k[E])
		e->hi -= 1;
	if (e->hi < -100 || e->hi > 100)
		e->hi = 0;
}

int		touch(t_env *e)
{
	if (e->k[ESC])
		delevr(e, 2);
	if (e->k[R])
		reset(e);
	if (e->k[A] || e->k[D] || e->k[W] || e->k[S] || e->k[Q] || e->k[E])
		move(e);
	if (e->k[M] || e->k[L])
		space(e);
	if (e->k[K] || e->k[N])
	{
		if (e->k[K])
			e->r_check = 1;
		else
			e->r_check = 2;
		e->r += (e->r_check == 1 ? (M_PI / 74) : (M_PI / 74) * -1);
	}
	if (e->k[KEY_1])
		e->iso_check = 1;
	if (e->k[KEY_2])
		e->iso_check = 2;
	if (e->k[Q] || e->k[E] || e->k[M] || e->k[K] || e->k[N] || e->k[L]
		|| e->k[A] || e->k[D] || e->k[W] || e->k[S] || e->k[R] || e->k[KEY_1]
		|| e->k[KEY_2])
		clean(e);
	return (0);
}
