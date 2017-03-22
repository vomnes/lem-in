/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:50:46 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/22 10:03:10 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/lem_in.h"

int add_path_list(t_list_path **list_path, t_path *new_elem, char *last_link_name)
{
	t_list_path *tmp;

	tmp = *list_path;
	if (tmp == NULL)
	{
		tmp->list_path = new_elem;
		if (!(tmp->last_link_name = ft_strdup(last_link_name)))
			return (-1);
		tmp->next = NULL;
	}
	else
	{
		while (tmp != NULL)
			tmp = tmp->next;
		tmp->list_path = new_elem;
		if (!(tmp->last_link_name = ft_strdup(last_link_name)))
			return (-1);
		tmp->next = NULL;
	}
	return (0);
}

int path_algorithm(t_room **rooms, t_data *data)
{
	t_path *selected_path;
	t_list_path *tmp_list;
	t_room *tmp_room;
	t_path *new_path;
	t_link *tmp_link;

	new_path = NULL;
	tmp_room = *rooms;
	tmp_list = data->list_path;
	/* Select Start */
	while (ft_strcmp(tmp_room->name, data->start) != 0)
		tmp_room = tmp_room->next;
	/* Add start in list_path */
	new_path = list_duplicate(selected_path, tmp_room->name); //data->list_path
	add_path_list(&(data->list_path), new_path, tmp_room->name);
	while (42)
	{
		/* Select right list path */
		while (ft_strcmp(tmp_list->last_link_name, tmp_room->name) != 0)
			tmp_list = tmp_list->next;
		selected_path = tmp_list->path;
		/* Select right link of the room */
		tmp_link = tmp_room->link;
		while (ft_strcmp(tmp_link->name, tmp_room->name) == 0 || tmp_link->visited == 1)
			tmp_link = tmp_link->next;
		if ((char*)tmp_link == NULL)
		{
			/* Set room as visited */
			tmp_room->visited = 1;
			continue ;
		}
		/* Add new Path to list_path */
		new_path = list_duplicate(selected_path, tmp_link->name); // tmp_link->name => link
		add_path_list(&(data->list_path), new_path, tmp_room->name);
		tmp_link->visited = 1;
		/* Visit all rooms */
	}
	return (0);
}
