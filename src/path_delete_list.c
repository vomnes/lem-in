/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_delete_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 11:39:44 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/24 11:45:50 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void path_list_delete(t_list_path **lst)
{
	t_list_path *tmp;
	t_list_path *tmp_2;

	tmp = *lst;
	while (tmp != NULL)
	{
		tmp_2 = tmp;
		tmp = tmp->next;
		ft_strdel(&(tmp_2->last_link_name));
		path_delete(&tmp_2->path);
		free(tmp_2);
	}
}
