/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 11:50:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/05/10 17:26:06 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int			check_chars(char *line)
{
	int		i;

	i = -1;
	while (line[++i] != 0)
	{
		if (line[i] == ',' || line[i] == '-' || line[i] == 'F' || line[i] == 'X'
				|| line[i] == 'x' || line[i] == 'f' || line[i] == ' '
				|| line[i] == '\n' || (line[i] > 47 && line[i] < 58)
				|| line[i] == 'a' || line[i] == 'b' || line[i] == 'c')
			return (1);
		else
			return (-1);
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
		return (0);// needs to be changed to NULL
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
	while (head->content[++len] != NULL)
		;
	e->pla.lx = len;
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
		if ((check_chars(e->line)) == -1)
			return (5);
		e->lin = ft_strsplit(e->line, ' ');
		add_links(e->lin, &head);
		if (e->line)
		{
			free(e->line);
			e->line = NULL;
		}
		e->pla.ly++;
	}
	if (e->ret == -1)
		return (3);
	if (vertical_check(head, e) == -1)
		return (4);
	e->lines = head;
	return (0);
}
