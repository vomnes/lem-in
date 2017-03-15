/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:07:53 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/15 15:10:08 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

#define LINE val->line

static int check_hash_line(t_validation *val)
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
	return (0);
}

static void flags_counts(t_validation *val)
{
	val->end_flag = 0;
	val->count_room += 1;
	val->start_flag = 0;
}

int analyse_line(int *ret, t_validation *val)
{
	if (*LINE == '#')
		*ret = check_hash_line(val);
	else if (val->space == 0 && val->end_flag == 0)
		*ret = check_link(LINE, val->stock_name);
	else if (val->space == 2)
	{
		*ret = check_x_y_line(LINE, &val->stock_name, &val->stock_coord);
		flags_counts(val);
	}
	else if (val->end_flag == 1)
		*ret = -30;
	else if (val->start_flag == 1)
		*ret = -40;
	else
		*ret = -50;
	return (0);
}
