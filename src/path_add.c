/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:42:30 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/28 17:12:00 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/lem_in.h"

static int	path_push_elem_back(t_path **lst_head, char *content)
{
    t_path	*new_node;

    new_node = *lst_head;
    if(*lst_head == NULL)
    {
        if (!(*lst_head = (t_path*)malloc(sizeof(t_path))))
            return(-1);
    	if (!((*lst_head)->name = ft_strdup(content)))
        	return (-1);
		(*lst_head)->id_ant = 0;
        (*lst_head)->next = NULL;
        (*lst_head)->previous = NULL;
    }
    else
    {
        while (new_node->next != NULL)
            new_node = new_node->next;
        if (!(new_node->next = (t_path*)malloc(sizeof(t_path))))
            return(-1);
        if (!(new_node->next->name = ft_strdup(content)))
            return (-1);
        new_node->next->id_ant = 0;
        new_node->next->next = NULL;
        new_node->next->previous = new_node;
    }
    return (1);
}

static t_path *list_duplicate(t_path *original, char *new_one, char on_off)
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
    if (on_off == ON_ADD)
        if (path_push_elem_back(&duplicate, new_one) == -1)
            return (NULL);
    return (duplicate);
}

static int add_path_list(t_list_path **list_path, t_path *new_elem, char *last_link_name)
{
	t_list_path *tmp;

	tmp = *list_path;
	if (*list_path == NULL)
	{
		if (!(*list_path = (t_list_path*)malloc(sizeof(t_list_path))))
            return(-1);
		(*list_path)->path = new_elem;
		if (!((*list_path)->last_link_name = ft_strdup(last_link_name)))
			return (-1);
		(*list_path)->next = NULL;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (!(tmp->next = (t_list_path*)malloc(sizeof(t_list_path))))
			return(-1);
		tmp->next->path = new_elem;
		if (!(tmp->next->last_link_name = ft_strdup(last_link_name)))
			return (-1);
		tmp->next->next = NULL;
	}
	return (0);
}

int path_add(t_data *data, t_path *original, char *title, char on_off)
{
	t_path *new_path;

	new_path = NULL;
	new_path = list_duplicate(original, title, on_off);
	if (on_off == 1)
    {
        if(add_path_list(&(data->list_path), new_path, title) == -1)
            return (-1);
    }
	else
    {
        if (add_path_list(&(data->solution_path), new_path, title) == -1)
            return (-1);
    }
    return (0);
}
