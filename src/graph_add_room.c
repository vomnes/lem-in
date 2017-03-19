/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_push_room.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 13:29:41 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/19 13:33:00 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	graph_add_room(t_room **lst_head, char *room, int x, int y, char state)
{
	t_room	*new_node;

	new_node = *lst_head;
	if(*lst_head == NULL)
	{
		if (!(*lst_head = (t_room*)malloc(sizeof(t_room))))
			return(-1);
		(*lst_head)->name = ft_strdup(room);
		(*lst_head)->x = x;
		(*lst_head)->y = y;
		(*lst_head)->state = state;
		(*lst_head)->link = NULL;
		(*lst_head)->next = NULL;
	}
	else
	{
		while (new_node->next != NULL)
			new_node = new_node->next;
		if (!(new_node->next = (t_room*)malloc(sizeof(t_room))))
			return(-1);
		new_node->next->name = ft_strdup(room);
		new_node->next->x = x;
		new_node->next->y = y;
		new_node->next->state = state;
		new_node->next->link = NULL;
		new_node->next->next = NULL;
	}
	return (1);
}
