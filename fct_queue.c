/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 16:38:45 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/20 18:10:26 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

typedef struct		 s_queue
{
	struct	s_queue  *next;
	char		     *name;
}					t_queue;

int queue_add(t_queue **queue, char *content)
{
    t_queue	*new_node;

    new_node = *queue;
    if (queue == NULL)
    {
        if (!(new_node = (t_queue*)ft_memalloc(sizeof(t_queue))))
            return (-1);
        new_node->name = ft_strdup(content);
        new_node->next = NULL;
    }
    else
    {
        if (!(new_node = (t_queue*)ft_memalloc(sizeof(t_queue))))
            return (-1);
        new_node->name = ft_strdup(content);
        new_node->next = *queue;
        *queue = new_node;
    }
    return (1);
}

void queue_delete_one(t_queue **queue)
{
    t_queue	*delete_node;
    t_queue	*tmp_node;

    delete_node = *queue;
    tmp_node = NULL;
    if (*queue == NULL)
        ft_putendl("IN_EMPTY");
    else
    {
        ft_putendl("IN");
        while (delete_node->next != NULL)
        {
            tmp_node = delete_node;
            delete_node = delete_node->next;
        }
        ft_strdel(&delete_node->name);
        if (tmp_node->next != NULL)
            tmp_node->next = NULL;
        tmp_node = NULL;
    }
}

int main()
{
    t_queue *file;

    file = NULL;
    queue_add(&file, "8");
    queue_add(&file, "7");
    queue_add(&file, "6");
    queue_add(&file, "5");
    queue_add(&file, "4");
    queue_add(&file, "3");
    queue_add(&file, "2");
    queue_add(&file, "1");
    queue_delete_one(&file);
    queue_delete_one(&file);
    queue_delete_one(&file);
    queue_delete_one(&file);
    queue_delete_one(&file);
    queue_delete_one(&file);
    queue_delete_one(&file);
    queue_delete_one(&file);
    t_queue *tmp = file;
    while (tmp != NULL)
    {
        ft_putendl(tmp->name);
        tmp = tmp->next;
    }
    while (42) {}
    return (0);
}
