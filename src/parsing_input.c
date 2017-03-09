/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:51:10 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/09 16:17:08 by vomnes           ###   ########.fr       */
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

int get_input(void)
{
	t_data *data;
	t_collect collect;
	char *line;

	(void)data;
	line = NULL;
	init_collect(&collect);
	while (get_next_line(0, &line) > 0)
	{
		if (*line == '#')
		{
			if (ft_strcmp(line, "##start") == 0)
				collect.statut = START;
			else if (ft_strcmp(line, "##end") == 0)
				collect.statut = END;
			ft_strdel(&line);
			continue ;
		}
		else if (ft_strchr(line, ' ') != NULL)
		{
			if (!(collect.name = ft_strsub(line, 0, ft_index(line, ' '))))
				return (-1);
			if (get_x_y(ft_strchr(line, ' '), &collect) == -1)
				return (-1);
			ft_printf("name : %11s | coord_x : %3d | coord_y : %3d | statut : %d\n", \
			collect.name, collect.coord_x, collect.coord_y, collect.statut);
		}
		else if (ft_strchr(line, '-') != NULL)
		{

		}
		init_collect(&collect);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}
