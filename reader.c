/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 11:50:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/04/19 19:04:32 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int			check_chars(char *line)
{
	int		i;

	i = -1;
	while (line[++i] != 0)
		if (ft_only_fdf(line[i]) == 0)
			return (-1);
	return (0);
}

int			add_links(char **lin, t_ll **head)
{
	t_ll	*last;
	t_ll	*new_link;

	last = *head;
	new_link = NULL;
	if (!(new_link = (t_ll*)malloc(sizeof(t_ll))))
		return (0); // needs to be changed to NULL
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

int			vertical_check(t_ll *head, t_env *ev)
{
	int		len;
	int 	i;

	len = -1;
	while (head->content[++len] != NULL)
		;
	ev->pla.lx = len;
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

int			reader(int fd, t_env *ev)
{
	t_ll	*head;

	head = NULL;
	while ((ev->ret = get_next_line(fd, &ev->line)) > 0)
	{
		if ((check_chars(ev->line)) == -1)
			return (5);
		ev->lin = ft_strsplit(ev->line, ' ');
		add_links(ev->lin, &head);
		free(ev->line);
		ev->line = NULL;
		ev->pla.ly++;
	}
	if (ev->ret == -1)
		return (3);
	if (vertical_check(head, ev) == -1)
		return (4);
	ev->lines = head;
	return (0);
}
