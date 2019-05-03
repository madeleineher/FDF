/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:54:59 by mhernand          #+#    #+#             */
/*   Updated: 2019/05/01 21:12:50 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"


void	lines(t_cor co, t_cor nx, t_env *e)
{
	e->be.dx = abs(nx.x2 - co.x2);
	e->be.dy = abs(nx.y2 - co.y2);
	e->be.tdx = 2 * e->be.dx;
	e->be.tdy = 2 * e->be.dy;

	if (e->be.dx < e->be.dy && nx.x2 > co.x2 && nx.y2 < co.y2) // case 1 
	{
		e->be.dec = e->be.tdx - e->be.dy;
		while (co.y2 > nx.y2)
		{
			printf("hello\n");
			if (e->be.dec >= 0)	
			{
				e->be.dec -= e->be.tdy;
				co.x2--;
			}
			e->be.dec += e->be.tdy;
			co.y2--;
			mlx_pixel_put(e->w.mp, e->w.wp, co.x2, co.y2, 0xFF0000);
		}
	}
/*	if (e->be.dx > e->be.dy && nx.x2 > co.x2 && nx.y2 > co.y2) // case 2 
	{
		while (co.x2 < nx.x2)
		{
			
		}
	}
*/
}

void	draw_me(t_env *e)
{
	int		x;
	int		y;
	t_cor	tmp_0 = {0, 0, e->pla.hx, e->pla.hy, 0};
	t_cor	tmp_1 = {0, 0, e->pla.hx + 10, e->pla.hy - 400, 0};

	y = -1;
	x = 0;
	lines(tmp_0, tmp_1, e);
	/*
	while (++y < e->pla.ly)
	{
		x = -1;
		while (++x < e->pla.lx)
		{
			if (x + 1 < e->pla.lx)
				lines(e->co[y][x], e->co[y][x + 1], e);
			if (y + 1 < e->pla.ly)
				lines(e->co[y][x], e->co[y + 1][x], e);

		}
	}
	*/
}
