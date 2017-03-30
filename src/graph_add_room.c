/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_add_room.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 13:29:41 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/30 18:05:12 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_room *graph_add_elem(t_collect *collect)
{
	t_room *room;

	room = NULL;
	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return(NULL);
	if (!((room)->name = ft_strdup(collect->name)))
		return (NULL);
	room->x = collect->coord_x;
	room->y = collect->coord_y;
	room->state = collect->statut;
	room->visited = 0;
	room->link = NULL;
	room->next = NULL;
	return (room);
}

int	graph_add_room(t_room **lst_head, t_collect *collect)
{
	t_room	*new_node;

	new_node = *lst_head;
	if(*lst_head == NULL)
	{
		if (!(*lst_head = graph_add_elem(collect)))
			return (-1);
	}
	else
	{
		while (new_node->next != NULL)
			new_node = new_node->next;
		if (!(new_node->next = graph_add_elem(collect)))
			return (-1);
	}
	return (1);
}
