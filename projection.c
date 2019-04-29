/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:43:49 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/29 18:11:36 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		cntr_iso(t_env *e, int dec)
{
	dec = e->pla.hx - dec;
	return (dec);
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
				e->iso = cntr_iso(e, ((y - x) * (e->spax / 2) + e->pla.px));
			e->co[y][x].x2 = (y - x) * (e->spax / 2) + e->pla.px + e->iso
				+ e->ml + e->mx + e->my;
			e->co[y][x].y2 = (x + y) * (e->spay / 2) + e->pla.py
				+ e->ml + e->mx + e->my;
		}
	}
}

void	projection(t_env *e)
{
	int	x;
	int	y;

	y = -1;
	if (e->ks[KEY_1])
	{
		while (++y < e->pla.ly)
		{
			x = -1;
			while (++x < e->pla.lx)
			{
				e->co[y][x].x2 = (e->pla.px + x * e->spax) + e->ml
					+ e->mx + e->my;
				e->co[y][x].y2 = (e->pla.py + y * e->spay) + e->ml
					+ e->mx + e->my;
				if (e->co[y][x].z > 0 && e->co[y][x].z != 0)
					e->co[y][x].y2 += (e->co[y][x].z * 10);
				else if (e->co[y][x].z < 0 && e->co[y][x].z != 0)
					e->co[y][x].y2 -= (e->co[y][x].z * 10);
			}
		}
	}
	else if (e->ks[KEY_2])
		iso(e, y);
}
