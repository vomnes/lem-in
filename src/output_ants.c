/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 12:26:43 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/28 18:34:24 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

int output_create_move(t_path **path, int *ants_moved, int nb_ants_to_move, int *count_success)
{
    t_path *forward;
    t_path *backward;

    (void)(*count_success);
    forward = *path;
    backward = NULL;
    while (forward != NULL)
    {
        backward = forward;
        if (forward->next == NULL && forward->id_ant > 0 && forward->previous->id_ant == 0)
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
            if ((*ants_moved) >= nb_ants_to_move)
                backward->id_ant = 0;
            else
            {
                backward->id_ant = (*ants_moved) + 1;
                (*ants_moved) += 1;
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

int output_print_ants(t_path *path_1, t_path *path_2, t_data *data)
{
    int nb_ants_a;
    int nb_ants_b;
    int count_success_a;
    int count_success_b;
    char break_a;
    char break_b;

    count_success_a = 0;
    count_success_b = 0;
    (void)path_2;
//    checker_nb = 0;
    nb_ants_b = 0;
    break_a = 0;
    break_b = 0;
    if (path_2 != NULL)
    {
        nb_ants_a = ft_lst_len(path_2) / (ft_lst_len(path_1) + ft_lst_len(path_2)) * (float)data->nb_ants + 0.5;
        nb_ants_b = data->nb_ants - nb_ants_a;
        ft_printf(">>%d<<>>%d<<\n", nb_ants_a, nb_ants_b);
    }
    else
        nb_ants_a = data->nb_ants;
    int checker_nb = 0;
    while (42)
    {
        ft_putendl(UNDERLINE"<    >"RESET);
        if (break_a == 0)
            if (output_create_move(&path_1, &checker_nb, nb_ants_a, &count_success_a) == 1)
                break_a = 1;
        if (break_b == 0)
            if (output_create_move(&path_2, &checker_nb, nb_ants_b, &count_success_b) == 1)
                break_b = 1;
        ft_putchar('\n');
        if (break_a == 1 && break_b == 1)
            break ;
    }
    return (0);
}
