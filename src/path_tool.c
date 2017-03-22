/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:40:04 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/22 15:37:53 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/lem_in.h"

void print_path(t_path *lst)
{
	t_path *tmp;

	tmp = lst;
	ft_putstr(Y_GREEN"Print Path ===> "RESET);
	while(tmp != NULL)
	{
		ft_putstr(tmp->name);
        ft_putstr(" --> ");
		tmp = tmp->next;
	}
    ft_putchar('\n');
}

void print_all_paths(t_list_path *lst)
{
	t_list_path *tmp;

	tmp = lst;
	ft_putendl(GREEN"=== [Print Paths] ==="RESET);
	if (tmp == NULL)
		ft_putendl(GREEN"NO PATH"RESET);
	while(tmp != NULL)
	{
		ft_printf("[%s] >> ", tmp->last_link_name);
		print_path(tmp->path);
		tmp = tmp->next;
	}
	ft_putendl(GREEN"=== [    End    ] ==="RESET);
}
