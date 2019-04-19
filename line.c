/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:54:59 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/19 19:42:43 by mhernand         ###   ########.fr       */
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
void	hore(t_env *ev)
{
	if (ev->tp.x1 < ev->tp.x2)
	{
		mlx_pixel_put(ev->win.m_p, ev->win.w_p, ev->tp.x1 + ev->pla.px + ev->spa, ev->tp.y1 + ev->pla.py + ev->spa, 0xFF0000);
		//printf("x : [%d] ++ ", ev->tp.x1);
		//printf(" y : [%d] ", ev->tp.y1);
	}
}

void	lines(t_env *ev)
{
	ev->be.m = abs(ev->tp.y2 - ev->tp.y1) / abs(ev->tp.x2 - ev->tp.x1); // correct parameter needs to be sent
	ev->be.tdydx = 2 * ((ev->tp.y2 - ev->tp.y1) - (ev->tp.x2 - ev->tp.x1));
	ev->be.tdxdy = 2 * ((ev->tp.x2 - ev->tp.x1) - (ev->tp.y2 - ev->tp.y1));

	if (ev->be.m == 0) // horizontal line ~*
		hore(ev);
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
