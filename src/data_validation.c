/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:28:32 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/14 18:17:41 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

void ft_kill_char(char **stock_coord, char **stock_name, char **line)
{
	ft_strdel(&(*stock_coord));
	ft_strdel(&(*stock_name));
	ft_strdel(&(*line));
}

int data_validation(int *num_line)
{
	char *line;
	char nb_ant_ok;
	char start_ok;
	int end_ok;
	char end_flag;
	int space;
	char *stock_name;
	char *stock_coord;
	int count_room;

	line = NULL;
	space = 0;
	nb_ant_ok = 0;
	start_ok = 0;
	end_ok = 0;
	end_flag = 0;
	count_room = 0;
	stock_name = ft_strdup(" ");
	stock_coord = ft_strdup("_");
	while (get_next_line(0, &line) > 0)
	{
		(*num_line)++;
		space = count_space(line);
		if (ft_isdigitstr(line) == 1 && ft_is_signed_integer(line) == 0\
		&& *line != '\0' && nb_ant_ok == 0)
		{
			nb_ant_ok = 1;
			ft_strdel(&line);
		}
		else if ((ft_isdigitstr(line) == 0 || ft_is_signed_integer(line) == -1\
		|| *line != '\0') && nb_ant_ok == 0)
		{
			ft_putstr_fd("Ant Number : Wrong format - ", 2);
			ft_kill_char(&stock_coord, &stock_name, &line);
			return (-1);
		}
		else if (nb_ant_ok == 1)
		{
			if (*line == '#')
			{
				if (ft_strcmp(line, "##start") == 0 && start_ok == 1)
				{
					ft_putstr_fd("Must have only one start - ", 2);
					ft_kill_char(&stock_coord, &stock_name, &line);
					return (-1);
				}
				if (ft_strcmp(line, "##start") == 0)
				{
					if (end_flag == 1)
						return (-1);
					start_ok = 1;
				}
				if (ft_strcmp(line, "##end") == 0)
				{
					end_ok += 1;
					end_flag = 1;
				}
			}
			else if (space == 0 && end_flag == 0)
			{
				if (check_link(line, stock_name) == -1)
				{
					ft_kill_char(&stock_coord, &stock_name, &line);
					return (-1);
				}
			}
			else if (space == 2)
			{
				if (check_x_y_line(line, &stock_name, &stock_coord) == -1)
				{
					ft_kill_char(&stock_coord, &stock_name, &line);
					return (-1);
				}
				end_flag = 0;
				count_room += 1;
			}
			else if (end_flag == 1)
			{
				ft_putstr_fd("Command end must followed by : name <coord_x> <coord_y> - ", 2);
				ft_kill_char(&stock_coord, &stock_name, &line);
				return (-1);
			}
			else if (start_ok == 1)
			{
				ft_putstr_fd("Command start must followed by : name <coord_x> <coord_y> - ", 2);
				ft_kill_char(&stock_coord, &stock_name, &line);
				return (-1);
			}
			else
			{
				ft_putstr_fd("Wrong format - ", 2);
				ft_kill_char(&stock_coord, &stock_name, &line);
				return (-1);
			}
		}
		else
		{
			ft_kill_char(&stock_coord, &stock_name, &line);
			ft_putstr_fd("No ants - ", 2);
			return (-1);
		}
		ft_strdel(&line);
	}
	if (count_room == 0)
	{
		ft_kill_char(&stock_coord, &stock_name, &line);
		ft_putstr_fd("No room - ", 2);
		return (-1);
	}
	if (start_ok == 0)
	{
		ft_kill_char(&stock_coord, &stock_name, &line);
		ft_putstr_fd("No command start - ", 2);
		return (-1);
	}
	if (end_ok == 0)
	{
		ft_kill_char(&stock_coord, &stock_name, &line);
		ft_putstr_fd("No command end - ", 2);
		return (-1);
	}
//	ft_putendl_fd(stock_name, 2);
//	ft_putendl_fd(stock_coord, 2);
	ft_kill_char(&stock_coord, &stock_name, &line);
	return (0);
}
