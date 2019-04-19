/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:04:51 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/19 16:40:59 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
/*
void	move(t_env *ev)
{
	if (ev->ks[A])	// just ifs - add to x and y values , keep in boundaries, needs to be a while loop
	{
		ev->co.x1 = ev->co.x1 - 10;
		mlx_pixel_put(ev->win.m_p, ev->win.w_p, ev->co.x1, ev->co.y1,  0x00FF00);
		if (ev->co.x1 < 50)
		{
			ev->co.x1 = 50;
			mlx_pixel_put(ev->win.m_p, ev->win.w_p, ev->co.x1, ev->co.y1,  0x00FF00);
		}
	}
	if (ev->ks[D])
	{
		ev->co.x1 = ev->co.x1 + 10;
		mlx_pixel_put(ev->win.m_p, ev->win.w_p, ev->co.x1, ev->co.y1,  0x00FF00);
		if (ev->co.x1 > ev->win.wx - 50)
		{
			ev->co.x1 = ev->co.x1 - 50;
			mlx_pixel_put(ev->win.m_p, ev->win.w_p, ev->co.x1, ev->co.y1,  0x00FF00);
		}
	}
	if (ev->ks[W])
	{
		ev->co.y1 = ev->co.y1 - 10;
		mlx_pixel_put(ev->win.m_p, ev->win.w_p, ev->co.x1, ev->co.y1,  0x00FF00);
		if (ev->co.y1 < 50)
		{
			ev->co.y1 = 50;
			mlx_pixel_put(ev->win.m_p, ev->win.w_p, ev->co.x1, ev->co.y1,  0x00FF00);
		}
	}
	if (ev->ks[S])
	{
		ev->co.y1 = ev->co.y1 + 10;
		mlx_pixel_put(ev->win.m_p, ev->win.w_p, ev->co.x1, ev->co.y1,  0x00FF00);
		if (ev->co.y1 > ev->win.wy - 50)
		{
			ev->co.y1= ev->co.y1 - 50;
			mlx_pixel_put(ev->win.m_p, ev->win.w_p, ev->co.x1, ev->co.y1,  0x00FF00);
		}
	}
	// call visualize here to redraw the map
}
*/
int		touch(t_env *ev)
{
	if (ev->ks[ESC]) // can be added to 
	{
		delevr(ev);
		exit(0);
	}
//	if (ev->ks[A] || ev->ks[D] || ev->ks[W] || ev->ks[S])
//		move(ev);
	/*if (ev->ks[C])
	{
		
	}
	if (ev->ks[I])
	{
		
	}
	if (ev->ks[O])
	{
		
	}
	if (ev->ks[KEY_1])
	{
		
	}
	if (ev->ks[KEY_2])
	{
		
	}
	if (ev->ks[M])
	{
		
	}
	if (ev->ks[L])
	{
		
	}*/
	return (0);
}
