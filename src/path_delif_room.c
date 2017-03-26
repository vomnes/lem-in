/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_delif_room.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:10:05 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/26 18:15:04 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void graph_clean_link(t_link **lst)
{
	t_link *tmp;
	t_link *tmp_2;

	tmp = *lst;
	while(tmp != NULL)
	{
		tmp_2 = tmp;
		tmp = tmp->next;
		ft_strdel(&tmp_2->name);
		free(tmp_2);
	}
	tmp = NULL;
}

void	path_delif_room(t_room **alst, char *data_ref)
{
	t_room	*tmp;
	t_room	**indirect;

	indirect = alst;
	while (*indirect)
	{
		if (ft_strcmp((*indirect)->name, data_ref) == 0)
		{
			tmp = (*indirect);
			(*indirect) = (*indirect)->next;
			ft_strdel(&(tmp->name));
			graph_clean_link(&tmp->link);
			tmp->x = 0;
			tmp->y = 0;
			tmp->state = 0;
			tmp->visited = 0;
			free(tmp);
		}
		else
			indirect = &(*indirect)->next;
	}
	tmp = *alst;
	while (tmp != NULL)
	{
	   path_delif_link(&(tmp->link), data_ref);
	   tmp = tmp->next;
	}
}
