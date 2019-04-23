
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

int		quit(t_env *e)
{
	(void)e;
	exit(0);
	return (0);
}

int		key_release(int key, t_env *e)
{
	e->ks[key] = 0;
	return (0);
}

int		key_press(int key, t_env *e)
{
	e->ks[key] = 1;
	return (0);
}

void	fake_draw_x(t_cor co, t_cor nxt, t_env *e)
{
	while (co.x2 < nxt.x2)
	{
		mlx_pixel_put(e->w.m_p, e->w.w_p, co.x2, co.y2,  0x00FF00);
		co.x2++;
	}
}

void	fake_draw_y(t_cor co, t_cor nxt, t_env *e)
{
	while (co.y2 < nxt.y2)
	{
		mlx_pixel_put(e->w.m_p, e->w.w_p, co.x2, co.y2,  0x00FF00);
		co.y2++;
	}
}

int		visualize(t_env *e)
{
	e->w.m_p = mlx_init(); //NEED
	if (!(e->w.m_p)) // NEED
		return (-1);
	e->w.w_p = mlx_new_window(e->w.m_p, e->w.wx, e->w.wy, "FDF"); //NEED
	texting(e); //NEED
	mlx_pixel_put(e->w.m_p, e->w.w_p, e->pla.hx, e->pla.hy, 0xFF0000);
	
	int y = 0;
	int x;
	while (y < e->pla.ly)
	{
		x = 0;
		while (x < e->pla.lx)
		{
			//mlx_pixel_put(e->w.m_p, e->w.w_p, e->co[y][x].x2, e->co[y][x].y2, 0xFF0000);
			if (y + 1 < e->pla.ly)
				fake_draw_y(e->co[y][x], e->co[y + 1][x], e);
			if (x + 1 < e->pla.lx)
				fake_draw_x(e->co[y][x], e->co[y][x + 1], e);
			x++;
		}
		y++;
	}

	// these need to be separate from above 
	mlx_hook(e->w.w_p, 2, 1L << 2, key_press, e);
	mlx_hook(e->w.w_p, 3, 1L << 3, key_release, e);
	mlx_hook(e->w.w_p, 17, 1L << 17, quit, e);
	mlx_loop_hook(e->w.m_p, touch, e); // call touch function here !
	mlx_loop(e->w.m_p);
	return (0);
}
