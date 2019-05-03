/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:54:59 by mhernand          #+#    #+#             */
/*   Updated: 2019/05/03 18:42:46 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	lines(t_cor co, t_cor nx, t_env *e)
{
	int	er;
	int	t_x = co.x2;
	int	t_y = co.y2;
	e->be.dx = abs(nx.x2 - co.x2);
	e->be.dy = abs(nx.y2 - co.y2);
	e->be.tdx = 2 * e->be.dx;
	e->be.tdy = 2 * e->be.dy;

	if (e->be.dx != 0)
	{
		if (e->be.dx > 0)
		{
			if (e->be.dy > 0)	
			{
				if (e->be.dx >= e->be.dy) // 1st octant
				{
					er = e->be.dx;
					e->be.dx = er * 2 ;
					e->be.dy = e->be.dy * 2 ; // e est positif
					while (t_x++ < nx.x2)  // déplacements horizontaux
					{
						mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFFFFFF);
						if ((er = er - e->be.dy) < 0)
						{
							t_y += 1 ;  // déplacement diagonal
							er += e->be.dx;
						}
					}
				}
				else // 2nd octant
				{
					er = e->be.dy;
					e->be.dy = er * 2 ; 
					e->be.dx = e->be.dx * 2 ;  // e est positif
					while (t_y++ < nx.y2) // déplacements verticaux
					{
						mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFFFFFF);
						if ((er = er - e->be.dx) < 0)
						{
							t_x += 1; // déplacement diagonal
							er += e->be.dy;
						}
					}
				}
			}
			else if (e->be.dy < 0) // (e->be.dy < 0) && e->be.dx > 0 // 4th cadran
			{
				if (e->be.dx >= -e->be.dy) // vecteur diagonal ou oblique proche de l’horizontale, 8e octant
				{
					er = e->be.dx;
					e->be.dx = er * 2;
					e->be.dy = e->be.dy * 2 ;  // e est positif
					while (t_x-- > nx.x2)  // déplacements horizontaux
					{
						mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFF0000);
						if ((er = er + e->be.dy) < 0)
						{
							t_y -= 1 ;  // déplacement diagonal
							er += e->be.dx ;
						}	
					}
				}
				else // 7th octant
				{
					er = -e->be.dy;
					e->be.dy = er * 2 ; 
					e->be.dx = e->be.dx * 2 ;  // e est négatif
					while (t_y-- > nx.y2)  // déplacements verticaux
					{
						mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFFFFFF);
						if ((er = er + e->be.dx) > 0)
						{
							t_x += 1;  // déplacement diagonal
							er += e->be.dy;
						}
					}
				}
			}
			else if (e->be.dy == 0 && e->be.dx > 0)// dy = 0 and dx > 0 // vertical towards the right
			{
				while (t_x++ < nx.x2) // jusqu’à ce que (x1 ← x1 + 1) = x
					mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFFFFFF);
			}
		}
		else if (e->be.dx < 0)
		{
			if (e->be.dy != 0)
			{
				if (e->be.dy > 0) // 2eme quadran
				{
					if (-e->be.dx >= e->be.dy) // vecteur diagonal ou oblique proche de l’horizontale, dans le 4e octant
					{
						er = -e->be.dx;
						e->be.dx = er * 2 ; 
						e->be.dy = e->be.dy * 2 ;  // e est négatif
						while (t_x++ < nx.x2)  // déplacements horizontaux
						{
							mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFFFFFF);
							if ((er = er + e->be.dy) >= 0)
							{
								t_y += 1 ;  // déplacement diagonal
								er += e->be.dx;
							}
						}
					}
					else // if vecteur oblique proche de la verticale, dans le 3e octant
					{
						er = e->be.dy;
						e->be.dy = er * 2; 
						e->be.dx = e->be.dx * 2;  // e est positif
						while (t_y++ < nx.y2) // déplacements verticaux
						{
							mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFFFFFF);
							if ((er = er + e->be.dx) <= 0)
							{
								t_x -= 1; // déplacement diagonal
								er += e->be.dy;
							}
						}
					}
				}
				else // dy < 0 (et dx < 0) // vecteur oblique dans le 3e cadran
				{
					if (e->be.dx <= e->be.dy)
					{
						er = -e->be.dx;
						e->be.dx = er * 2 ; 
						e->be.dy = e->be.dy * 2 ;  // e est négatif
						while (t_x-- > nx.x2) // déplacements horizontaux
						{
							mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFFFFFF);
							if ((er = er - e->be.dy) >= 0)
							{
								t_y -= 1;  // déplacement diagonal
								er += e->be.dx;
							}
						}		
					}
					else // vecteur oblique proche de la verticale, dans le 6e octant
					{
						er = -e->be.dy;
						e->be.dy = er * 2 ; 
						e->be.dx = e->be.dx * 2 ;  // e est négatif
						while (t_y++ > nx.y2)  // déplacements verticaux
						{
							mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFFFFFF);
							if ((er = er - e->be.dx) >= 0)
							{
								t_x -= 1;  // déplacement diagonal
								er += e->be.dy;
							}
						}
					}
				}
			}
			else if (e->be.dy == 0 && e->be.dx < 0)
			{
				while (t_x-- > nx.x2) //jusqu’à ce que (x1 ← x1 - 1) = x2; 
					mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFFFFFF);
			}
		}
	}
	else if (e->be.dx == 0)
	{
		if (e->be.dy != 0)
		{
			if (e->be.dy > 0)
				while (t_y++ < nx.y2)
					mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFFFFFF);
			else if (e->be.dy < 0)
				while (t_y-- > nx.y2)
					mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFFFFFF);
		}
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
				lines(e->co[y][x], e->co[y][x + 1], e);
			if (y + 1 < e->pla.ly)
				lines(e->co[y][x], e->co[y + 1][x], e);

		}
	}
}
