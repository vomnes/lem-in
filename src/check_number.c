/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:15:42 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/30 19:10:25 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	check_number(char *line)
{
	char	str_number[11];
	int		number;
	int		index;

	index = 0;
	ft_bzero(str_number, 11);
	while (ft_isdigit(line[index]))
	{
		if (index > 9)
			return (-1);
		str_number[index] = line[index];
		index++;
	}
	number = ft_lltoi(str_number);
	if (number > 2147483647 || number < 0)
		return (-1);
	return (0);
}
