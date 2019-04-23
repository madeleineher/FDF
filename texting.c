/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:35:31 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/23 19:09:51 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void		texting(t_env *e)
{
	mlx_string_put(e->w.m_p, e->w.w_p, 30, 20, 0xFFFFFF, "~ COMMANDS ~");
	mlx_string_put(e->w.m_p, e->w.w_p, 
			e->w.wx - 150, e->w.wy - 60, 0xFFFFFF, "EXIT : ESC");
	mlx_string_put(e->w.m_p, e->w.w_p, 30, 40, 0xFFFFFF, "PROJECTIONS");
	mlx_string_put(e->w.m_p, e->w.w_p, 50, 55, 0xFFFFFF, "ISOMETRIC : I");
	mlx_string_put(e->w.m_p, e->w.w_p, 50, 70, 0xFFFFFF, "PARALLEL : O");
	mlx_string_put(e->w.m_p, e->w.w_p, 30, 90, 0xFFFFFF, "DIRECTIONS");
	mlx_string_put(e->w.m_p, e->w.w_p, 50, 105, 0xFFFFFF, "UP : A");
	mlx_string_put(e->w.m_p, e->w.w_p, 50, 120, 0xFFFFFF, "DOWN : S");
	mlx_string_put(e->w.m_p, e->w.w_p, 50, 135, 0xFFFFFF, "LEFT : A");
	mlx_string_put(e->w.m_p, e->w.w_p, 50, 150, 0xFFFFFF, "RIGHT : D");
	mlx_string_put(e->w.m_p, e->w.w_p, 30, 170, 0xFFFFFF, "MAGNIFICATION");
	mlx_string_put(e->w.m_p, e->w.w_p, 50, 185, 0xFFFFFF, "ZOOM IN : M");
	mlx_string_put(e->w.m_p, e->w.w_p, 50, 200, 0xFFFFFF, "ZOOM OUT : L");
}
