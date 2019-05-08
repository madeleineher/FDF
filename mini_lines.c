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

void	lines(t_cor co, t_cor nx, t_env *e)
{
	int	er;
	e->b.dx = abs(nx.x2 - co.x2);
	e->b.dy = abs(nx.y2 - co.y2);
	int copy_dx = nx.x2 - co.x2;
	int copy_dy = nx.y2 - co.y2;
	e->b.tdx = 2 * e->b.dx;
	e->b.tdy = 2 * e->b.dy;

	int	inc_x = (copy_dx > 0 ? 1 : -1);
	int	inc_y = (copy_dy < 0 ? -1 : 1);

	if (copy_dx > 0)
	{
		if (copy_dy > 0) // 1ere cadran	
		{
			er = (copy_dx >= (copy_dy * inc_y) ? copy_dx : copy_dy);
			copy_dx = (er == copy_dx ? er * 2 : copy_dx * 2);
			copy_dy = (er == copy_dy ? er * 2 : copy_dy * 2);
			if (copy_dx >= copy_dy) // 1st octant // e est positif
			{
				while (e->b.t_x < nx.x2)
				{
					mlx_pixel_put(e->w.mp, e->w.wp, e->b.t_x++, e->b.t_y, 0xFFFFFF);
					if ((er = er - copy_dy) < 0)
					{
						e->b.t_y += inc_y;
						er += copy_dx;
					}
				}
			}
			else // 2nd octant // e est positif
			{
				while (e->b.t_y < nx.y2)
				{
					mlx_pixel_put(e->w.mp, e->w.wp, e->b.t_x, e->b.t_y++, 0xFFFFFF);
					if ((er = er - copy_dx) < 0)
					{
						e->b.t_x += inc_x;
						er += copy_dy;
					}
				}
			}
		}
		else if (copy_dy < 0) // 4th cadran
		{
			er = (copy_dx >= (copy_dy * inc_y) ? copy_dx : copy_dy);
			copy_dx = (er == copy_dx ? er * 2 : copy_dx * 2);
			copy_dy = (er == copy_dy ? er * 2 : copy_dy * 2);
			if (copy_dx >= (copy_dy * inc_y)) // 8e octant  // e est positif
			{
				while (e->b.t_x < nx.x2)
				{
					mlx_pixel_put(e->w.mp, e->w.wp, e->b.t_x++, e->b.t_y, 0xFFFFFF);
					if ((er = er + copy_dy) < 0)
					{
						e->b.t_y += inc_y;
						er += copy_dx;
					}	
				}
			}
			else // e est négatif
			{
				while (e->b.t_y > nx.y2)
				{
					mlx_pixel_put(e->w.mp, e->w.wp, e->b.t_x, e->b.t_y--, 0xFFFFFF);
					if ((er = er + copy_dx) > 0)
					{
						e->b.t_x += inc_x;
						er += copy_dy;
					}
				}
			}
		}
	}
	else if (copy_dx < 0)
	{
		if (copy_dy > 0) // 2eme quadran
		{
			er = ((copy_dx * inc_x) >= copy_dy ? copy_dx : copy_dy);
			copy_dx = (er == copy_dx ? er * 2 : copy_dx * 2);
			copy_dy = (er == copy_dy ? er * 2 : copy_dy * 2);
			if ((copy_dx * inc_x) >= copy_dy) // 4e octant // e est négatif
			{
				while (e->b.t_x > nx.x2)
				{
					mlx_pixel_put(e->w.mp, e->w.wp, e->b.t_x--, e->b.t_y, 0xFFFFFF);
					if ((er = er + copy_dy) >= 0)
					{
						e->b.t_y += inc_y;
						er += copy_dx;
					}
				}
			}
			else // 3e octant // e est positif
			{
				while (e->b.t_y < nx.y2)
				{
					mlx_pixel_put(e->w.mp, e->w.wp, e->b.t_x, e->b.t_y++, 0xFFFFFF);
					if ((er = er + copy_dx) <= 0)
					{
						e->b.t_x += inc_x;
						er += copy_dy;
					}
				}
			}
		}
		else // 3e cadran
		{
			er = ((copy_dx * inc_x) <= copy_dy ? copy_dx : copy_dy);
			copy_dx = (er == copy_dx ? er * 2 : copy_dx * 2);
			copy_dy = (er == copy_dy ? er * 2 : copy_dy * 2);
			if (copy_dx <= copy_dy) // e est négatif
			{
				while (e->b.t_x > nx.x2)
				{
					mlx_pixel_put(e->w.mp, e->w.wp, e->b.t_x--, e->b.t_y, 0xFFFFFF);
					if ((er = er - copy_dy) >= 0)
					{
						e->b.t_y += inc_y;
						er += copy_dx;
					}
				}		
			}
			else // 6e octant // e est négatif
			{
				while (e->b.t_y > nx.y2)
				{
					mlx_pixel_put(e->w.mp, e->w.wp, e->b.t_x, e->b.t_y--, 0xFFFFFF);
					if ((er = er - copy_dx) >= 0)
					{
						e->b.t_x += inc_x;
						er += copy_dy;
					}
				}
			}
		}
	}
}

void	parse_lines(t_cor co, t_cor nx, t_env *e)
{
	e->b.t_x = co.x2;
	e->b.t_y = co.y2;
	int copy_dy = nx.y2 - co.y2;
	int copy_dx = nx.x2 - co.x2;

	if ((nx.x2 - co.x2) != 0)
	{
		if (copy_dy == 0 && copy_dx > 0)
			while (e->b.t_x < nx.x2)
				mlx_pixel_put(e->w.mp, e->w.wp, e->b.t_x++, e->b.t_y, 0xFFFFFF);
		else if (copy_dy == 0 && copy_dx < 0)
			while (e->b.t_x > nx.x2)
				mlx_pixel_put(e->w.mp, e->w.wp, e->b.t_x--, e->b.t_y, 0xFFFFFF);
		else
			lines(co, nx, e);
	}
	else if ((nx.x2 - co.x2) == 0)
	{
		if (copy_dy > 0)
			while (e->b.t_y < nx.y2)
				mlx_pixel_put(e->w.mp, e->w.wp, e->b.t_x, e->b.t_y++, 0xFFFFFF);
		else if (copy_dy < 0)
			while (e->b.t_y > nx.y2)
				mlx_pixel_put(e->w.mp, e->w.wp, e->b.t_x, e->b.t_y--, 0xFFFFFF);
	}	
}

void	draw_me(t_env *e)
{
	int		x;
	int		y;
 
 	y = -1;
	while (++y < e->pla.ly)
	{
		x = -1;
		while (++x < e->pla.lx)
		{
			if (x + 1 < e->pla.lx)
				parse_lines(e->co[y][x], e->co[y][x + 1], e);
			if (y + 1 < e->pla.ly)
				parse_lines(e->co[y][x], e->co[y + 1][x], e);

		}
	}
}