/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_list_duplicate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:42:30 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/21 16:42:48 by vomnes           ###   ########.fr       */
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
