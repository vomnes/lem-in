/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:43:28 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/24 20:30:47 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void graph_clean_link(t_link *lst)
{
	t_link *tmp;

	tmp = lst;
	while(tmp != NULL)
	{
		ft_strdel(&tmp->name);
		tmp = tmp->next;
	}
	tmp = NULL;
}
/*
void destroy_room(t_room **room, char *room_to_detroy)
{
	t_room *tmp;
	t_room *tmp_2;

	tmp = *room;
	tmp_2 = *room;
	while (tmp != NULL && ft_strcmp(tmp->name, room_to_detroy) != 0)
	{
		tmp_2 = tmp;
		tmp = tmp->next;
	}
	ft_strdel(&(tmp->name));
	graph_clean_link(tmp->link);
	tmp->x = 0;
	tmp->y = 0;
	tmp->state = 0;
	tmp->visited = 0;
	free(tmp);
	// if (tmp->next != NULL)
		// tmp_2 = tmp->next;
	tmp = tmp_2->next;
}
*/

void destroy_elem_link(t_link **original, char *elem_to_detroy)
{
	t_link *tmp;
	t_link *copy;

	tmp = *original;
	copy = NULL;
    if (*original == NULL)
    	return ;
    if (ft_strcmp(tmp->name, elem_to_detroy) == 0)
    {
         *original = tmp->next;
		 ft_strdel(&(tmp->name));
		 tmp->visited = 0;
		 free(tmp);
		 tmp = NULL;
         return ;
    }
	while (tmp->next != NULL && ft_strcmp(tmp->next->name, elem_to_detroy) != 0)
		tmp = tmp->next;
	if (tmp->next == NULL)
		return ;
    copy = tmp->next;
	tmp->next = copy->next;
	ft_strdel(&(copy->name));
	copy->visited = 0;
    free(copy);
}

void destroy_room(t_room **room, char *room_to_detroy)
{
	t_room *tmp;
	t_room *copy;

	tmp = *room;
	copy = NULL;
    if (*room == NULL)
       return ;
     if (ft_strcmp(tmp->name, room_to_detroy) == 0)
     {
         *room = tmp->next;
		 ft_strdel(&(tmp->name));
		 graph_clean_link(tmp->link);
		 tmp->x = 0;
		 tmp->y = 0;
		 tmp->state = 0;
		 tmp->visited = 0;
		 free(tmp);
         return ;
     }
	 while (tmp->next->next != NULL && ft_strcmp(tmp->next->name, room_to_detroy) != 0)
	 	tmp = tmp->next;
     copy = tmp->next;
	 tmp->next = copy->next;
	 ft_strdel(&(copy->name));
	 graph_clean_link(copy->link);
	 copy->x = 0;
	 copy->y = 0;
	 copy->state = 0;
	 copy->visited = 0;
     free(copy);
	 tmp = *room;
	 while (tmp != NULL)
	 {
 	 	destroy_elem_link(&(tmp->link), room_to_detroy);
		tmp = tmp->next;
	 }
}

void	lst_delif_link(t_link **alst, char *data_ref)
{
	t_link	*tmp;
	t_link	**indirect;

	indirect = alst;
	while (*indirect)
	{
		if (ft_strcmp((*indirect)->name, data_ref) == 0)
		{
			tmp = (*indirect);
			(*indirect) = (*indirect)->next;
			ft_strdel(&(tmp->name));
			tmp->visited = 0;
		    free(tmp);
		//	ft_lstdelone(&tmp, del);
		}
		else
			indirect = &(*indirect)->next;
	}
}

void	ft_lst_delif_room(t_room **alst, char *data_ref)
{
	t_room	*tmp;
	t_room	**indirect;

	indirect = alst;
	while (*indirect)
	{
		if (ft_strcmp((*indirect)->name, data_ref) == 0)
		{
			tmp = (*indirect);
			(*indirect) = (*indirect)->next;
			ft_strdel(&(tmp->name));
			graph_clean_link(tmp->link);
			tmp->x = 0;
			tmp->y = 0;
			tmp->state = 0;
			tmp->visited = 0;
		//	ft_lstdelone(&tmp, del);
		}
		else
			indirect = &(*indirect)->next;
	}
	tmp = *alst;
	while (tmp != NULL)
	{
	   lst_delif_link(&(tmp->link), data_ref);
	   tmp = tmp->next;
	}
}

int		main(int argc, char **argv)
{
	char **input_data;
	t_room *room;
	t_data data;
	int i;

	(void)argv;
	input_data = NULL;
	room = NULL;
	i = 0;
	if (argc == 0 || argc == 1)
	{
		if (implementation_data_val(&input_data) == -1)
			return (-1);
		if (graph_create(input_data, &room, &data) == -1)
			return (-1);
		// print_graph(room);
		data.list_path = NULL;
		data.solution_path = NULL;
		if (path_algorithm(&room, &data, 1) == -1)
			return (-1);
		t_path *path = (data.solution_path)->path;
		while (path)
		{
			if (ft_strcmp(path->name, data.start) != 0 &&
				ft_strcmp(path->name, data.end) != 0)
				ft_lst_delif_room(&room, path->name);
			path = path->next;
		}
		path_list_delete(&data.list_path);
		data.list_path = NULL;
		// print_graph(room);
		if (path_algorithm(&room, &data, 2) == -1)
			return (-1);
		print_all_paths(data.solution_path);
		graph_clean(room);
		path_list_delete(&data.list_path);
		path_list_delete(&data.solution_path);
	}
	else
	{
		ft_putendl("Usage : ./lem-in < [map_name]");
		return (0);
	}
	while (input_data[i] != NULL)
		ft_strdel(&input_data[i++]);
	ft_strdel(input_data);
	ft_strdel(&(data.start));
	ft_strdel(&(data.end));
	return (0);
}

//Need to check comment before nb ants \!/
