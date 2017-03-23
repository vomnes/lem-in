/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:43:28 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/23 20:39:59 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void graph_clean_link(t_link *lst)
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

void graph_clean(t_room *lst)
{
	t_room *tmp;

	tmp = lst;
	while(tmp != NULL)
	{
		ft_strdel(&tmp->name);
		graph_clean_link(tmp->link);
		tmp = tmp->next;
	}
	tmp = NULL;
}

void path_delete(t_path **path)
{
	t_path *tmp;
	t_path *lol;

	tmp = *path;
	while (tmp != NULL)
	{
		lol = tmp;
		tmp = tmp->next;
		ft_strdel(&(lol->name));
		free(lol);
	}
//	free(*path);
}

void path_list_delete(t_list_path **lst)
{
	t_list_path *tmp;
	t_list_path *lol;


	tmp = *lst;
	while (tmp != NULL)
	{
		lol = tmp;
		tmp = tmp->next;
		ft_strdel(&(lol->last_link_name));
		path_delete(&lol->path);
		free(lol);
	}
//	free(*lst);
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
	//	print_graph(room);
		data.list_path = NULL;
		data.solution_path = NULL;
		if (path_algorithm(&room, &data) == -1)
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
	while (42) {}
	return (0);
}

//Need to check comment before nb ants /!
