/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_signed_integer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:14:19 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/09 16:14:31 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

int ft_is_signed_integer(char *str)
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
