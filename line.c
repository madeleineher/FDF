/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:54:59 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/23 19:17:25 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
/*
void	diagnol()
{

}

void	slope_plus_one(t_env *ev)
{
	if ()

	else
	{
		// this all needs to be in a while loop
		if (ev->be.dec >= 0)
		{
			ev->be.x = ev->be.x + 1;
			ev->be.dec = ev->be.dec + ev->be.tdxdy;
		}
		else if (ev->be.dec < 0)
		{
			ev->be.x = ev->be.x;
			ev->be.dec = ev->be.dec + (2 * (ev->be.x2 - ev->be.x1));
		}
		ev->be.y = ev->be.y + 1;
		slope_plus_one(ev);
	}
}

void	slope_less_one(t_env *ev)
{
	if (ev->)

	else
	{
		// this all needs to be in a while loop
		if (ev->be.dec >= 0)
		{
			ev->be.y = ev->be.y + 1;
			ev->be.dec = ev->be.dec + ev->be.tdydx;
		}
		else if (ev->be.dec < 0)
		{
			ev->be.y = ev->be.y;
			ev->be.dec = ev->be.dec + (2 * (ev->be.y2 - ev->be.y1));
		}
		ev->be.x = ev->be.x + 1;
		slope_less_one(ev);
	}
}
*/
void	hore(t_env *e)
{
	if (e->tp.x1 < e->tp.x2)
	{
		mlx_pixel_put(e->w.m_p, e->w.w_p, e->tp.x1 + ev->pla.px + e->spa, e->tp.y1 + e->pla.py + ev->spa, 0xFF0000);
		//printf("x : [%d] ++ ", ev->tp.x1);
		//printf(" y : [%d] ", ev->tp.y1);
	}
}

void	lines(t_env *e)
{
	e->be.m = abs(e->tp.y2 - e->tp.y1) / abs(e->tp.x2 - e->tp.x1); // correct parameter needs to be sent
	e->be.tdydx = 2 * ((e->tp.y2 - e->tp.y1) - (e->tp.x2 - e->tp.x1));
	e->be.tdxdy = 2 * ((e->tp.x2 - e->tp.x1) - (e->tp.y2 - e->tp.y1));

	if (e->be.m == 0) // horizontal line ~*
		hore(e);
	/*
	if (ev->be.m > 1)
	{
		ev->be.dec = (2 * (ev->be.x2 - ev->be.x1)) - (y2 - y1);
		slope_less_one(ev);
	}
	else if (ev->be.m == 0) // horizontal line ~*
		hore(ev);
	else if (ev->be.m <= 1 && ev->be.m != 0)
	{
		ev->be.dec = (2 * (ev->be.y2 - ev->be.y1)) - (x2 - y1);
		slope_plus_one(ev);
	}
	*/
}
