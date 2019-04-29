/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 09:41:31 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/29 18:11:28 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_cor	*minico(t_ll *link, t_cor *mi, t_env *e, int y)
{
	int		x;

	x = 0;
	mi = NULL;
	if (!(mi = (t_cor*)malloc(sizeof(t_cor) * e->pla.lx)))
		return (NULL);
	while (link->content[x])
	{
		printf("%s ", link->content[x]);
		mi[x].x1 = x;
		mi[x].y1 = y;
		mi[x].z = ft_atoi(link->content[x]);
		mi[x].x2 = (e->pla.px + x * e->spax) + e->ml + e->mx + e->my; //+ e->rl + e->rr;
		mi[x].y2 = (e->pla.py + y * e->spay) + e->ml + e->mx + e->my; // + e->rl + e->rr;
		if (mi[x].z > 0 && mi[x].z != 0)
			mi[x].y2 += (mi[x].z * 20);
		else if (mi[x].z < 0 && mi[x].z != 0)
			mi[x].y2 -= (mi[x].z * 20);
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
	if (!(e->co = (t_cor**)malloc(sizeof(t_cor*) * e->pla.ly)))
		return (0);
	while (tp)
	{
		e->co[y] = minico(tp, e->co[y], e, y);
		if (!(e->co[y]))
			return (0);
		tp = tp->next;
		printf("\n");
		y++;
	}
	delevr(e, 1);
	return (1);
}
