/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 12:26:43 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/26 18:07:46 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
        i = len - 3;
        while (i >= 0)
        {
            integer[i + 1] = integer[i];
            i--;
        }
        // integer[2] = integer[1];
        // integer[1] = integer[0];
        //if (integer[0] > 0)
        //    integer[0]--;
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
