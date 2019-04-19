/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 09:41:31 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/19 20:02:07 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_cor	*minico(t_ll *link, t_cor *mi, t_env *ev, int sz)
{
	int		i;

	i = 0;
	mi = NULL;
	if (!(mi = (t_cor*)malloc(sizeof(t_cor) * ev->pla.lx)))
		return (NULL);
	while (link->content[i])
	{
		printf("%s ", link->content[i]);
		mi[i].x1 = i;
		mi[i].y1 = sz;
		mi[i].z = ft_atoi(link->content[i]);
		mi[i].x2 = (ev->pla.px + i * ev->spa) + ev->prx;
		mi[i].y2 = (ev->pla.py + sz * ev->spa) + ev->pry;
		i++;
	}
	return (mi);
}

int		points(t_env *ev)
{
	t_ll	*tp;
	int		sz = 0;

	tp = NULL;
	ev->co = NULL;
	tp = ev->lines;
	if (!(ev->co = (t_cor**)malloc(sizeof(t_cor*) * ev->pla.ly)))
		return (0);
	while (tp)
	{
		ev->co[sz] = minico(tp, ev->co[sz], ev, sz);
		if (!(ev->co[sz]))
			return (0);
		tp = tp->next;
		printf("\n");
		sz++;
	}
	delevr(ev);
	return (1);
}
