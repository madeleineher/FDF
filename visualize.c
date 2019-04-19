
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:29:44 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/19 11:40:36 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		quit(t_env *ev)
{
	(void)ev;
	exit(0);
	return (0);
}

int		key_release(int key, t_env *ev)
{
	ev->ks[key] = 0;
	return (0);
}

int		key_press(int key, t_env *ev)
{
	ev->ks[key] = 1;
	return (0);
}

void	fake_draw_x(t_cor co, t_cor nxt, t_env *ev)
{
	while (co.x2 < nxt.x2)
	{
		mlx_pixel_put(ev->win.m_p, ev->win.w_p, co.x2, co.y2,  0x00FF00);
		co.x2++;
	}
}

void	fake_draw_y(t_cor co, t_cor nxt, t_env *ev)
{
	while (co.y2 < nxt.y2)
	{
		mlx_pixel_put(ev->win.m_p, ev->win.w_p, co.x2, co.y2,  0x00FF00);
		co.y2++;
	}
}

int		visualize(t_env *ev)
{
	ev->win.m_p = mlx_init(); //NEED
	if (!(ev->win.m_p)) // NEED
		return (-1);
	ev->win.w_p = mlx_new_window(ev->win.m_p, ev->win.wx, ev->win.wy, "FDF"); //NEED
	texting(ev); //NEED
	mlx_pixel_put(ev->win.m_p, ev->win.w_p, ev->pla.hx, ev->pla.hy, 0x00FF00);
	
	int y = 0;
	int x;
	while (y < ev->pla.ly)
	{
		x = 0;
		while (x < ev->pla.lx)
		{
			//mlx_pixel_put(ev->win.m_p, ev->win.w_p, ev->co[y][x].x2, ev->co[y][x].y2, 0xFF0000);
			if (y + 1 < ev->pla.ly)
				fake_draw_y(ev->co[y][x], ev->co[y + 1][x], ev);
			if (x + 1 < ev->pla.lx)
				fake_draw_x(ev->co[y][x], ev->co[y][x + 1], ev);
			x++;
		}
		y++;
	}

	// these need to be separate from above 
	mlx_hook(ev->win.w_p, 2, 1L << 2, key_press, ev);
	mlx_hook(ev->win.w_p, 3, 1L << 3, key_release, ev);
	mlx_hook(ev->win.w_p, 17, 1L << 17, quit, ev);
	mlx_loop_hook(ev->win.m_p, touch, ev); // call touch function here !
	mlx_loop(ev->win.m_p);
	return (0);
}
