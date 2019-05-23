/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deltab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 10:17:43 by mhernand          #+#    #+#             */
/*   Updated: 2019/05/10 17:19:14 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	delproj(t_env *e)
{
	int		y;

	y = -1;
	while (++y < e->pl.ly)
	{
		free(e->co[y]);
		e->co[y] = NULL;
	}
	free(e->co);
	e->co = NULL;
	mlx_destroy_image(e->w.mp, e->i.ig);
	mlx_destroy_window(e->w.mp, e->w.wp);
	exit(0);
}

void	delevr(t_env *e, int w)
{
	t_ll	*tmp;
	t_ll	*tmp2;

	if (w == 2)
		delproj(e);
	else
	{
		tmp = e->lines;
		while (tmp)
		{
			ft_delsplit(tmp->content);
			tmp->content = NULL;
			tmp2 = tmp;
			tmp = tmp->next;
			if (tmp2)
			{
				free(tmp2);
				tmp2 = NULL;
			}
		}
		tmp = NULL;
	}
}
