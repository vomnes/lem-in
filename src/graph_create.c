/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:51:10 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/19 14:15:38 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

int get_x_y(char *line, t_collect *collect)
{
	int i;
	char x_collected;

	i = 0;
	x_collected = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			if (x_collected == 0)
			{
				if ((collect->coord_x = collect_number(line, &i)) == -1)
					return (-1);
				x_collected = 1;
			}
			else if (x_collected == 1)
			{
				if ((collect->coord_y = collect_number(line, &i)) == -1)
					return (-1);
				return (0);
			}
		}
		i++;
	}
	return (0);
}

void init_collect(t_collect *collect)
{
	collect->coord_x = 0;
	collect->coord_y = 0;
	collect->name = NULL;
	collect->statut = 0;
}

int graph_create(char **input_data, t_room **room)
{
	t_collect collect;
	char *line;
	int i;

	line = NULL;
	i = 0;
	init_collect(&collect);
	while (input_data[i] != NULL)
	{
		if (input_data[i][0] == '#')
		{
			if (ft_strcmp(input_data[i], "##start") == 0)
				collect.statut = START;
			else if (ft_strcmp(input_data[i], "##end") == 0)
				collect.statut = END;
			i++;
			continue ;
		}
		else if (ft_strchr(input_data[i], ' ') != NULL)
		{
			if (!(collect.name = ft_strsub(input_data[i], 0, ft_index(input_data[i], ' '))))
				return (-1);
			if (get_x_y(ft_strchr(input_data[i], ' '), &collect) == -1)
				return (-1);
			if (graph_add_room(room, collect.name, collect.coord_x, collect.coord_y, collect.statut) == -1)
				return (-1);
		}
		else if (ft_strchr(input_data[i], '-') != NULL)
		{
			if (!(collect.name_1 = ft_strndup(input_data[i], ft_index(input_data[i], '-'))))
        		return (-1);
			collect.name_2 = ft_strchr(input_data[i], '-') + 1;
			if (graph_add_link(collect.name_1, collect.name_2, room) == -1)
				return (-1);
			if (graph_add_link(collect.name_2, collect.name_1, room) == -1)
				return (-1);
		}
		init_collect(&collect);
		i++;
	}
	return (0);
}
