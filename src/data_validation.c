/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:28:32 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/09 14:12:08 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

static int	ft_isdigitstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (-1);
		i++;
	}
	return (1);
}

static int ft_is_signed_integer(char *str)
{
	long long int value;
	int index;

	value = 0;
	index = 0;
	if (ft_is_integer(str) == -1)
		return (-1);
	else
	{
		value = ft_lltoi(str);
		if (value > 2147483648 || value < 0)
			return (-1);
		while(str[index])
		{
			if (index > 9)
				return (-1);
			index++;
		}
	}
	return (0);
}

int collect_number(char *line, int *i)
{
	char str_number[10];
	int number;
	int index;

	index = 0;
	ft_bzero(str_number, 10);
	while(ft_isdigit(line[*i]))
	{
		if (index > 9)
			return (-1);
		str_number[index] = line[*i];
		index++;
		(*i)++;
	}
	number = ft_lltoi(str_number);
	if (number > 2147483647 || number < 0)
		return (-1);
	return (0);
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
				if (collect_number(line, &i) < 0)
					return (-1);
				x_collected = 1;
			}
			else if (x_collected == 1)
			{
				if (collect_number(line, &i) < 0)
					return (-1);
				return (0);
			}
		}
		i++;
	}
	return (0);
}

int count_space(char *line)
{
	int count;

	count = 0;
	if (*line == '\0')
		return (-1);
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			count++;
	}
	return (0);
}

int data_validation(void)
{
	char *line;
	char nb_ant_ok;
	int space;

	line = NULL;
	space = 0;
	nb_ant_ok = 0;
	while (get_next_line(0, &line) > 0)
	{
		space = count_space(line);
		if (*line == '#')
		{
			ft_strdel(&line);
			continue ;
		}
		else if (space == 0)
		{
			if ()
			if (ft_strchr(line, '-') == NULL)
			{
				ft_strdel(&line);
				return (-1);
			}
		}
		else if (space == 2)
		{

		}
		else
		{
			ft_strdel(&line);
			return (-1);
		}
	}
	ft_strdel(&line);
	return (0);
}
