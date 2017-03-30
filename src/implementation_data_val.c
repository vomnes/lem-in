/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementation_data_val.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:08:45 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/30 12:22:18 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_kill_char(char **stock_coord, char **stock_name, char **line)
{
	ft_strdel(&(*stock_coord));
	ft_strdel(&(*stock_name));
	ft_strdel(&(*line));
}

static void	code_error_a(int code)
{
	(code == -10) ? ft_putstr_fd("Ant Number : Wrong format", 2) : (void)code;
	(code == -20) ? ft_putstr_fd("Must have only one start", 2) : (void)code;
	(code == -25) ? ft_putstr_fd("Must have only one end", 2) : (void)code;
	(code == -30) ? ft_putstr_fd("Command end must followed by : name \
<coord_x> <coord_y>", 2) : (void)code;
	(code == -40) ? ft_putstr_fd("Command start must be followed by : name \
<coord_x> <coord_y>", 2) : (void)code;
	(code == -50) ? ft_putstr_fd("Wrong format", 2) : (void)code;
	(code == -60) ? ft_putstr_fd("No ants", 2) : (void)code;
	(code == -70) ? ft_putstr_fd("No room", 2) : (void)code;
	(code == -80) ? ft_putstr_fd("No command start", 2) : (void)code;
	(code == -90) ? ft_putstr_fd("No command end", 2) : (void)code;
}

static void	code_error(int code)
{
	code_error_a(code);
	(code == -91) ? ft_putstr_fd("Wrong format", 2) : (void)code;
	(code == -1) ? ft_putstr_fd("Malloc failed", 2) : (void)code;
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

static void print_error_message(int code, int num_line)
{
	ft_putstr_fd("ERROR - ", 2);
	code_error(code);
	if ((code <= -60 && code >= -90) || code == -1)
		;
	else
	{
		ft_putstr_fd(" - [Line ", 2);
		ft_putnbr_fd(num_line, 2);
		ft_putstr_fd("]", 2);
	}
	ft_putstr_fd("\n", 2);
}

int implementation_data_val(char ***input_data, char print_message)
{
	int				num_line;
	t_validation	val;
	int				code;
	char 			*line_input;

	num_line = 0;
	code = 0;
	if ((code = data_validation(&num_line, &val, &line_input)) < 0)
	{
		if (print_message == 1)
			print_error_message(code, num_line);
		else
			ft_putstr_fd("ERROR\n", 2);
		ft_strdel(&line_input);
		ft_kill_char(&val.stock_coord, &val.stock_name, &val.line);
		return (-1);
	}
	ft_kill_char(&val.stock_coord, &val.stock_name, &val.line);
	if (!(*input_data = ft_strsplit(line_input, '\n')))
		return (-1);
	ft_strdel(&line_input);
	return (0);
}
