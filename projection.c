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
		}
	}
}

void	projection(t_env *e)
{
	int	x;
	int	y;
	int tmp_x;

	tmp_x = 0;
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
				if (e->ks[K])
				{
					tmp_x = e->co[y][x].x2;
					e->co[y][x].x2 = cos(e->r) * tmp_x + sin(e->r) * e->co[y][x].y2;
					e->co[y][x].y2 = -sin(e->r) * tmp_x + cos(e->r) * e->co[y][x].y2;
				}
			}
		}
	}
	else if (e->iso_check == 2)
		iso(e, y);
}
