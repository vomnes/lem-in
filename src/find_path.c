/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:57:53 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/21 17:07:44 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define GRAY 1
#define WHITE 1
#define BLACK 1

/*
t_queue queue; // Linked list
	queue <-- add(this.start_node);
	printNode(this.start_node);
	rootNode.visited = 1;
	while(!queue.isEmpty())
	{
		Node n = (Node)queue.remove();
		Node child = null;
		while((child = getUnvisitedChildNode(n))!= NULL)
		{
			child.visited = 1;
			printNode(child);
			queue.add(child);
		}
	}
*/
/*
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
*/
/*
int	ft_lst_len_link(t_link *list)
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

int find_path(t_room **rooms, char *start, char *end)
{
	t_link *node_link;
	t_room *tmp;
	t_link *tmp_in;
	int len;
	int count;

	node_link = NULL;
	tmp_in= NULL;
	tmp = *rooms;
	len = 0;
	count = 0;
	// Found start node
	while (ft_strcmp(tmp->name, start) != 0)
		tmp = tmp->next;
	ft_printf(L_GREEN"start node --> %s\n"RESET, tmp->name);
    while (42)
    {
		node_link = tmp->link;
		len = ft_lst_len_link(tmp->link); // get number links
		ft_printf("len = %d\n", len);
		while (tmp != NULL)
		{
			if (ft_strcmp(node_link->name, end) == 0)
			{
				ft_printf("end_found : %s\n", node_link->name);
				return (1);
			}
			if (node_link->visited == 0)
			{
				node_link->visited = 1;
				tmp = node_link->link_room;
				ft_printf("node_link->name : %s\n", node_link->name);
				continue ;
			}
			count++;
			if (count == len)
				tmp->done = 1;
			node_link = tmp->link;
			tmp = tmp->next;
		}
    }
}

int graph_algorithm(t_room **rooms, char *start, char *end)
{
	t_room *tmp_room;

	while (ft_strcmp(tmp->name, start) != 0)
		tmp = tmp->next;
	tmp->done = GRAY;
	add start to queue
	while (!queue_is_empty(queue))
	{
		node = queue;
		while ()
		for all branches in node
			if (is_in_list(branch->name, queue) == 1)
				continue ;
			if (branch_color == WHITE)
			{
				branch_color == GRAY;
				add branch to queue
			}
		delete "first in" from queue
		color_node = BLACK
	}
}

int graph_algorithm(t_room **rooms, char *start, char *end)
{
	t_room *tmp_room;

	tmp_room = *rooms;
	while (ft_strcmp(tmp_room->name, start) != 0)
		tmp_room = tmp_room->next;

}
*/
