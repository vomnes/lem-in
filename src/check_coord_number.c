/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coord_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 11:28:09 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/31 11:29:15 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	check_coord_number(char *line)
{
	char	x_collected;
	int		i;

	i = 0;
	x_collected = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			if (x_collected == 0)
			{
				if (collect_number(line, &i) == -1)
					return (-101);
				x_collected = 1;
			}
			else if (x_collected == 1)
			{
				if (collect_number(line, &i) == -1)
					return (-102);
				return (0);
			}
		}
		i++;
	}
	return (0);
}
