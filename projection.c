/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:43:49 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/26 17:07:27 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		cntr_iso(t_env *e, int dec)
{
	(void)e;

	dec = e->pla.hx - dec;
	printf("[%d]\n", dec);
	return (dec);
}

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
				//mlx_pixel_put(e->w.mp, e->w.wp, e->co[y][x].x2, e->co[y][x].y2, 0x00FF00);
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
				if (e->iso == 0)
					e->iso = cntr_iso(e, ((y - x) * (e->spax / 2) + e->pla.px));
				e->co[y][x].x2 = (y - x) * (e->spax / 2) + e->pla.px + e->iso; 
				e->co[y][x].y2 = (x + y) * (e->spay / 2) + e->pla.py;
			//	if (x + 1 < e->pla.lx)
			//		lines(e->co[y][x], e->co[y][x + 1], e);
			//	if (y + 1 < e->pla.ly)
			//		lines(e->co[y][x], e->co[y + 1][x], e);
			//	mlx_pixel_put(e->w.mp, e->w.wp, e->co[y][x].x2, e->co[y][x].y2, 0x00FEFF);
				//printf("x : [%d] - y : [%d]\n", e->co[y][x].x2, e->co[y][x].y2);
			}
		}
		visualize(e);
	}
}
