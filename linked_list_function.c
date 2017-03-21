/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 10:06:44 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/21 11:51:44 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

typedef struct		 s_path
{
	struct	s_path   *next;
	char		     *name;
}					t_path;

int path_add(t_path **path, char *content)
{
    t_path	*new_node;

    new_node = *path;
    if (path == NULL)
    {
        if (!(new_node = (t_path*)ft_memalloc(sizeof(t_path))))
            return (-1);
        if (!(new_node->name = ft_strdup(content)))
            return (-1);
        new_node->next = NULL;
    }
    else
    {
        if (!(new_node = (t_path*)ft_memalloc(sizeof(t_path))))
            return (-1);
        if (!(new_node->name = ft_strdup(content)))
            return (-1);
        new_node->next = *path;
        *path = new_node;
    }
    return (1);
}

int	path_push_elem_back(t_path **lst_head, char *content)
{
    t_path	*new_node;

    new_node = *lst_head;
    if(*lst_head == NULL)
    {
        if (!(*lst_head = (t_path*)malloc(sizeof(t_path))))
            return(-1);
        if (!((*lst_head)->name = ft_strdup(content)))
            return (-1);
        (*lst_head)->next = NULL;
    }
    else
    {
        while (new_node->next != NULL)
            new_node = new_node->next;
        if (!(new_node->next = (t_path*)malloc(sizeof(t_path))))
            return(-1);
        if (!(new_node->next->name = ft_strdup(content)))
            return (-1);
        new_node->next->next = NULL;
    }
    return (1);
}

t_path *list_duplicate(t_path *original, char *new_one)
{
    t_path *duplicate;
    t_path *tmp;

    duplicate = NULL;
    tmp = original;
    while (tmp != NULL)
    {
        if (path_push_elem_back(&duplicate, tmp->name) == -1)
            return (NULL);
        tmp = tmp->next;
    }
    if (path_push_elem_back(&duplicate, new_one) == -1)
        return (NULL);
    return (duplicate);
}

void print_path(t_path *lst)
{
	t_path *tmp;

	tmp = lst;
	ft_putendl(Y_GREEN"=== [Print Path] ==="RESET);
	while(tmp != NULL)
	{
		ft_putstr(tmp->name);
        ft_putstr(" --> ");
		tmp = tmp->next;
	}
    ft_putchar('\n');
}

int main()
{
    t_path *path;
    t_path *new_path;

    path = NULL;
/*    path_add(&path, "One");
    path_add(&path, "Two");
    path_add(&path, "Three");
    path_add(&path, "Four");
    path_add(&path, "Five");
    path_add(&path, "Six");
    path_add(&path, "Seven");*/
    print_path(path);
    if (!(new_path = list_duplicate(path, "NEW_ONE !!!")))
        return (-1);
    print_path(new_path);
    return (0);
}
