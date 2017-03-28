/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 12:26:43 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/27 18:58:38 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
/*
int output_print_ants(int len, int nb_ants, char *tab[3])
{
    int integer[len];
    int i = 0;
    int count = 0;
    int ant_value = 0;

    while (i < len)
        integer[i++] = 0;
    integer[0] = 0;
    while (integer[len - 1] != nb_ants)
    {
        if (integer[0] < nb_ants && integer[0] >= 0)
            integer[0]++;
        else
            integer[0] = -1;
        integer[len - 1] = integer[len - 2];
        if (integer[len - 1] > 0)
            count++;
        // #iterate
        i = len - 3;
        while (i >= 0)
        {
            integer[i + 1] = integer[i];
            i--;
        }
        // Print IT !
        i = 1;
        while (i < len)
        {
            if (integer[i] == -1 || integer[i] == 0)
            {
                i++;
                continue;
            }
            ft_printf("L%d-%s ", integer[i], tab[i]);
            i++;
        }
        ft_printf("\n");
    }
    return (0);
}
*/
static int	ft_lst_len(t_path *list)
{
	t_path	*temp;
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

void init_tab(int **pos, int len)
{
    int i;

    i = 0;
    if (!(*pos = (int*)malloc(sizeof(*pos) * len)))
        ;
    while (i < len)
        (*pos)[i++] = 0;
}

void output_print_ants(t_path *path_1, t_path *path_2, t_data *data)
{
    int *pos_a;
    int *pos_b;
 	  t_path *tmp_a;
	  t_path *tmp_b;
    int len_a;
    int len_b;
	int start_value;

    ft_putendl("__Algo in__");
    tmp_a = NULL;
    tmp_b = NULL;
    len_a = ft_lst_len(path_1);
    len_b = ft_lst_len(path_2);
    init_tab(&pos_a, len_a);
    init_tab(&pos_b, len_b);
/*	int i = 0;
	  while (i < len_a)
		    ft_putnbr(pos_a[i++]);*/
    start_value = data->nb_ants;
    ft_putendl("____");
    tmp_a = path_1;
    tmp_b = path_2;
    ft_putnbr(tmp_a->value);
    /*while (tmp_a->value != data->nb_ants || tmp_b->value != data->nb_ants)
    {
        ft_putendl("-->");
        tmp_a = path_1->next;
        tmp_b = path_2->next;
        ft_putendl("-->");
        while (tmp_a != NULL || tmp_b != NULL)
      {
        if (tmp_a != NULL)
        {
          if (tmp_a->value)
            tmp_a->value++;
            tmp_a = tmp_a->next;
            ft_printf("L%d-%s ", tmp_a->value, tmp_a->name);
        }
        if (tmp_b != NULL)
        {
          tmp_b->value += 2;
          tmp_b = tmp_b->next;
          ft_printf("L%d-%s ", tmp_b->value, tmp_b->name);
        }
      }
      ft_putchar('\n');
  }*/
}


// integer[2] = integer[1];
// integer[1] = integer[0];
//if (integer[0] > 0)
//    integer[0]--;
/*
int main()
{
    char *tab[4];
    tab[0] = ft_strdup("0");
    tab[1] = ft_strdup("3");
    tab[2] = ft_strdup("1");
//    tab[3] = ft_strdup("0");
    tab[3] = NULL;
    output_print_ants(3, 652, tab);
}
*/
