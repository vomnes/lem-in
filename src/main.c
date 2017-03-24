/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:43:28 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/24 11:47:51 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	return (0);
}

//Need to check comment before nb ants \!/
