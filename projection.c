/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:43:49 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/25 18:53:37 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	projection(t_env *e)
{
	int	x;
	int	y;

	y = -1;
	if (e->ks[KEY_1]) // parallel
	{
		while (++y < e->pla.ly)
		{
			x = -1;
			while (++x < e->pla.lx)
			{
				e->co[y][x].x2 = (e->pla.px + x * e->spax);
				e->co[y][x].y2 = (e->pla.py + y * e->spay);
				mlx_pixel_put(e->w.mp, e->w.wp, e->co[y][x].x2, e->co[y][x].y2, 0x00FF00);
			}
		}
	}
	else if (e->ks[KEY_2]) // isometric
	{
		while (++y < e->pla.ly)
		{
			x = -1;
			while (++x < e->pla.lx)
			{
				e->co[y][x].x2 = (y - x) * (e->spax / 2) + e->pla.px + 270; 
				e->co[y][x].y2 = (x + y) * (e->spay / 2) + e->pla.py;
				//lines();
				mlx_pixel_put(e->w.mp, e->w.wp, e->co[y][x].x2, e->co[y][x].y2, 0x00FF00);
				printf("x : [%d] - y : [%d]\n", e->co[y][x].x2, e->co[y][x].y2);
			}
		}
	}
}
