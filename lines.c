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
	int	t_x = co.x2;
	int	t_y = co.y2;
	e->be.dx = abs(nx.x2 - co.x2);
	e->be.dy = abs(nx.y2 - co.y2);
	int copy_dx = nx.x2 - co.x2;
	int copy_dy = nx.y2 - co.y2;
	e->be.tdx = 2 * e->be.dx;
	e->be.tdy = 2 * e->be.dy;


	if (e->be.dx != 0)
	{
		if (copy_dx > 0)
		{
			if (copy_dy != 0)
			{
				if (copy_dy > 0) // 1ere cadran	
				{
					if (copy_dx >= copy_dy) // 1st octant
					{
						er = copy_dx;
						copy_dx = er * 2 ;
						copy_dy = copy_dy * 2 ; // e est positif
						while (t_x++ < nx.x2)  // déplacements horizontaux
						{
							mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFFFFFF);
							if ((er = er - copy_dy) < 0)
							{
								t_y += 1 ;  // déplacement diagonal
								er += copy_dx;
							}
						}
					}
					else // 2nd octant
					{
						er = copy_dy;
						copy_dy = er * 2 ; 
						copy_dx = copy_dx * 2 ;  // e est positif
						while (t_y++ < nx.y2) // déplacements verticaux
						{
							mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFFFFFF);
							if ((er = er - copy_dx) < 0)
							{
								t_x += 1; // déplacement diagonal
								er += copy_dy;
							}
						}
					}
				}
				else if (copy_dy < 0)// 4th cadran
				{
					if (copy_dx >= (copy_dy * -1)) // vecteur diagonal ou oblique proche de l’horizontale, 8e octant
					{
						er = copy_dx;
						copy_dx = er * 2;
						copy_dy = copy_dy * 2 ;  // e est positif
						while (t_x++ < nx.x2) // déplacements horizontaux
						{
							mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFFFFFF);
							er = er + copy_dy; 
							if (er < 0)
							{
								t_y -= 1 ;  // déplacement diagonal
								er += copy_dx;
							}	
						}
					}
					else 
					{
					//	printf("abs dx : [%d]\nabs dy : [%d]\ndx : [%d]\ndy : [%d]\n\n", e->be.dx, e->be.dy, copy_dx, copy_dy);
						er = copy_dy;
						copy_dy = er * 2 ; 
						copy_dx = copy_dx * 2 ;  // e est négatif
						while (t_y-- > nx.y2)  // déplacements verticaux
						{
							mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFFFFFF);
							er = er + copy_dx;
							if (er > 0)
							{
								t_x += 1;  // déplacement diagonal
								er += copy_dy;
							}
						}
					}
				}
			}
			else if (copy_dy == 0 && copy_dx > 0)// dy = 0 and dx > 0 // vertical towards the right
			{
				while (t_x < nx.x2) // jusqu’à ce que (x1 ← x1 + 1) = x
				{
					mlx_pixel_put(e->w.mp, e->w.wp, t_x++, t_y, 0xFFFFFF);
				}
			}
		}
		else if (copy_dx < 0)
		{
			if (copy_dy != 0)
			{
				if (copy_dy > 0) // 2eme quadran
				{
					if ((copy_dx * -1) >= copy_dy) // vecteur diagonal ou oblique proche de l’horizontale, dans le 4e octant
					{
						er = copy_dx;
						copy_dx = er * 2 ; 
						copy_dy = copy_dy * 2 ;  // e est négatif
						while (t_x-- > nx.x2)  // déplacements horizontaux
						{
							mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFFFFFF);
							er = er + copy_dy;
							if (er >= 0)
							{
								t_y += 1;  // déplacement diagonal
								er += copy_dx;
							}
						}
					}
					else // if vecteur oblique proche de la verticale, dans le 3e octant
					{
						er = copy_dy;
						copy_dy = er * 2; 
						copy_dx = copy_dx * 2;  // e est positif
						while (t_y++ < nx.y2) // déplacements verticaux
						{
							mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFFFFFF);
							er = er + copy_dx;
							if (er <= 0)
							{
								t_x -= 1; // déplacement diagonal
								er += copy_dy;
							}
						}
					}
				}
				else // dy < 0 (et dx < 0) // vecteur oblique dans le 3e cadran
				{
					if (copy_dx <= copy_dy)
					{
						er = copy_dx;
						copy_dx = er * 2 ; 
						copy_dy = copy_dy * 2 ;  // e est négatif
						while (t_x-- > nx.x2) // déplacements horizontaux
						{
							mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFFFFFF);
							er = er - copy_dy;
							if (er >= 0)
							{
								t_y -= 1;  // déplacement diagonal
								er += copy_dx;
							}
						}		
					}
					else // vecteur oblique proche de la verticale, dans le 6e octant
					{
						er = copy_dy;
						copy_dy = er * 2; 
						copy_dx = copy_dx * 2;  // e est négatif
						while (t_y-- > nx.y2)  // déplacements verticaux
						{
							mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y, 0xFFFFFF);
							er = er - copy_dx;
							if (er >= 0)
							{
								t_x -= 1;  // déplacement diagonal
								er += copy_dy;
							}
						}
					}
				}
			}
			else if (copy_dy == 0)
				while (t_x > nx.x2) //jusqu’à ce que (x1 ← x1 - 1) = x2; 
					mlx_pixel_put(e->w.mp, e->w.wp, t_x--, t_y, 0xFFFFFF);
		}
	}
	else if (e->be.dx == 0)
	{
		if (copy_dy > 0)
			while (t_y < nx.y2)
				mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y++, 0xFFFFFF);
		else if (copy_dy < 0)
			while (t_y > nx.y2)
				mlx_pixel_put(e->w.mp, e->w.wp, t_x, t_y--, 0xFFFFFF);
	}
}

