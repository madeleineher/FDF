/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 09:41:31 by mhernand          #+#    #+#             */
/*   Updated: 2020/01/21 16:08:59 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_cor	*minico(t_ll *link, t_cor *mi, t_env *e, int y)
{
	int		x;

	x = 0;
	mi = NULL;
	if (!(mi = (t_cor*)malloc(sizeof(t_cor) * e->pl.lx)))
		return (NULL);
	while (link->content[x])
	{
		mi[x].x1 = x;
		mi[x].y1 = y;
		mi[x].z = ft_atoi(link->content[x]);
		if (mi[x].z >= 5000000)
			mi[x].z = 500;
		if (mi[x].z <= -5000000)
			mi[x].z = -500;
		mi[x].x2 = (e->pl.px + x * e->spax) + e->mx;
		mi[x].y2 = (e->pl.py + y * e->spay) + e->my
			- (mi[x].z * e->hi);
		e->d_max = (e->d_max > mi[x].z ? e->d_max : mi[x].z);
		e->d_min = (e->d_min > mi[x].z ? mi[x].z : e->d_min);
		x++;
	}
	return (mi);
}

int		points(t_env *e)
{
	t_ll	*tp;
	int		y;

	y = 0;
	tp = NULL;
	e->co = NULL;
	tp = e->lines;
	if (!(e->co = (t_cor**)malloc(sizeof(t_cor*) * e->pl.ly)))
		return (0);
	while (tp)
	{
		e->co[y] = minico(tp, e->co[y], e, y);
		if (!(e->co[y]))
			return (0);
		tp = tp->next;
		y++;
	}
	delevr(e, 1);
	return (1);
}
