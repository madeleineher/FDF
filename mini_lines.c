/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:54:59 by mhernand          #+#    #+#             */
/*   Updated: 2019/05/07 11:21:14 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		color_me(t_cor co, t_cor nx, t_env *e)
{
	(void)co;
	(void)nx;
	(void)e;
	int couleur;

	couleur = 0xffffff;
	if (co.z <= 0)
		couleur = WATER;
	else if (co.z > 0 && co.z < 10)
		couleur = SAND;
	else if (co.z >= 10 && co.z < 20)
		couleur = GRASS;
	else if (co.z >= 20 && co.z < 40)
		couleur = ROCK;
	else if (co.z >= 40)
		couleur = SNOW;
	return (couleur);
}

static void		line_setup(t_cor co, t_cor nx, t_cor *tmp, t_env *e, int c)
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
	*(int *)&e->i.dt[tmp->x2 * (e->i.bpp / 8) + tmp->y2 * e->i.sl] = c;
	e->b.tdx = e->b.dx / 2;
	e->b.tdy = e->b.dy / 2;
}

void	lines(t_cor co, t_cor nx, t_env *e, int c)
{
	int		i;
	t_cor	tmp;

	i = -1;
	line_setup(co, nx, &tmp, e, c);
	if (e->b.dx > e->b.dy)
	{
		while (++i < e->b.dx)
		{
			tmp.x2 += e->b.ix;
			e->b.tdx += e->b.dy;
			if (e->b.tdx >= e->b.dx)
			{
				e->b.tdx -= e->b.dx;
				tmp.y2 += e->b.iy;
			}
			*(int *)&e->i.dt[tmp.x2 * (e->i.bpp / 8) + tmp.y2 * e->i.sl] = c;
		}
	}
	else
	{
		while (++i < e->b.dy)
		{
			tmp.y2 += e->b.iy;
			e->b.tdy += e->b.dx;
			if (e->b.tdy >= e->b.dy)
			{
				e->b.tdy -= e->b.dy;
				tmp.x2 += e->b.ix;
			}
			*(int *)&e->i.dt[tmp.x2 * (e->i.bpp / 8) + tmp.y2 * e->i.sl] = c;
		}
	}
}

void	draw_me(t_env *e)
{
	int		x;
	int		y;
	int		color;

	ft_bzero(e->i.dt, sizeof(e->i.dt));
	color = 0;
 	y = -1;
	while (++y < e->pla.ly)
	{
		x = -1;
		while (++x < e->pla.lx)
		{
			if (x + 1 < e->pla.lx)
			{
				color = color_me(e->co[y][x], e->co[y][x + 1], e);
				lines(e->co[y][x], e->co[y][x + 1], e, color);
			}
			if (y + 1 < e->pla.ly)
			{
				color = color_me(e->co[y][x], e->co[y][x + 1], e);
				lines(e->co[y][x], e->co[y + 1][x], e, color);
			}
		}
	}
}