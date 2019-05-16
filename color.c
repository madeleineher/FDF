/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:10:17 by mhernand          #+#    #+#             */
/*   Updated: 2019/05/16 14:10:19 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		gradient(t_cor nx, t_env *e)
{
	if (nx.z <= 0)
		e->c = WATER;
	else if (nx.z > 0 && nx.z < 10)
		e->c = SAND;
	else if (nx.z >= 10 && nx.z < 20)
		e->c = GRASS;
	else if (nx.z >= 20 && nx.z < 70)
		e->c = ROCK;
	else if (nx.z >= 70)
		e->c = SNOW;
	return (e->c);
}

int		color_me(t_cor co, t_cor nx, t_env *e, int w)
{
	if (w == 1)
	{
		if (co.z <= 0)
			e->c = WATER;
		else if (co.z > 0 && co.z < 10)
			e->c = SAND;
		else if (co.z >= 10 && co.z < 20)
			e->c = GRASS;
		else if (co.z >= 20 && co.z < 70)
			e->c = ROCK;
		else if (co.z >= 70)
			e->c = SNOW;
	}
	else if (w == 2)
		e->c = gradient(nx, e);
	return (e->c);
}
