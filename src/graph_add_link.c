/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_add_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 13:27:32 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/29 17:31:10 by vomnes           ###   ########.fr       */
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

static t_link *add_one_link(char *link_name, t_room *tmp_room)
{
	t_link *new_node;
	t_room *tmp;

	new_node = NULL;
	tmp = tmp_room;
	if (!(new_node = (t_link*)malloc(sizeof(t_link))))
		return(NULL);
	while (tmp != NULL && ft_strcmp(tmp->name, link_name) != 0)
		tmp = tmp->next;
	new_node->link_room = tmp;
	if (!(new_node->name = ft_strdup(link_name)))
		return (NULL);
	new_node->visited = 0;
	new_node->next = NULL;
	return (new_node);
}

static int	push_link(t_room *rooms, t_link **list_link, char *link_name)
{
	t_link	*new_node;
	t_room *tmp_room;

	new_node = *list_link;
	tmp_room = rooms;
	if (link_exist(*list_link, link_name) == -1)
		return (0);
	if(*list_link == NULL)
	{
		if (!(*list_link = add_one_link(link_name, tmp_room)))
			return (-1);
	}
	else
	{
		while (new_node->next != NULL)
			new_node = new_node->next;
		if (!(new_node->next = add_one_link(link_name, tmp_room)))
			return (-1);
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
