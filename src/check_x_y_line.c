/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_x_y_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:48:09 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/31 11:41:48 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	first_check(char *line, char **name)
{
	if (*line == 'L')
		return (-104);
	if (!(*name = ft_strndup(line, ft_index(line, ' '))))
		return (-1);
	if (ft_strchr(*name, '-') != NULL)
	{
		ft_strdel(&(*name));
		return (-105);
	}
	return (0);
}

static int	ft_malloc_coord(char **tmp_name, char *name)
{
	if (!(*tmp_name = ft_strnew(ft_strlen(name) + 3)))
		return (-1);
	*tmp_name = ft_strcat(*tmp_name, "_");
	*tmp_name = ft_strcat(*tmp_name, name);
	*tmp_name = ft_strcat(*tmp_name, "_");
	return (0);
}

static int	coord_xy(char *line, char **stock_coord, int ret)
{
	char	*remain;
	char	*remain_tmp;
	char	*tmp_stock_coord;

	remain = ft_strchr(line, ' ');
	if (ft_is_space_digit_str(remain) == -1)
		return (-107);
	if (!(remain_tmp = ft_strdup(remain + 1)))
		return (-1);
	if (ft_malloc_coord(&tmp_stock_coord, remain + 1) == -1)
		return (-1);
	if (ft_strstr(*stock_coord, tmp_stock_coord) != NULL)
	{
		ft_strdel(&tmp_stock_coord);
		return (-108);
	}
	ft_strdel(&tmp_stock_coord);
	if (!(*stock_coord = ft_strjoin_free(*stock_coord, remain_tmp)))
		return (-1);
	ft_strdel(&remain_tmp);
	if (!(*stock_coord = ft_strjoin_free(*stock_coord, "_")))
		return (-1);
	if ((ret = check_coord_number(line)) < 0)
		return (ret);
	return (0);
}

int			check_x_y_line(char *line, char **stock_name, char **stock_coord)
{
	char	*name;
	char	*tmp_name;
	int		ret;

	ret = 0;
	if ((ret = first_check(line, &name)) < 0)
		return (ret);
	if ((ret = check_name(&tmp_name, &name, &(*stock_name))) < 0)
		return (ret);
	ft_strdel(&tmp_name);
	if (!(*stock_name = ft_strjoin_free(*stock_name, name)))
		return (-1);
	ft_strdel(&name);
	if (!(*stock_name = ft_strjoin_free(*stock_name, " ")))
		return (-1);
	if ((ret = coord_xy(line, &(*stock_coord), 0)) < 0)
		return (ret);
	return (0);
}
