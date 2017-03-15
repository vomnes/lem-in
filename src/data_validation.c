/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:28:32 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/15 12:24:27 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

#define LINE val->line

void init_val(t_validation *val)
{
	val->line = NULL;
	val->space = 0;
	val->nb_ant_ok = 0;
	val->start_ok = 0;
	val->end_ok = 0;
	val->end_flag = 0;
	val->count_room = 0;
	val->stock_name = ft_strdup(" ");
	val->stock_coord = ft_strdup("_");
	val->code_error = -1;
}

int data_validation(int *num_line, t_validation *val)
{
	int ret;

	ret = 0;
	init_val(val);
	while (get_next_line(0, &LINE) > 0)
	{
		(*num_line)++;
		val->space = count_space(LINE);
		if (ft_isdigitstr(LINE) == 1 && ft_is_signed_integer(LINE) == 0\
		&& *LINE != '\0' && val->nb_ant_ok == 0)
		{
			val->nb_ant_ok = 1;
			ft_strdel(&LINE);
		}
		else if ((ft_isdigitstr(LINE) == 0 || ft_is_signed_integer(LINE) == -1\
		|| *LINE != '\0') && val->nb_ant_ok == 0)
			return (-10);
		else if (val->nb_ant_ok == 1)
		{
			if (*LINE == '#')
			{
				if (ft_strcmp(LINE, "##start") == 0 && val->start_ok == 1)
					return (-20);
				if (ft_strcmp(LINE, "##start") == 0)
				{
					if (val->end_flag == 1)
						return (-1);
					val->start_ok = 1;
					if (val->start_flag == 1)
						return (-40);
					val->start_flag = 1;
				}
				if (ft_strcmp(LINE, "##end") == 0)
				{
					val->end_ok += 1;
					val->end_flag = 1;
					if (val->start_flag == 1)
						return (-40);
				}
			}
			else if (val->space == 0 && val->end_flag == 0)
			{
				if ((ret = check_link(LINE, val->stock_name)) < 0)
					return (ret);
			}
			else if (val->space == 2)
			{
				if ((ret = check_x_y_line(LINE, &val->stock_name, &val->stock_coord)) < 0)
					return (ret);
				val->end_flag = 0;
				val->count_room += 1;
				val->start_flag = 0;
			}
			else if (val->end_flag == 1)
				return (-30);
			else if (val->start_flag == 1)
				return (-40);
			else
				return (-50);
		}
		else
			return (-60);
		ft_strdel(&LINE);
	}
	if (val->nb_ant_ok == 0)
		return (-60);
	if (val->count_room == 0)
		return (-70);
	if (val->start_ok == 0)
		return (-80);
	if (val->end_ok == 0)
		return (-90);
//	ft_putendl_fd(stock_name, 2);
//	ft_putendl_fd(stock_coord, 2);
	return (0);
}
