/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 15:35:34 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/31 11:54:30 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	ft_lst_len_lstpath(t_list_path *list)
{
	t_list_path	*temp;
	int			count;

	temp = list;
	count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

void		output_print(t_data *data, char **input_data, char print_path)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	while (input_data[i] != NULL)
		ft_putendl(input_data[i++]);
	ret = ft_lst_len_lstpath(data->solution_path);
	if (ret == 1)
		output_ants((data->solution_path)->path, NULL, data);
	else if (ret == 2)
		output_ants((data->solution_path)->path, \
		(data->solution_path)->next->path, data);
	if (print_path == 1)
		path_print(data->solution_path);
}
