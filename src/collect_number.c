/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:17:15 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/30 19:07:57 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	collect_number(char *line, int *i)
{
	char	str_number[11];
	int		number;
	int		index;

	index = 0;
	ft_bzero(str_number, 11);
	while (ft_isdigit(line[*i]))
	{
		if (index >= 10)
			return (-1);
		str_number[index] = line[*i];
		index++;
		(*i)++;
	}
	number = ft_lltoi(str_number);
	if (number > 2147483647 || number < 0)
		return (-1);
	return (number);
}
