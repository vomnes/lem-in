/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 12:26:43 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/29 14:15:22 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int output_create_move(t_path **path, int *nb_ants_moved, int nb_ants_to_move, int *new_ant)
{
    t_path *forward;
    t_path *backward;

    forward = *path;
    backward = NULL;
    while (forward != NULL)
    {
        backward = forward;
        if (forward->next == NULL && (*path)->id_ant == 0 \
        && forward->previous->id_ant == 0 && forward->id_ant != 0)
            return (1);
        forward = forward->next;
    }
    while (backward != NULL)
    {
        forward = backward;
        if (backward->previous != NULL)
            ft_swap(&(backward->previous->id_ant), &(backward->id_ant));
        else
        {
            if ((*nb_ants_moved) >= nb_ants_to_move)
                backward->id_ant = 0;
            else
            {
                (*new_ant) += 1;
                backward->id_ant = *new_ant;
                (*nb_ants_moved) += 1;
            }
        }
        backward = backward->previous;
    }
    while (forward != NULL)
    {
        backward = forward;
        if (forward->id_ant > 0 && ft_strcmp(forward->name, (*path)->name) != 0)
            ft_printf("L%d-%s ", forward->id_ant, forward->name);
        forward = forward->next;
    }
    return (0);
}

static float	ft_lst_len(t_path *list)
{
	t_path	*temp;
	float	count;

	temp = list;
	count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int output_print_ants(t_path *path_1, t_path *path_2, t_data *data)
{
    int nb_ants_a;
    int nb_ants_b;
    char break_a;
    char break_b;

    nb_ants_b = 0;
    break_a = 0;
    break_b = 0;
    if (path_2 != NULL)
    {
        nb_ants_a = ft_lst_len(path_2) / (ft_lst_len(path_1) + ft_lst_len(path_2)) * (float)data->nb_ants + 0.5;
        nb_ants_b = data->nb_ants - nb_ants_a;
    }
    else
            nb_ants_a = data->nb_ants;
    int checker_nb_a = 0;
    int checker_nb_b = 0;
    int new_ant = 0;
    while (42)
    {
        if (output_create_move(&path_1, &checker_nb_a, nb_ants_a, &new_ant) == 1)
            break_a = 1;
        if (path_2 == NULL)
            break_b = 1;
        if (output_create_move(&path_2, &checker_nb_b, nb_ants_b, &new_ant) == 1)
            break_b = 1;
        if (break_a == 1 && break_b == 1)
            break ;
        ft_putchar('\n');
    }
    return (0);
}
