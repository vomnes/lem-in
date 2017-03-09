/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:12:20 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/09 16:12:37 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

int count_space(char *line)
{
	int count;
	int len;

	count = 0;
	len = ft_strlen(line);
	if (*line == '\0')
		return (-1);
	while (line[i] != '\0')
	{
		if (i > 1 && i < len && ft_isprint(line[i - 1]) != ' ' && \
		line[i] == ' ' && ft_isprint(line[i + 1]) != ' ')
			count++;
	}
	return (0);
}
