/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 12:26:43 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/29 16:39:31 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int edit_forward(t_path **forward, t_path **backward, t_path **path)
{
    while (*forward != NULL)
    {
        *backward = *forward;
        if ((*forward)->next == NULL && (*path)->id_ant == 0 \
        && (*forward)->previous->id_ant == 0 && (*forward)->id_ant != 0)
            return (1);
        (*forward) = (*forward)->next;
    }
    return (0);
}

static void add_new_ant(t_path **backward, int *new_ant, \
int nb_ants_to_move, int *nb_ants_moved)
{
    if ((*nb_ants_moved) >= nb_ants_to_move)
        (*backward)->id_ant = 0;
    else
    {
        (*new_ant) += 1;
        (*backward)->id_ant = *new_ant;
        (*nb_ants_moved) += 1;
    }
}

static int output_create_move(t_path **path, int *nb_ants_moved, \
int nb_ants_to_move, int *new_ant)
{
    t_path *forward;
    t_path *backward;

    forward = *path;
    backward = NULL;
    if (edit_forward(&forward, &backward, &(*path)) == 1)
        return (1);
    while (backward != NULL)
    {
        forward = backward;
        if (backward->previous != NULL)
            ft_swap(&(backward->previous->id_ant), &(backward->id_ant));
        else
            add_new_ant(&backward, &(*new_ant), \
            nb_ants_to_move, &(*nb_ants_moved));
        if (forward->id_ant > 0 && ft_strcmp(forward->name, (*path)->name) != 0)
            ft_printf("L%d-%s ", forward->id_ant, forward->name);
        backward = backward->previous;
    }
    return (0);
}

static void move_ants(char break_print[2], int nb_ants[2], \
t_path *path_1, t_path *path_2)
{
    int checker_nb[2];
    int new_ant;

    checker_nb[0] = 0;
    checker_nb[1] = 0;
    new_ant = 0;
    while (42)
    {
        if (output_create_move(&path_1, &checker_nb[0], \
            nb_ants[0], &new_ant) == 1)
            break_print[0] = 1;
        if (path_2 == NULL)
            break_print[1] = 1;
        if (output_create_move(&path_2, &checker_nb[1], \
            nb_ants[1], &new_ant) == 1)
            break_print[1] = 1;
        if (break_print[0] == 1 && break_print[1] == 1)
            break ;
        ft_putchar('\n');
    }
}

void output_print_ants(t_path *path_1, t_path *path_2, t_data *data)
{
    int nb_ants[2];
    char break_print[2];

    nb_ants[0] = 0;
    break_print[0] = 0;
    break_print[1] = 0;
    if (path_2 != NULL)
    {
        nb_ants[0] = path_len(path_2) / (path_len(path_1) + \
        path_len(path_2)) * (float)data->nb_ants + 0.5;
        nb_ants[1] = data->nb_ants - nb_ants[0];
    }
    else
        nb_ants[0] = data->nb_ants;
    move_ants(break_print, nb_ants, path_1, path_2);
}
