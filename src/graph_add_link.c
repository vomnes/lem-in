/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_add_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 13:27:32 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/19 14:01:54 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int link_exist(t_link *list_link, char *name)
{
	t_room *room_selected;

	while(list_link != NULL)
	{
		room_selected = list_link->link_room;
		if (ft_strcmp(room_selected->name, name) == 0)
		 	return (-1);
		list_link = list_link->next;
	}
	return (0);
}

static int	push_link(t_room *rooms, t_link **lst_head, char *link_name)
{
	t_link	*new_node;
	t_room *tmp_room;

	new_node = *lst_head;
	tmp_room = rooms;
	if (link_exist(*lst_head, link_name) == -1)
		return (0);
	if(*lst_head == NULL)
	{
		if (!(*lst_head = (t_link*)malloc(sizeof(t_link))))
			return(-1);
		while (ft_strcmp(tmp_room->name, link_name) != 0 && tmp_room != NULL)
			tmp_room = tmp_room->next;
		(*lst_head)->link_room = tmp_room;
		if (!((*lst_head)->name = ft_strdup(link_name)))
			return (-1);
		(*lst_head)->next = NULL;
	}
	else
	{
		while (new_node->next != NULL)
			new_node = new_node->next;
		if (!(new_node->next = (t_link*)malloc(sizeof(t_link))))
			return(-1);
		while (ft_strcmp(tmp_room->name, link_name) != 0 && tmp_room != NULL)
			tmp_room = tmp_room->next;
		new_node->next->link_room = tmp_room;
		if (!(new_node->next->name = ft_strdup(link_name)))
			return (-1);
		new_node->next->next = NULL;
	}
	return (1);
}

int graph_add_link(char *selected_room, char *room, t_room **list_room)
{
	t_room	*tmp;
	t_room	*tmp_initial;

	tmp = *list_room;
	tmp_initial = *list_room;
	while (ft_strcmp(tmp->name, selected_room) != 0 && tmp != NULL)
		tmp = tmp->next;
	if (push_link(tmp_initial, &(tmp->link), room) == -1)
		return (-1);
	return (0);
}
