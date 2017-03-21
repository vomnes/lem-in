/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:50:46 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/21 18:28:26 by vomnes           ###   ########.fr       */
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

	new_path = NULL;
	tmp_room = *rooms;
	tmp_list = data->list_path;
	while (ft_strcmp(tmp_room->name, data->start) != 0)
		tmp_room = tmp_room->next;
	while (42)
	{
		/* Select right list path */
		while (ft_strcmp(tmp_list->name, tmp_room->name) != 0)
			tmp_list = tmp_list->next;
		selected_path = tmp_list->path;
		/* Add new Path to list_path */
		new_path = list_duplicate(selected_path, tmp_room->name); //(data->list_path)
		add_path_list(&(data->list_path), new_path, tmp_room->name);
		tmp_room->visited = 1;
	}
}
