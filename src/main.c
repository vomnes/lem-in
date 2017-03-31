/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:43:28 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/31 14:22:11 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_elem(t_path **path, int *ret, t_data *data)
{
	*path = NULL;
	*ret = 0;
	data->list_path = NULL;
	data->solution_path = NULL;
}

static int	run_algorithm(t_data *data, t_room **room)
{
	t_path	*path;
	int		ret;

	init_elem(&path, &ret, data);
	if ((ret = path_algorithm(&(*room), data, 1)) == -1)
		return (-1);
	if (ret == -2)
		return (-1);
	path = (data->solution_path)->path;
	while (path)
	{
		if (ft_strcmp(path->name, data->start) != 0 &&
			ft_strcmp(path->name, data->end) != 0)
			path_delif_room(&(*room), path->name);
		path = path->next;
	}
	path_list_delete(&data->list_path);
	data->list_path = NULL;
	if ((ret = path_algorithm(&(*room), data, 2)) == -1)
		return (-1);
	if (ret == -2)
		return (-1);
	return (0);
}

static void	clean_all(t_room **room, t_data *data, char ***input_data)
{
	int i;

	i = 0;
	path_list_delete(&data->solution_path);
	if (*input_data)
	{
		while ((*input_data)[i] != NULL)
			ft_strdel(&(*input_data)[i++]);
	}
	graph_clean(*room);
	path_list_delete(&data->list_path);
	ft_strdel(*input_data);
	ft_strdel(&(data->start));
	ft_strdel(&(data->end));
}

static int	run(char ***input_data, t_data *data, t_room **room, char details)
{
	if (implementation_data_val(&(*input_data), details) == -1)
		return (-1);
	if (graph_create(*input_data, &(*room), data, 0) == -1)
	{
		graph_clean(*room);
		return (-1);
	}
	if (run_algorithm(data, &(*room)) == -1)
	{
		clean_all(&(*room), data, &(*input_data));
		if (details == 1)
			ft_putstr_fd("ERROR - No Path\n", 2);
		else
			ft_putstr_fd("ERROR\n", 2);
		return (-1);
	}
	output_print(data, *input_data, details);
	return (0);
}

int			main(int argc, char **argv)
{
	char	**input_data;
	t_room	*room;
	t_data	data;

	input_data = NULL;
	room = NULL;
	if (argc <= 1)
	{
		if (run(&input_data, &data, &room, 0) == -1)
			return (-1);
	}
	else if (argc == 2 && (ft_strcmp(argv[1], "-details") == 0 || \
	ft_strcmp(argv[1], "-d") == 0))
	{
		if (run(&input_data, &data, &room, 1) == -1)
			return (-1);
	}
	else
	{
		ft_putendl("Usage : ./lem-in [-details] < [map_name]");
		return (0);
	}
	clean_all(&room, &data, &input_data);
	return (0);
}
