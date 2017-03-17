/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacency_list_try.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:02:48 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/17 17:14:24 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

typedef struct		s_link
{
	void			*link_room;
	char 			*name;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	struct	s_room	 *next;
	char		     *name;
	int			     x;
	int			     y;
	char		     state;
	char			 visited;
	t_link		     *link;
}					t_room;

int	ft_push_link(t_room *rooms, t_link **lst_head, char *link_name)
{
	t_link	*new_node;
	t_room *tmp_room;

	new_node = *lst_head;
	tmp_room = rooms;
	if(*lst_head == NULL)
	{
		if (!(*lst_head = (t_link*)malloc(sizeof(t_link))))
			return(-1);
		while (ft_strcmp(tmp_room->name, link_name) != 0 && tmp_room != NULL)
			tmp_room = tmp_room->next;
		(*lst_head)->link_room = tmp_room;
		(*lst_head)->name = ft_strdup(link_name);
		(*lst_head)->next = NULL;
	}
	else
	{
		while (new_node->next != NULL)
			new_node = new_node->next;
		if (!(new_node->next = (t_link*)malloc(sizeof(t_link))))
			return(-1);
		while (ft_strcmp(tmp_room->name, link_name) != 0 && tmp_room != NULL)
			tmp_room = tmp_room->next;
		new_node->next->link_room = tmp_room;
		new_node->next->name = ft_strdup(link_name);
		new_node->next->next = NULL;
	}
	return (1);
}

int	ft_push_back(t_room **lst_head, char *room, int x, int y, char state)
{
	t_room	*new_node;

	new_node = *lst_head;
	if(*lst_head == NULL)
	{
		if (!(*lst_head = (t_room*)malloc(sizeof(t_room))))
			return(-1);
		(*lst_head)->name = ft_strdup(room);
		(*lst_head)->x = x;
		(*lst_head)->y = y;
		(*lst_head)->state = state;
		(*lst_head)->link = NULL;
		(*lst_head)->next = NULL;
	}
	else
	{
		while (new_node->next != NULL)
			new_node = new_node->next;
		if (!(new_node->next = (t_room*)malloc(sizeof(t_room))))
			return(-1);
		new_node->next->name = ft_strdup(room);
		new_node->next->x = x;
		new_node->next->y = y;
		new_node->next->state = state;
		new_node->next->link = NULL;
		new_node->next->next = NULL;
	}
	return (1);
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

void print_graph(t_room *lst)
{
	t_room *tmp;

	tmp = lst;
	while(tmp != NULL)
	{
		printf("room : %s - x : %d - y : %d - state : %d\n", tmp->name, \
		tmp->x, tmp->y, tmp->state);
		print_link(tmp->link);
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

void ft_push_link_on(char *selected_room, char *room, t_room **list_room)
{
	t_room	*tmp;
	t_room	*tmp_initial;

	tmp = *list_room;
	tmp_initial = *list_room;
	while (ft_strcmp(tmp->name, selected_room) != 0 && tmp != NULL)
		tmp = tmp->next;
	ft_push_link(tmp_initial, &(tmp->link), room);
}
int main(int argc, char **argv)
{
	t_room *my_list;
	int i;

	i = 1;
	my_list = NULL;
	if (argc < 2)
		ft_putstr("Restart\n");
	else
	{
		ft_push_back(&my_list, "2", 5, 0, 0);
		ft_push_back(&my_list, "0", 1, 2, 1);
		ft_push_back(&my_list, "1", 24, 42, 2);
		ft_push_back(&my_list, "3", 5, 4, 0);
		ft_push_link_on("0", "2", &my_list);
		ft_push_link_on("2", "0", &my_list);
		ft_push_link_on("0", "3", &my_list);
		ft_push_link_on("3", "0", &my_list);
		ft_push_link_on("2", "1", &my_list);
		ft_push_link_on("1", "2", &my_list);
		ft_push_link_on("3", "1", &my_list);
		ft_push_link_on("1", "3", &my_list);
		ft_push_link_on("2", "3", &my_list);
		ft_push_link_on("3", "2", &my_list);
	}
	ft_putendl(Y_GREEN"=== [Print Graph] ==="RESET);
	print_graph(my_list);
	return (0);
}