void	draw_me(t_env *e)
{

	t_cor	tmp_start = {0, 0, e->pla.hx, e->pla.hy, 0};

	t_cor	tmp_1_8 = {0, 0, 1632, 612, 0};
	t_cor	tmp_6_7 = {0, 0, 816, 0, 0};
	t_cor	tmp_5_4 = {0, 0, 0, 612, 0};
	t_cor	tmp_3_2 = {0, 0, 816, 1224, 0};

	t_cor	tmp_7_8 = {0, 0, 1632, 0, 0};
	t_cor	tmp_1_2 = {0, 0, 1632, 1224, 0};
	t_cor	tmp_4_3 = {0, 0, 0, 1224, 0};
	t_cor	tmp_5_6 = {0, 0, 0, 0, 0};

	t_cor	tmp_8 = {0, 0, 1632, 332, 0};
	t_cor	tmp_1 = {0, 0, 1632, 652, 0};

	t_cor	tmp_2 = {0, 0, 836, 1224, 0};
	t_cor	tmp_3 = {0, 0, 700, 1224, 0};

	t_cor	tmp_4 = {0, 0, 6, 652, 0};
	t_cor	tmp_5 = {0, 0, 0, 590, 0};

	t_cor	tmp_6 = {0, 0, 796, 0, 0};
	t_cor	tmp_7 = {0, 0, 826, 0, 0};

	printf("hx : [%d] -- hy : [%d]\n", e->pla.hx, e->pla.hy);
	//horizontal && vertical
	lines(tmp_start, tmp_1_8, e);
	lines(tmp_start, tmp_6_7, e);
	lines(tmp_start, tmp_5_4, e);
	lines(tmp_start, tmp_3_2, e);

	//diagonal
	lines(tmp_start, tmp_7_8, e);
	lines(tmp_start, tmp_1_2, e);
	lines(tmp_start, tmp_4_3, e);
	lines(tmp_start, tmp_5_6, e);

	printf("\n\n--------------------------------------------------------------------------------\n\n");

	lines(tmp_start, tmp_1, e);
	lines(tmp_start, tmp_2, e);

	lines(tmp_start, tmp_3, e);
	lines(tmp_start, tmp_4, e);

	lines(tmp_start, tmp_5, e);
	lines(tmp_start, tmp_6, e);

	lines(tmp_start, tmp_7, e); // DOES NOT WORK !
	lines(tmp_start, tmp_8, e);

/*	
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
	*/
}
