/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:36:48 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/15 14:42:04 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

static int ft_malloc_link(char **tmp_pn1, char **tmp_pn2, \
char **parse_name_1, char **parse_name_2)
{
	if (!(*tmp_pn1 = ft_strnew(ft_strlen(*parse_name_1) + 2)))
		return (-1);
	*tmp_pn1 = ft_strcat(*tmp_pn1, " ");
	*tmp_pn1 = ft_strcat(*tmp_pn1, *parse_name_1);
	*tmp_pn1 = ft_strcat(*tmp_pn1, " ");
	if (!(*tmp_pn2 = ft_strnew(ft_strlen(*parse_name_2) + 2)))
		return (-1);
	*tmp_pn2 = ft_strcat(*tmp_pn2, " ");
	*tmp_pn2 = ft_strcat(*tmp_pn2, *parse_name_2);
	*tmp_pn2 = ft_strcat(*tmp_pn2, " ");
	return (0);
}

static void ft_free_all(char **tmp_pn1, char **tmp_pn2)
{
	ft_strdel(&(*tmp_pn1));
	ft_strdel(&(*tmp_pn2));
}

static int ft_link_errors(char **parse_name_1, char **parse_name_2, char *stock_name)
{
	char *tmp_pn1;
	char *tmp_pn2;

	if (ft_malloc_link(&tmp_pn1, &tmp_pn2, &(*parse_name_1), &(*parse_name_2)) == -1)
		return (-1);
	if (ft_strcmp(*parse_name_1, *parse_name_2) == 0)
	{
		ft_free_all(&tmp_pn1, &tmp_pn2);
		return (-92);
	}
	if (ft_strstr(stock_name, tmp_pn1) == NULL)
	{
		ft_free_all(&tmp_pn1, &tmp_pn2);
		return (-93);
	}
	if (ft_strstr(stock_name, tmp_pn2) == NULL)
	{
		ft_free_all(&tmp_pn1, &tmp_pn2);
		return (-94);
	}
	ft_free_all(&tmp_pn1, &tmp_pn2);
	return (0);
}

int check_link(char *line, char *stock_name)
{
	char *parse_name_1;
	char *parse_name_2;
	int ret;

	if (ft_strchr(line, '-') != NULL)
	{
		parse_name_1 = ft_strndup(line, ft_index(line, '-'));
		parse_name_2 = ft_strchr(line, '-') + 1;
		if((ret = ft_link_errors(&parse_name_1, &parse_name_2, stock_name)) < 0)
		{
			ft_strdel(&parse_name_1);
			return (ret);
		}
		ft_strdel(&parse_name_1);
	}
	else
		return (-50);
	return (0);
}
