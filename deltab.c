/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deltab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 10:17:43 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/23 17:42:48 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	delevr(t_env *ev)
{
	t_ll	*tmp;
	t_ll	*tmp2;

	tmp = ev->lines;
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
