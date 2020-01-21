/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 11:50:20 by mhernand          #+#    #+#             */
/*   Updated: 2020/01/21 16:09:19 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			check_chars(char **line)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (line[++i] != 0)
	{
		if (line[i][j] == '-')
			j++;
		if ((line[i][j]) < 48 || (line[i][j]) > 57)
			return (-1);
		else
		{
			while (line[i][j])
			{
				if (line[i][j] == ',')
					break ;
				if (line[i][j] < 48 || line[i][j] > 57)
					return (-1);
				j++;
			}
			j = 0;
		}
	}
	return (0);
}

int			add_links(char **lin, t_ll **head)
{
	t_ll	*last;
	t_ll	*new_link;

	last = *head;
	new_link = NULL;
	if (!(new_link = (t_ll*)malloc(sizeof(t_ll))))
		return (-1);
	new_link->content = lin;
	new_link->next = NULL;
	if (*head == NULL)
		*head = new_link;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new_link;
	}
	return (0);
}

int			vertical_check(t_ll *head, t_env *e)
{
	int		len;
	int		i;

	len = -1;
	if (head == NULL)
		return (-1);
	while (head->content[++len] != NULL)
		;
	e->pl.lx = len;
	while (head)
	{
		i = -1;
		while (head->content[++i])
			;
		if (i != len)
			return (-1);
		head = head->next;
	}
	return (0);
}

int			reader(int fd, t_env *e)
{
	t_ll	*head;

	head = NULL;
	e->line = NULL;
	while ((e->ret = get_next_line(fd, &e->line)) > 0)
	{
		e->lin = ft_strsplit(e->line, ' ');
		if ((check_chars(e->lin)) == -1)
			return (5);
		if ((add_links(e->lin, &head)) == -1)
			return (7);
		if (e->line)
		{
			free(e->line);
			e->line = NULL;
		}
		e->pl.ly++;
	}
	if (e->ret == -1)
		return (3);
	if (vertical_check(head, e) == -1)
		return (4);
	e->lines = head;
	return (0);
}
