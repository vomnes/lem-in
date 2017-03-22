/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:28:32 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/22 18:50:19 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define LINE val->line

static int	init_val(t_validation *val)
{
	val->line = NULL;
	val->nb_ant_ok = 0;
	val->start_ok = 0;
	val->start_flag = 0;
	val->end_ok = 0;
	val->end_flag = 0;
	val->space = 0;
	if (!(val->stock_name = ft_strdup(" ")))
		return (-1);
	if (!(val->stock_coord = ft_strdup("_")))
		return (-1);
	val->count_room = 0;
	return (0);
}

static int	last_check(t_validation *val)
{
	if (val->nb_ant_ok == 0)
		return (-60);
	if (val->count_room == 0)
		return (-70);
	if (val->start_ok == 0)
		return (-80);
	if (val->end_ok == 0)
		return (-90);
	return (0);
}

static int	global_analyse(t_validation *val)
{
	int ret;

	ret = 0;
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
		analyse_line(&ret, val);
		if (ret < 0)
			return (ret);
	}
	else
		return (-60);
	ft_strdel(&LINE);
	return (0);
}

int			data_validation(int *num_line, t_validation *val, char **line_input)
{
	int ret;

	ret = 0;
	if (init_val(val) == -1)
		return (-1);
	if (!(*line_input = ft_strdup("\0")))
		return (-1);
	while (get_next_line(0, &LINE) > 0)
	{
		if (!(*line_input = ft_strjoin_free(*line_input, LINE)))
			return (-1);
		if (!(*line_input = ft_strjoin_free(*line_input, "\n")))
			return (-1);
		(*num_line)++;
		if ((ret = global_analyse(val)) < 0)
			return (ret);
	}
	if ((ret = last_check(val)) < 0)
		return (ret);
	return (0);
}
