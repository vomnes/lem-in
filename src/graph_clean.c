/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 11:40:18 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/24 11:40:30 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void graph_clean_link(t_link *lst)
{
	t_link *tmp;

	tmp = lst;
	while(tmp != NULL)
	{
		ft_strdel(&tmp->name);
		tmp = tmp->next;
	}
	tmp = NULL;
}

void graph_clean(t_room *lst)
{
	t_room *tmp;

	tmp = lst;
	while(tmp != NULL)
	{
		ft_strdel(&tmp->name);
		graph_clean_link(tmp->link);
		tmp = tmp->next;
	}
	tmp = NULL;
}
