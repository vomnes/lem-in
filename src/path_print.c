/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:40:04 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/31 11:49:51 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	print_path(t_path *lst)
{
	t_path *tmp;

	tmp = lst;
	ft_putstr(Y_GREEN"Path : "RESET);
	while (tmp != NULL)
	{
		ft_putstr(tmp->name);
		if (tmp->next != NULL)
			ft_putstr(" --> ");
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void		path_print(t_list_path *lst)
{
	t_list_path *tmp;

	tmp = lst;
	ft_putendl(GREEN"=== [Print Paths] ==="RESET);
	if (tmp == NULL)
		ft_putendl(GREEN"NO PATH"RESET);
	if (path_len(tmp->path) == 2)
	{
		print_path(tmp->path);
		return ;
	}
	while (tmp != NULL)
	{
		print_path(tmp->path);
		tmp = tmp->next;
	}
}
