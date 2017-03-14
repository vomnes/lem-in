/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_x_y_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:48:09 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/14 18:09:25 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

static int ft_malloc_link(char **tmp_name, char *name)
{
	if (!(*tmp_name = ft_strnew(ft_strlen(name) + 3)))
		return (-1);
	*tmp_name = ft_strcat(*tmp_name, " ");
	*tmp_name = ft_strcat(*tmp_name, name);
	*tmp_name = ft_strcat(*tmp_name, " ");
	return (0);
}

static int check_coord_number(char *line)
{
	char x_collected;
	int i;

	i = 0;
	x_collected = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			if (x_collected == 0)
			{
				if (collect_number(line, &i) == -1)
					return (-1);
				x_collected = 1;
			}
			else if (x_collected == 1)
			{
				if (collect_number(line, &i) == -1)
					return (-1);
				return (0);
			}
		}
		i++;
	}
	return (0);
}

int check_x_y_line(char *line, char **stock_name, char **stock_coord)
{
	char *remain;
	char *name;
	char *remain_tmp;
	char *tmp_name;

	if (*line == 'L')
		return (-1);
	name = ft_strndup(line, ft_index(line, ' '));
	if (ft_strchr(name, '-') != NULL)
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(" Character '-' not allowed in name - ", 2);
		ft_strdel(&name);
		return (-1);
	}
	ft_malloc_link(&tmp_name, name);
	if (ft_strstr(*stock_name, tmp_name) != NULL)
	{
		ft_putendl_fd(*stock_name, 2);
		ft_putstr_fd(name, 2);
		ft_putstr_fd(" already exist - ", 2);
		ft_strdel(&name);
		ft_strdel(&tmp_name);
		return (-1);
	}
	ft_strdel(&tmp_name);
	*stock_name = ft_strjoin_free(*stock_name, name);
	ft_strdel(&name);
	*stock_name = ft_strjoin_free(*stock_name, " ");
	remain = ft_strchr(line, ' ');
	if (ft_is_space_digit_str(remain) == -1)
	{
		ft_putstr_fd("Coordinates wrong format - ", 2);
		return (-1);
	}
	remain_tmp = ft_strdup(remain + 1);
	if (ft_strstr(*stock_coord, remain + 1) != NULL)
	{
		ft_putstr_fd("Coordinates already used - ", 2);
		return (-1);
	}
	*stock_coord = ft_strjoin_free(*stock_coord, remain_tmp);
	ft_strdel(&remain_tmp);
	*stock_coord = ft_strjoin_free(*stock_coord, "_");
	if (check_coord_number(line) == -1)
		return (-1);
	return (0);
}
