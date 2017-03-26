/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_delif_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:11:46 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/26 18:12:14 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	path_delif_link(t_link **alst, char *data_ref)
{
	t_link	*tmp;
	t_link	**indirect;

	indirect = alst;
	while (*indirect)
	{
		if (ft_strcmp((*indirect)->name, data_ref) == 0)
		{
			tmp = (*indirect);
			(*indirect) = (*indirect)->next;
			ft_strdel(&(tmp->name));
			tmp->visited = 0;
		    free(tmp);
		}
		else
			indirect = &(*indirect)->next;
	}
}
