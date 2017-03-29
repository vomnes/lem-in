/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:51:10 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/29 18:24:55 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

static void init_collect(t_collect *collect)
{
	collect->coord_x = 0;
	collect->coord_y = 0;
	collect->name = NULL;
	collect->statut = 0;
}

static int create_room(t_collect *collect, char *line, t_room **room, t_data *data)
{
	if (!(collect->name = ft_strndup(line,\
	ft_index(line, ' '))))
		return (-1);
	if (graph_get_x_y(ft_strchr(line, ' '), collect) == -1)
		return (-1);
	if (collect->statut == START)
		data->start = ft_strdup(collect->name);
	if (collect->statut == END)
		data->end = ft_strdup(collect->name);
	if (graph_add_room(&(*room), collect) == -1)
		return (-1);
	ft_strdel(&collect->name);
	return (0);
}

static int create_link(t_collect *collect, char *line, t_room **room)
{
	if (!(collect->name_1 = ft_strndup(line, ft_index(line, '-'))))
		return (-1);
	collect->name_2 = ft_strchr(line, '-') + 1;
	if (graph_add_link(collect->name_1, collect->name_2, &(*room)) == -1)
		return (-1);
	if (graph_add_link(collect->name_2, collect->name_1, &(*room)) == -1)
		return (-1);
	ft_strdel(&collect->name_1);
	return (0);
}

static void check_start_end(char *line, t_collect *collect, int *i)
{
	if (ft_strcmp(line, "##start") == 0)
		collect->statut = START;
	else if (ft_strcmp(line, "##end") == 0)
		collect->statut = END;
	(*i)++;
}

int graph_create(char **input_data, t_room **room, t_data *data, int i)
{
	t_collect collect;

	init_collect(&collect);
	while (input_data[i] != NULL)
	{
		if (ft_isdigitstr(input_data[i]) == 1)
			data->nb_ants = ft_lltoi(input_data[i]);
		if (input_data[i][0] == '#')
		{
			check_start_end(input_data[i], &collect, &i);
			continue ;
		}
		else if (ft_strchr(input_data[i], ' ') != NULL)
		{
			if (create_room(&collect, input_data[i], &(*room), data) == -1)
				return (-1);
		}
		else if (ft_strchr(input_data[i], '-') != NULL)
			if (create_link(&collect, input_data[i], &(*room)) == -1)
				return (-1);
		init_collect(&collect);
		i++;
	}
	return (0);
}
