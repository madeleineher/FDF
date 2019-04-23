/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 09:41:31 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/23 19:13:32 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_cor	*minico(t_ll *link, t_cor *mi, t_env *e, int sz)
{
	int		i;

	i = 0;
	mi = NULL;
	if (!(mi = (t_cor*)malloc(sizeof(t_cor) * e->pla.lx)))
		return (NULL);
	while (link->content[i])
	{
		printf("%s ", link->content[i]);
		mi[i].x1 = i;
		mi[i].y1 = sz;
		mi[i].z = ft_atoi(link->content[i]);
		mi[i].x2 = (e->pla.px + i * e->spa) + e->prx;
		mi[i].y2 = (e->pla.py + sz * e->spa) + e->pry;
		i++;
	}
	return (mi);
}

int		points(t_env *e)
{
	t_ll	*tp;
	int		sz = 0;

	tp = NULL;
	e->co = NULL;
	tp = e->lines;
	if (!(e->co = (t_cor**)malloc(sizeof(t_cor*) * e->pla.ly)))
		return (0);
	while (tp)
	{
		e->co[sz] = minico(tp, e->co[sz], e, sz);
		if (!(e->co[sz]))
			return (0);
		tp = tp->next;
		printf("\n");
		sz++;
	}
	delevr(e);
	return (1);
}
