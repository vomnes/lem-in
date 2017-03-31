/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 11:40:00 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/31 11:58:43 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	ft_malloc_link(char **tmp_name, char *name)
{
	if (!(*tmp_name = ft_strnew(ft_strlen(name) + 3)))
		return (-1);
	*tmp_name = ft_strcat(*tmp_name, " ");
	*tmp_name = ft_strcat(*tmp_name, name);
	*tmp_name = ft_strcat(*tmp_name, " ");
	return (0);
}

int			check_name(char **tmp_name, char **name, char **stock_name)
{
	if (ft_malloc_link(&(*tmp_name), *name) == -1)
	{
		ft_strdel(&(*name));
		ft_strdel(&(*tmp_name));
		return (-1);
	}
	if (ft_strstr(*stock_name, *tmp_name) != NULL)
	{
		ft_strdel(&(*name));
		ft_strdel(&(*tmp_name));
		return (-106);
	}
	return (0);
}
