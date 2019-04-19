/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:35:31 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/16 15:20:50 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void		texting(t_env *ev)
{
	mlx_string_put(ev->win.m_p, ev->win.w_p, 30, 20, 0xFFFFFF, "~ COMMANDS ~");
	mlx_string_put(ev->win.m_p, ev->win.w_p, 
			ev->win.wx - 150, ev->win.wy - 60, 0xFFFFFF, "EXIT : ESC");
	mlx_string_put(ev->win.m_p, ev->win.w_p, 30, 40, 0xFFFFFF, "PROJECTIONS");
	mlx_string_put(ev->win.m_p, ev->win.w_p, 50, 55, 0xFFFFFF, "ISOMETRIC : 3");
	mlx_string_put(ev->win.m_p, ev->win.w_p, 50, 70, 0xFFFFFF, "PARALLEL : 1");
	mlx_string_put(ev->win.m_p, ev->win.w_p, 30, 90, 0xFFFFFF, "DIRECTIONS");
	mlx_string_put(ev->win.m_p, ev->win.w_p, 50, 105, 0xFFFFFF, "UP : 8");
	mlx_string_put(ev->win.m_p, ev->win.w_p, 50, 120, 0xFFFFFF, "DOWN : 2");
	mlx_string_put(ev->win.m_p, ev->win.w_p, 50, 135, 0xFFFFFF, "LEFT : 4");
	mlx_string_put(ev->win.m_p, ev->win.w_p, 50, 150, 0xFFFFFF, "RIGHT : 6");
	mlx_string_put(ev->win.m_p, ev->win.w_p, 
			30, 170, 0xFFFFFF, "MAGNIFICATION");
	mlx_string_put(ev->win.m_p, ev->win.w_p, 50, 185, 0xFFFFFF, "ZOOM IN : 7");
	mlx_string_put(ev->win.m_p, ev->win.w_p, 50, 200, 0xFFFFFF, "ZOOM OUT : 9");
}
