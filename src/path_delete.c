/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 11:38:37 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/24 11:42:52 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void path_delete(t_path **path)
{
	t_path *tmp;
	t_path *tmp_2;

	tmp = *path;
	while (tmp != NULL)
	{
		tmp_2 = tmp;
		tmp = tmp->next;
		ft_strdel(&(tmp_2->name));
		free(tmp_2);
	}
}
