/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:43:28 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/08 12:43:49 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int ft_get_input(int fd)
{
	char *line;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}

int main(int argc, char **argv)
{
	int fd;

	if (argc <= 0)
		fd = 0;
	else if (argc == 1 || argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 1)
		{
			ft_putendl_fd("Error - Failed to open file", 2);
			return (-1);
		}
		ft_get_input(fd);
	}
	else
	{
		ft_putendl("Usage : ./lem-in [file_name]");
		return (0);
	}
	return (0);
}
