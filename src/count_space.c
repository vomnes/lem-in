/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:12:20 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/09 17:16:37 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

int count_space(char *line)
{
	int count;
	int len;
	int i;

	count = 0;
	len = ft_strlen(line);
	i = 0;
	if (*line == '\0')
		return (-1);
	while (line[i] != '\0')
	{
		if (line[i - 1] != ' ' && line[i] == ' ' && line[i + 1] != ' ')
			count++;
		i++;
	}
	return (count);
}
