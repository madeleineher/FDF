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
	if ((float)nx.z >= e->d_min && (float)nx.z <= 0)
		e->c = WATER;
	else if (((float)nx.z > e->d_min || (float)nx.z > 0)
		&& (float)nx.z <= e->d_max / 7)
		e->c = SAND;
	else if ((float)nx.z > e->d_max / 7 && (float)nx.z < e->d_max / 4)
		e->c = GRASS;
	else if ((float)nx.z >= e->d_max / 4 && (float)nx.z < e->d_max / 1.5)
		e->c = ROCK;
	else if ((float)nx.z >= e->d_max / 1.5)
		e->c = SNOW;
	return (e->c);
}

int		color_me(t_cor co, t_cor nx, t_env *e, int w)
{
	if (w == 1)
	{
		if (co.z >= e->d_min && co.z <= 0)
			e->c = WATER;
		else if (((float)co.z > 0 || (float)co.z > e->d_min)
			&& (float)co.z <= e->d_max / 8)
			e->c = SAND;
		else if ((float)co.z > e->d_max / 8 && (float)co.z < e->d_max / 4)
			e->c = GRASS;
		else if ((float)co.z >= e->d_max / 4 && (float)co.z < e->d_max / 1.5)
			e->c = ROCK;
		else if ((float)co.z >= e->d_max / 1.5)
			e->c = SNOW;
	}
	else if (w == 2)
		e->c = gradient(nx, e);
	return (e->c);
}
