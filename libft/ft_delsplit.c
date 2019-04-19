/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:01:43 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/19 20:06:43 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_delsplit(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
}
