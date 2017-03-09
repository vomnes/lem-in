/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:51:10 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/09 13:03:46 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"
/*
static int	ft_isdigitstr(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (-1);
		i++;
	}
	return (1);
}
*/
/*if (ft_isdigitstr(argv[i + 1]) == -1)
{
	ft_putendl_fd("Error", 2);
	return (-1);
}
else if (ft_lltoi(argv[i + 1]) >= 2147483648
|| ft_lltoi(argv[i + 1]) < -2147483648
|| ft_strcmp(argv[i + 1], "-") == 0)
{
	ft_putendl_fd("Error", 2);
	return (-1);
}*/

int collect_number(char *line, int *i)
{
	char str_number[10];
	int number;
	int index;

	index = 0;
	ft_putendl(line);
	ft_bzero(str_number, 10);
	while(ft_isdigit(line[*i]))
	{
		ft_printf("i : %c\n", line[*i]);
		if (index > 10)
			return (-1);
		str_number[index] = line[*i];
		index++;
		(*i)++;
	}
	number = ft_lltoi(str_number);
	if (number > 2147483647 || number < 0)
		return (-1);
	return (number);
}

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
			ft_printf("coord_x : %3d | coord_y : %3d | name : %11s | statut : %d\n", \
			collect.coord_x, collect.coord_y, collect.name, collect.statut);
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
