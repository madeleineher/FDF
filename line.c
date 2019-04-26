/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:54:59 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/26 17:14:56 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	slope_plus_one(t_cor co, t_cor nx, t_env *e, int dec)
{
	while (co.y2++ < nx.y2)
	{
		if (dec >= 0)
		{
			dec = dec + e->be.tdxdy;
			co.x2++;
		}
		else if (dec < 0)
			dec = dec + (2 * e->be.dx);
		mlx_pixel_put(e->w.mp, e->w.wp, co.x2, co.y2, 0xFFFFFF);
	}
}

void	slope_less_one(t_cor co, t_cor nx, t_env *e, int dec)
{
	while (co.x2++ < nx.x2)
	{
		printf("drawing, [%d] [%d]\n", co.x2, co.y2);
		if (dec >= 0)
		{
			dec = dec + e->be.tdydx;
			co.y2++;
		}
		else if (dec < 0)
			dec = dec + (2 * e->be.dy);
		mlx_pixel_put(e->w.mp, e->w.wp, co.x2, co.y2, 0xFFFFFF);
	}
}

void	vertical_horizontal(t_cor co, t_cor nx, t_env *e)
{
	if (e->be.dy == 0)
	{
		while (co.x2++ < nx.x2)
		{
		//	if (co.z != 0)
		//		mlx_pixel_put(e->w.mp, e->w.wp, co.x2, co.y2 - (co.z * 30), 0x00FF00);
		//	else
			mlx_pixel_put(e->w.mp, e->w.wp, co.x2, co.y2, 0xFFFFFF);
		}
	}
	else if (e->be.dx == 0)
	{
		while (co.y2++ < nx.y2)
		{
		//	if (co.z != 0)
		//		mlx_pixel_put(e->w.mp, e->w.wp, co.x2, co.y2 - (co.z * 30), 0x00FF00);
		//	else
			mlx_pixel_put(e->w.mp, e->w.wp, co.x2, co.y2, 0xFFFFFF);
		}
	}
}

void	lines(t_cor co, t_cor nx, t_env *e)
{
	e->be.dx = (nx.x2 - co.x2);
	e->be.dy = (nx.y2 - co.y2);
	if (e->be.dx == 0 || e->be.dy == 0) 
		vertical_horizontal(co, nx, e);
	else if (e->be.dx != 0 && e->be.dy != 0)
	{
		e->be.m = e->be.dy / e->be.dx;
		e->be.tdydx = 2 * (e->be.dy - e->be.dx);
		e->be.tdxdy = 2 * (e->be.dx - e->be.dy);
		printf("slope : [%d] \t tdydx : [%d] - tdxdy : [%d] \t point 1 : x [%d] - y [%d] \t point 2 : x [%d] - y [%d]\n", e->be.m, e->be.tdydx, e->be.tdxdy, co.x2, co.y2, nx.x2, nx.y2);
		if (e->be.m > 1)
		{
			e->be.dec = (2 * e->be.dx) - e->be.dy;
			slope_plus_one(co, nx, e, e->be.dec);
		}
		else if (e->be.m <= 1)
		{
			e->be.dec = (2 * e->be.dy) - e->be.dx;
			slope_less_one(co, nx, e, e->be.dec);
		}
	}
}
