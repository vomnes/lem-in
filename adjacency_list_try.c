/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_main_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:02:48 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/17 12:24:49 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

typedef struct		s_link
{
	char			*name;
	struct s_link	*next;
}					t_link;
/*
typedef struct       s_data
{
	char		     *name;
	int			     x;
	int			     y;
	char		     state;
	t_link		     *link;
}				     t_data;
*/
typedef struct		s_room
{
	struct	s_room	 *next;
	char		     *name;
	int			     x;
	int			     y;
	char		     state;
	t_link		     *link;
}					t_room;
/*
t_data *add_spe_room(char *name, int x, int y)
{
	t_data  *tmp;

	if (!(tmp = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	tmp->name = ft_strdup(name);
	 ft_putendl(tmp->name);
	tmp->x = x;
	 ft_putnbr(tmp->x);
	 ft_putchar('\n');
	tmp->y = y;
	 ft_putnbr(tmp->y);
	 ft_putchar('\n');
	return (tmp);
}
*/
/*
typedef struct		s_room
{
	struct	s_room	 *next;
	char		     *name;
	int			     x;
	int			     y;
	char		     state;
	t_link		     *link;
}					t_room;
*/
/*
void add_room(char *room, t_room **lst)
{
	t_room *tmp;

	ft_putendl("add_room()");
	tmp = NULL;
	tmp = *lst;
	if (*lst == NULL)
	{
		ft_putendl("*lst is NULL");
		if (!(*lst = (t_room*)ft_memalloc(sizeof(t_room))))
			return ;
		(*lst)->name = ft_strdup(room);
		(*lst)->x = 5;
		(*lst)->y = 25;
		(*lst)->next = NULL;
	}
	else
	{
		ft_putendl("in -->");
		while (tmp != NULL)
		{
			tmp = tmp->next;
			ft_putendl("while / **\\");
		}
		ft_putendl("tmp->room");
		if (!(tmp = (t_room*)ft_memalloc(sizeof(t_room))))
			return ;
		ft_putendl("tmp->room malloced");
		tmp->name = ft_strdup(room);
		tmp->x = 42;
		tmp->y = 24;
		ft_putendl("tmp->next");
		tmp->next = NULL;
	}
	ft_putendl("add_room() >> End");
}
*/
int	ft_push_link(t_link **lst_head, char *link_name)
{
	t_link	*new_node;

	new_node = *lst_head;
	if(*lst_head == NULL)
	{
		if (!(*lst_head = (t_link*)malloc(sizeof(t_link))))
			return(-1);
		(*lst_head)->name = ft_strdup(link_name);
		(*lst_head)->next = NULL;
	}
	else
	{
		while (new_node->next != NULL)
			new_node = new_node->next;
		if (!(new_node->next = (t_link*)malloc(sizeof(t_link))))
			return(-1);
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

	tmp = lst;
	while(tmp != NULL)
	{
		printf("-->link : %s\n", tmp->name);
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

void ft_push_link_on(char *selected_room, char *room, t_room **list_room)
{
	t_room	*tmp;

	tmp = *list_room;
	while (ft_strcmp(tmp->name, selected_room) != 0 && tmp != NULL)
	{
		tmp = tmp->next;
	}
	ft_push_link(&(tmp->link), room);
}
/*
ft_push_link(&(my_list->link), "One");
ft_push_link(&(my_list->next->link), "Two");
*/
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
		ft_putendl(L_GREEN"> Start"RESET);
		while (argv[i])
		{
			ft_push_back(&my_list, argv[i], 42, 4, 1); //add_room(argv[i++], &my_list);
			i++;
		}
		ft_push_link_on(argv[3], argv[2], &my_list);
		ft_push_link_on(argv[3], argv[1], &my_list);
		ft_putendl(RED"> Finish"RESET);
	}
	printf("len >> %d\n", ft_lst_len(my_list));
	print_graph(my_list);
	return (0);
}
