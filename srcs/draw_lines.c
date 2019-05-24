/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:54:59 by mhernand          #+#    #+#             */
/*   Updated: 2019/05/24 16:39:20 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		line_setup(t_cor co, t_cor nx, t_cor *tmp, t_env *e)
{
	tmp->x2 = co.x2;
	tmp->y2 = co.y2;
	tmp->z = co.z;
	e->b.dx = nx.x2 - co.x2;
	e->b.dy = nx.y2 - co.y2;
	e->b.ix = (e->b.dx > 0) ? 1 : -1;
	e->b.iy = (e->b.dy > 0) ? 1 : -1;
	e->b.dx = abs(e->b.dx);
	e->b.dy = abs(e->b.dy);
	if (tmp->x2 > 0 && tmp->x2 < 1632 && tmp->y2 > 0 && tmp->y2 < 1224)
		*(int *)&e->i.dt[tmp->x2 * (e->i.bp / 8) + tmp->y2 * e->i.sl] = e->c;
	e->b.tdx = e->b.dx / 2;
	e->b.tdy = e->b.dy / 2;
}

void		lines2(t_cor tmp, t_env *e, t_cor nx, int i)
{
	while (++i < e->b.dy)
	{
		if (e->b.dy / 2 == i && tmp.z != nx.z)
		{
			e->c = color_me(tmp, nx, e, 2);
		}
		tmp.y2 += e->b.iy;
		e->b.tdy += e->b.dx;
		if (e->b.tdy >= e->b.dy)
		{
			e->b.tdy -= e->b.dy;
			tmp.x2 += e->b.ix;
		}
		if (tmp.x2 > 0 && tmp.x2 < 1632 && tmp.y2 > 0 && tmp.y2 < 1224)
			*(int *)&e->i.dt[tmp.x2 * (e->i.bp / 8) + tmp.y2 * e->i.sl] = e->c;
	}
}

void		lines(t_cor co, t_cor nx, t_env *e)
{
	int		i;
	t_cor	tmp;

	i = -1;
	line_setup(co, nx, &tmp, e);
	if (e->b.dx > e->b.dy)
	{
		while (++i < e->b.dx)
		{
			if (e->b.dx / 2 == i && co.z != nx.z)
				e->c = color_me(tmp, nx, e, 2);
			tmp.x2 += e->b.ix;
			e->b.tdx += e->b.dy;
			if (e->b.tdx >= e->b.dx)
			{
				e->b.tdx -= e->b.dx;
				tmp.y2 += e->b.iy;
			}
			if (tmp.x2 > 0 && tmp.x2 < 1632 && tmp.y2 > 0 && tmp.y2 < 1224)
				*(int *)&e->i.dt[tmp.x2 * (e->i.bp / 8)
					+ tmp.y2 * e->i.sl] = e->c;
		}
	}
	else
		lines2(tmp, e, nx, i);
}

void		draw_lines(t_env *e)
{
	int		x;
	int		y;

	ft_bzero(e->i.dt, sizeof(e->i.dt));
	e->c = 0xffffff;
	y = -1;
	while (++y < e->pl.ly)
	{
		x = -1;
		while (++x < e->pl.lx)
		{
			if (x + 1 < e->pl.lx)
			{
				e->c = color_me(e->co[y][x], e->co[y][x + 1], e, 1);
				lines(e->co[y][x], e->co[y][x + 1], e);
			}
			if (y + 1 < e->pl.ly)
			{
				e->c = color_me(e->co[y][x], e->co[y][x + 1], e, 1);
				lines(e->co[y][x], e->co[y + 1][x], e);
			}
		}
	}
}
