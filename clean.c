/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:08:44 by mhernand          #+#    #+#             */
/*   Updated: 2019/05/15 17:08:45 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	clear(t_env *e)
{
	int		i;
	int		j;

	j = -1;
	e->c = 0x000000;
	while (++j < 1224)
	{
		i = -1;
		while (++i < 1632)
			*(int *)&e->i.dt[i * (e->i.bp / 8) + j * e->i.sl] = e->c;
	}
}

void	clean(t_env *e)
{
	clear(e);
	draw_lines(e);
	mlx_put_image_to_window(e->w.mp, e->w.wp, e->i.ig, 0, 0);
	texting(e);
	projection(e);
}
