/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:50:46 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/22 15:57:10 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/lem_in.h"

int delete_path(t_path **path)
{
	t_path *tmp;

	tmp = *path;
	while (tmp != NULL)
	{
		ft_strdel(&(tmp->name));
		tmp = tmp->next;
	}
	return (0);
}

int delete_first_elem(t_list_path **list_path)
{
	t_list_path	*old_head;

	old_head = NULL;
	if (*list_path == NULL)
		return (-1);
	old_head = *list_path;
	ft_strdel(&((*list_path)->last_link_name));
	delete_path(&((*list_path)->path));
	*list_path = (*list_path)->next;
	free(old_head);
	old_head = NULL; // re u sure
	return (0);
}

int add_path_list(t_list_path **list_path, t_path *new_elem, char *last_link_name)
{
	t_list_path *tmp;

	tmp = *list_path;
	if (*list_path == NULL)
	{
		if (!(*list_path = (t_list_path*)malloc(sizeof(t_list_path))))
            return(-1);
		(*list_path)->path = new_elem;
		if (!((*list_path)->last_link_name = ft_strdup(last_link_name)))
			return (-1);
		(*list_path)->next = NULL;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (!(tmp->next = (t_list_path*)malloc(sizeof(t_list_path))))
			return(-1);
		tmp->next->path = new_elem;
		if (!(tmp->next->last_link_name = ft_strdup(last_link_name)))
			return (-1);
		tmp->next->next = NULL;
	}
	return (0);
}

int ft_is_not_in(t_path *path, char *content)
{
	t_path *tmp;

	tmp = path;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, content) == 0)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}

int path_algorithm(t_room **rooms, t_data *data)
{
	t_path *selected_path;
	t_list_path *tmp_list;
	t_room *tmp_room;
	t_path *new_path;
	t_link *tmp_link;

	selected_path = NULL;
	new_path = NULL;
	data->list_path = NULL;
	tmp_room = *rooms;
	tmp_list = data->list_path;

	ft_putendl(GOLD"=== [Start Algorithm] ==="RESET);
	/* Select Start */
	while (ft_strcmp(tmp_room->name, data->start) != 0)
		tmp_room = tmp_room->next;
	ft_putendl(tmp_room->name);
	/* Add start in list_path */
	new_path = list_duplicate(selected_path, data->start); //data->list_path
	add_path_list(&data->list_path, new_path, data->start);
	//print_all_paths(data->list_path);
	while (42)
	{
		/* Select right list path */
		print_all_paths(data->list_path);
		// ft_putendl(tmp_list->last_link_name);
		// ft_putendl(tmp_room->name);
		// while (ft_strcmp(tmp_list->last_link_name, tmp_room->name) != 0)
			// tmp_list = tmp_list->next;
		// selected_path = tmp_list->path;
		/* Select right link of the room - iteration in links */
		tmp_link = tmp_room->link;
		while (tmp_link != NULL && (ft_strcmp(tmp_link->name, \
		tmp_room->name) == 0 || tmp_link->visited == 1 || ft_is_not_in((data->list_path)->path, tmp_link->name) == -1))
			tmp_link = tmp_link->next;
		if ((char*)tmp_link == NULL)
		{
			// Set room as visited
			tmp_room->visited = 1;
			if (tmp_room->link == NULL && ft_strcmp(tmp_room->name, data->end) != 0)
			{
				delete_first_elem(&(data->list_path));
				ft_putendl("Select One");
			}
			else if (ft_strcmp(tmp_room->name, data->end) == 0)
			{
				// cpy list in solution path list
				new_path = list_duplicate(selected_path, "\0"); // tmp_link->name => link
				add_path_list(&(data->solution_path), new_path, "\0");
				ft_putendl("Select Two");
				return (110);
			}
			else if (tmp_room->link != NULL)
			{
				// Si l'on a crée de nouveau path de ce maillon et qu'il a des links
				// --> Delete old list_path
				delete_first_elem(&(data->list_path));
				ft_putendl("Select Three");
			}
			print_all_paths(data->list_path);
			tmp_room = *rooms;
			while (ft_strcmp(tmp_room->name, (data->list_path)->last_link_name) != 0)
				tmp_room = tmp_room->next;
			continue ;
		}
		// Add new Path to list_path
		new_path = list_duplicate((data->list_path)->path, tmp_link->name); // tmp_link->name => link
		add_path_list(&(data->list_path), new_path, tmp_link->name);
		tmp_link->visited = 1;
		// Visit all rooms
	}
	ft_putendl("=== [Solution Paths] ===");
	print_all_paths(data->solution_path);
	return (0);
}
