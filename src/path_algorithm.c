/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:50:46 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/31 11:06:46 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

#define NEXT 0
#define PATH_FOUND 1
#define NEXT_LINK 2
#define NO_PATH 3
#define LAST_ROOM (data->list_path)->last_link_name

static void	move_to_right_room(t_room **tmp_room, t_link **tmp_link, \
char call, t_data *data)
{
	*tmp_link = (*tmp_room)->link;
	while (*tmp_link != NULL &&
	(ft_strcmp((*tmp_link)->name, (*tmp_room)->name) == 0 ||
	(ft_strcmp((*tmp_link)->name, data->start) == 0 ||
	(*tmp_link)->visited == call)))
		*tmp_link = (*tmp_link)->next;
}

static int	all_link_checked(t_data *data, t_room **tmp_room, \
t_room **head_room)
{
	if (ft_strcmp(LAST_ROOM, data->end) == 0)
	{
		if (path_add(data, (data->list_path)->path, "/", ADD_SOLUTION) == -1)
			return (-1);
		return (PATH_FOUND);
	}
	if ((*tmp_room)->link == NULL && ft_strcmp(LAST_ROOM, data->end) != 0)
		return (PATH_FOUND);
	else if ((*tmp_room)->link != NULL)
		path_delete_first_elem(&(data->list_path));
	(*tmp_room) = *head_room;
	if (data->list_path == NULL)
	{
		if (data->solution_path == NULL)
			return (NO_PATH);
		return (PATH_FOUND);
	}
	while ((*tmp_room) != NULL && ft_strcmp((*tmp_room)->name, LAST_ROOM))
		(*tmp_room) = (*tmp_room)->next;
	return (NEXT_LINK);
}

static int	breadth_first_search(t_room **tmp_room, t_data *data, \
t_room *head_room, char call)
{
	t_link *tmp_link;

	move_to_right_room(&(*tmp_room), &tmp_link, call, data);
	if (tmp_link == NULL)
		return (all_link_checked(data, &(*tmp_room), &head_room));
	if (path_add(data, (data->list_path)->path, tmp_link->name, ADD_PATH) == -1)
		return (-1);
	tmp_link->visited = call;
	return (NEXT);
}

int			path_algorithm(t_room **rooms, t_data *data, char call)
{
	t_list_path	*tmp_list;
	t_room		*tmp_room;
	int			ret;

	ret = 0;
	tmp_room = *rooms;
	tmp_list = data->list_path;
	while (ft_strcmp(tmp_room->name, data->start) != 0)
		tmp_room = tmp_room->next;
	if (path_add(data, NULL, data->start, ADD_PATH) == -1)
		return (-1);
	while (42)
	{
		if ((ret = breadth_first_search(&tmp_room, data, *rooms, call)) == -1)
			return (-1);
		if (ret == PATH_FOUND)
			break ;
		else if (ret == NEXT_LINK)
			continue ;
		else if (ret == NO_PATH)
			return (-2);
	}
	if (data->solution_path == NULL)
		return (-2);
	return (0);
}
