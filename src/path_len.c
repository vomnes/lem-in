/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:31:57 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/29 16:39:07 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

float	path_len(t_path *list)
{
	t_path	*temp;
	float	count;

	temp = list;
	count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
