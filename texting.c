/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:35:31 by mhernand          #+#    #+#             */
/*   Updated: 2019/05/10 17:26:31 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void		texting(t_env *e)
{
	mlx_string_put(e->w.mp, e->w.wp, 30, 20, 0xFFFFFF, "~ COMMANDS ~");
	mlx_string_put(e->w.mp, e->w.wp,
			e->w.wx - 150, e->w.wy - 60, 0xFFFFFF, "EXIT : ESC");
	mlx_string_put(e->w.mp, e->w.wp, 30, 40, 0xFFFFFF, "PROJECTIONS");
	mlx_string_put(e->w.mp, e->w.wp, 50, 55, 0xFFFFFF, "ISOMETRIC : 2");
	mlx_string_put(e->w.mp, e->w.wp, 50, 70, 0xFFFFFF, "PARALLEL : 1");
	mlx_string_put(e->w.mp, e->w.wp, 30, 90, 0xFFFFFF, "DIRECTIONS");
	mlx_string_put(e->w.mp, e->w.wp, 50, 105, 0xFFFFFF, "UP : A");
	mlx_string_put(e->w.mp, e->w.wp, 50, 120, 0xFFFFFF, "DOWN : S");
	mlx_string_put(e->w.mp, e->w.wp, 50, 135, 0xFFFFFF, "LEFT : A");
	mlx_string_put(e->w.mp, e->w.wp, 50, 150, 0xFFFFFF, "RIGHT : D");
	mlx_string_put(e->w.mp, e->w.wp, 30, 170, 0xFFFFFF, "MAGNIFICATION");
	mlx_string_put(e->w.mp, e->w.wp, 50, 185, 0xFFFFFF, "ZOOM IN : M");
	mlx_string_put(e->w.mp, e->w.wp, 50, 200, 0xFFFFFF, "ZOOM OUT : L");
}
