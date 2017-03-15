/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:43:28 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/15 12:24:12 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void ft_kill_char(char **stock_coord, char **stock_name, char **line)
{
	ft_strdel(&(*stock_coord));
	ft_strdel(&(*stock_name));
	ft_strdel(&(*line));
}

/*
"Ant Number : Wrong format - "
"Must have only one start - "
"Command end must followed by : name <coord_x> <coord_y> - "
"Command start must followed by : name <coord_x> <coord_y> - "
"Wrong format - "
"No ants - "
"No room - "
"No command start - "
"No command end - "

"Wrong format - "
"Name_1 = Name_2 - "
"Name_1 does not exist - "
"Name_2 does not exist - "

L
" Character '-' not allowed in name - "
" already exist - "
"Coordinates wrong format - "
"Coordinates already used - "
*/

static void code_error_one(int code)
{
	(code == -10) ? ft_putstr_fd("Ant Number : Wrong format", 2) : (void)code;
	(code == -20) ? ft_putstr_fd("Must have only one start", 2) : (void)code;
	(code == -30) ? ft_putstr_fd("Command end must followed by : name \
<coord_x> <coord_y>", 2) : (void)code;
	(code == -40) ? ft_putstr_fd("Command start must followed by : name \
<coord_x> <coord_y>", 2) : (void)code;
	(code == -50) ? ft_putstr_fd("Wrong format", 2) : (void)code;
	(code == -60) ? ft_putstr_fd("No ants", 2) : (void)code;
	(code == -70) ? ft_putstr_fd("No room", 2) : (void)code;
	(code == -80) ? ft_putstr_fd("No command start", 2) : (void)code;
	(code == -90) ? ft_putstr_fd("No command end", 2) : (void)code;
}

static void code_error_two(int code)
{
	(code == -91) ? ft_putstr_fd("Wrong format", 2) : (void)code;
	(code == -1) ? ft_putstr_fd("Malloc failed", 2) : (void)code;
	(code == -92) ? ft_putstr_fd("Name_1 = Name_2", 2) : (void)code;
	(code == -93) ? ft_putstr_fd("Name_1 does not exist", 2) : (void)code;
	(code == -94) ? ft_putstr_fd("Name_2 does not exist", 2) : (void)code;
	(code == -101) ? ft_putstr_fd("Coordinate x : Wrong format", 2)\
	 : (void)code;
	(code == -102) ? ft_putstr_fd("Coordinate y : Wrong format", 2)\
	 : (void)code;
	(code == -104) ? ft_putstr_fd("Name must not start by character 'L'", 2)\
	 : (void)code;
	(code == -105) ? ft_putstr_fd("Character '-' not allowed in name", 2)\
	 : (void)code;
	(code == -106) ? ft_putstr_fd("Name already used", 2) : (void)code;
	(code == -107) ? ft_putstr_fd("Coordinates : Wrong format", 2) : (void)code;
	(code == -108) ? ft_putstr_fd("Coordinates already used", 2) : (void)code;
}

int main(int argc, char **argv)
{
	int num_line;
	t_validation validation;
	int ret;
	(void)argv;

	num_line = 0;
	if (argc == 0 || argc == 1)
	{
		if ((ret = data_validation(&num_line, &validation)) < 0)
		{
			ft_putstr_fd("ERROR - ", 2);
			code_error_one(ret);
			code_error_two(ret);
			if ((ret <= -60 && ret >= -90) || ret == -1)
				;
			else
			{
				ft_putstr_fd(" - [Line ", 2);
				ft_putnbr_fd(num_line, 2);
				ft_putstr_fd("]", 2);
			}
			ft_putstr_fd("\n", 2);
			ft_kill_char(&validation.stock_coord, &validation.stock_name, &validation.line);
			return (-1);
		}
		ft_kill_char(&validation.stock_coord, &validation.stock_name, &validation.line);
	}
	else
	{
		ft_putendl("Usage : ./lem-in < [map_name]");
		return (0);
	}
	return (0);
}
