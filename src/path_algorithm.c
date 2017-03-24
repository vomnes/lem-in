/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:50:46 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/24 11:43:44 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/lem_in.h"

static int breadth_first_search(t_room **tmp_room, t_data *data, t_room *head_room)
{
	t_link *tmp_link;

	tmp_link = (*tmp_room)->link;
	while (tmp_link != NULL && (ft_strcmp(tmp_link->name, \
	(*tmp_room)->name) == 0 || tmp_link->visited == 1))
		tmp_link = tmp_link->next;
	if ((char*)tmp_link == NULL)
	{
		if (ft_strcmp((data->list_path)->last_link_name, data->end) == 0)
		{
			if (path_add(data, (data->list_path)->path, "Finish", OFF_ADD) == -1)
				return (-1);
			return (1);
		}
		if ((*tmp_room)->link == NULL && ft_strcmp((data->list_path)->last_link_name, data->end) != 0)
			path_delete_first_elem(&(data->list_path));
		else if ((*tmp_room)->link != NULL)
			path_delete_first_elem(&(data->list_path));
		(*tmp_room) = head_room;
		while (ft_strcmp((*tmp_room)->name, (data->list_path)->last_link_name) != 0)
			(*tmp_room) = (*tmp_room)->next;
		return (2);
	}
	if (path_add(data, (data->list_path)->path, tmp_link->name, ON_ADD) == -1)
		return (-1);
	tmp_link->visited = 1;
	return (0);
}

int path_algorithm(t_room **rooms, t_data *data)
{
	t_list_path *tmp_list;
	t_room *tmp_room;
	int ret;

	ret = 0;
	tmp_room = *rooms;
	tmp_list = data->list_path;
	while (ft_strcmp(tmp_room->name, data->start) != 0)
		tmp_room = tmp_room->next;
	if (path_add(data, NULL, data->start, ON_ADD) == -1)
		return (-1);
	while (42)
	{
		if ((ret = breadth_first_search(&tmp_room, data, *rooms)) == -1)
			return (-1);
		if (ret == 1)
			break ;
		else if (ret == 2)
			continue ;
	}
	return (0);
}
