/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:54:59 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/29 18:11:14 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	move_x(t_cor co, t_cor nx, t_env *e)
{
	int tmp_y;

	tmp_y = 1;
	if (e->be.dy < 0)
	{
		tmp_y = -1;
		e->be.dy = -e->be.dy;
	}
	e->be.dec = e->be.tdy - e->be.dx;
	while (co.x2++ < nx.x2)
	{
		mlx_pixel_put(e->w.mp, e->w.wp, co.x2, co.y2, 0xFFFFFF);
		if (e->be.dec > 0)
		{
			co.y2 += tmp_y;
			e->be.dec = e->be.dec - e->be.tdx;
		}
		e->be.dec = e->be.dec + e->be.tdy;
	}
}

void	special(t_cor co, t_cor nx, t_env *e)
{
	int tmp_y;

	tmp_y = 1;
	if (e->be.dy < 0)
	{
		tmp_y = -1;
		e->be.dy = -e->be.dy;
	}
	e->be.dec = e->be.tdy - e->be.dx;
	while (co.x2-- > nx.x2)
	{
		mlx_pixel_put(e->w.mp, e->w.wp, co.x2, co.y2, 0xFFFFFF);
		if (e->be.dec > 0)
		{
			co.y2 += tmp_y;
			e->be.dec = e->be.dec - e->be.tdx;
		}
		e->be.dec = e->be.dec + e->be.tdy;
	}
}

void	move_y(t_cor co, t_cor nx, t_env *e)
{
	int tmp_x;

	tmp_x = 1;
	if (e->be.dx < 0)
	{
		tmp_x = -1;
		e->be.dx = -e->be.dx;
	}
	e->be.dec = e->be.tdx - e->be.dy;
	while (co.y2++ < nx.y2)
	{
		mlx_pixel_put(e->w.mp, e->w.wp, co.x2, co.y2, 0xFFFFFF);
		if (e->be.dec > 0)
		{
			co.x2 += tmp_x;
			e->be.dec = e->be.dec - e->be.tdy;
		}
		e->be.dec = e->be.dec + e->be.tdx;
	}
}

void	lines(t_cor co, t_cor nx, t_env *e)
{
	e->be.dx = abs(nx.x2 - co.x2);
	e->be.dy = abs(nx.y2 - co.y2);
	e->be.tdx = 2 * e->be.dx;
	e->be.tdy = 2 * e->be.dy;

	if ((nx.x2 - co.x2) < 0)
		special(co, nx, e);
	else if ((nx.y2 - co.y2) < (nx.x2 - co.x2))
	{
		if (co.x2 > nx.x2)
			move_x(nx, co, e);
		else
			move_x(co, nx, e);
	}
	else
	{
		if (co.y2 > nx.y2)
			move_y(nx, co, e);
		else
			move_y(co, nx, e);
	}
}
