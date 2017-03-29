/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_delete_first_elem.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 11:42:15 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/29 16:53:18 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void path_delete_first_elem(t_list_path **list_path)
{
	t_list_path	*old_head;

	old_head = NULL;
	if (old_head == NULL)
		;
	old_head = *list_path;
	ft_strdel(&((*list_path)->last_link_name));
	path_delete(&((*list_path)->path));
	*list_path = (*list_path)->next;
	free(old_head);
}
