/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementation_data_val.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:08:45 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/15 16:12:33 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_kill_char(char **stock_coord, char **stock_name, char **line)
{
	ft_strdel(&(*stock_coord));
	ft_strdel(&(*stock_name));
	ft_strdel(&(*line));
}

static void	code_error_one(int code)
{
	(code == -10) ? ft_putstr_fd("Ant Number : Wrong format", 2) : (void)code;
	(code == -20) ? ft_putstr_fd("Must have only one start", 2) : (void)code;
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

static void	code_error_two(int code)
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

int implementation_data_val(void)
{
	int				num_line;
	t_validation	validation;
	int				ret;

	num_line = 0;
	ret = 0;
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
	return (0);
}
