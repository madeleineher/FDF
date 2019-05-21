/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:43:49 by mhernand          #+#    #+#             */
/*   Updated: 2019/05/10 17:23:32 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	reset(t_env *e)
{
	e->ml = 0;
	e->mx = 0;
	e->my = 0;
	e->zo = 1;
	e->hi = 5;
	e->hi = 5;
	e->zo = 1;
	e->r = M_PI / 74;
	e->r_check = 0;
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
	e->pla.px = e->pla.hx - ((e->pla.lx * e->spax) / 2);
	e->pla.py = e->pla.hy - ((e->pla.ly * e->spay) / 2);
}

void	rotate(t_env *e, int x, int y)
{
	int tmp_x;

	tmp_x = e->co[y][x].x2;
	if (e->r_check > 0)
	{
		e->co[y][x].x2 = cos(e->r) * tmp_x + sin(e->r) * e->co[y][x].y2;
		e->co[y][x].y2 = -sin(e->r) * tmp_x + cos(e->r) * e->co[y][x].y2;
	}
}

void	iso(t_env *e, int y)
{
	int	x;

	while (++y < e->pla.ly)
	{
		x = -1;
		while (++x < e->pla.lx)
		{
			if (e->iso == 0)
				e->iso = e->pla.hx - ((y - x) * (e->spax / 2) + e->pla.px);
			e->co[y][x].x2 = (x - y) * (e->spax / 2)
				+ e->pla.px + e->iso + e->ml + e->mx;
			e->co[y][x].y2 = (x + y) * (e->spay / 2) + e->pla.py + e->ml
				+ e->my - (e->co[y][x].z * e->hi);
			if (e->r_check > 0)
				rotate(e, x, y);
		}
	}
}

void	projection(t_env *e)
{
	int	x;
	int	y;

	y = -1;
	if (e->iso_check == 1)
	{
		while (++y < e->pla.ly)
		{
			x = -1;
			while (++x < e->pla.lx)
			{
				e->co[y][x].x2 = (e->pla.px + x * e->spax) + e->ml + e->mx;
				e->co[y][x].y2 = (e->pla.py + y * e->spay) + e->ml + e->my
					- (e->co[y][x].z * e->hi);
				if (e->r_check > 0)
					rotate(e, x, y);
			}
		}
	}
	else if (e->iso_check == 2)
		iso(e, y);
}
