/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:04:51 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/23 19:17:33 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	boundaries(t_env *e, int x, int y)
{
	if (e->co[y][x].x2 < 50)
	{
		e->co[y][x].x2 = 50;
		mlx_pixel_put(e->w.m_p, e->w.w_p, e->co[y][x].x2, 
				e->co[y][x].y2, 0x00FF00);
	}
	if (e->co[y][x].x2 > e->w.wx - 50)
	{
		e->co[y][x].x2 = e->co[y][x].x2 - 50;
		mlx_pixel_put(e->w.m_p, e->w.w_p, e->co[y][x].x2, 
				e->co[y][x].y2, 0x00FF00);
	}
	if (e->co[y][x].y2 < 50)
	{
		e->co[y][x].y2 = 50;
		mlx_pixel_put(e->w.m_p, e->w.w_p, e->co[y][x].x2, 
				e->co[y][x].y2, 0x00FF00);
	}
	if (e->co[y][x].y2 > e->w.wy - 50)
	{
		e->co[y][x].y2 = e->co[y][x].y2 - 50;
		mlx_pixel_put(e->w.m_p, e->w.w_p, e->co[y][x].x2, 
				e->co[y][x].y2, 0x00FF00);
	}
}

void	move(t_env *e)
{
	int	y;
	int	x;

	y = -1;
	while (++y < e->pla.ly)
	{
		x = -1;
		while (++x < e->pla.lx)
		{
			if (e->ks[A])
				e->co[y][x].x2 = e->co[y][x].x2 - 10;
			if (e->ks[D])
				e->co[y][x].x2 = e->co[y][x].x2 + 10;
			if (e->ks[W])
				e->co[y][x].y2 = e->co[y][x].y2 - 10;
			if (e->ks[S])
				e->co[y][x].y2 = e->co[y][x].y2 + 10;
			mlx_pixel_put(e->w.m_p, e->w.w_p, e->co[y][x].x2, 
					e->co[y][x].y2, 0x00FF00);
			if (e->co[y][x].x2 < 50 || e->co[y][x].x2 > e->w.wx - 50 
					|| e->co[y][x].y2 < 50 || e->co[y][x].y2 > e->w.wy - 50)
				boundaries(e, x, y);
		}
	}// call visualize here to redraw the map
}

int		touch(t_env *e)
{
	if (e->ks[ESC]) // can be added to 
	{
		delevr(e);
		exit(0);
	}
	if (e->ks[A] || e->ks[D] || e->ks[W] || e->ks[S])
		move(e);
	/*if (e->ks[C])
	  {

	  }
	  if (e->ks[I])
	  {

	  }
	  if (e->ks[O])
	  {

	  }
	  if (e->ks[KEY_1])
	  {

	  }
	  if (e->ks[KEY_2])
	  {

	  }
	  if (e->ks[M])
	  {

	  }
	  if (e->ks[L])
	  {

	  }*/
	return (0);
}
