/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 13:34:10 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/20 10:08:20 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void print_graph(t_room *lst)
{
	t_room *tmp;

	tmp = lst;
	ft_putendl(Y_GREEN"=== [Print Graph] ==="RESET);
	while(tmp != NULL)
	{
		printf("room : %s - x : %d - y : %d - state : %d\n", tmp->name, \
		tmp->x, tmp->y, tmp->state);
		print_link(tmp->link);
		tmp = tmp->next;
	}
}

void print_link(t_link *lst)
{
	t_link *tmp;
	t_room *test;

	tmp = lst;
	while(tmp != NULL)
	{
		test = tmp->link_room;
		printf("-->link : %s - x : %d - y : %d\n", test->name, test->x, test->y);
		tmp = tmp->next;
	}
}

int	ft_lst_len(t_room *list)
{
	t_room	*temp;
	int		count;

	temp = list;
	count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int	ft_lst_len2(t_link *list)
{
	t_link	*temp;
	int		count;

	temp = list;
	count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
