/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_get_x_y.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:22:12 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/29 18:22:43 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int graph_get_x_y(char *line, t_collect *collect)
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
