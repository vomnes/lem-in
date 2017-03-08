/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:51:10 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/08 18:23:34 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem-in.h"

# define IS_IN_LINE(x) (ft_strstr(line, x) != NULL)
# define IS_LINE(x) (ft_strchmp(line, x) == 0)

static int	ft_isdigitstr(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (-1);
		i++;
	}
	return (1);
}

/*if (ft_isdigitstr(argv[i + 1]) == -1)
{
	ft_putendl_fd("Error", 2);
	return (-1);
}
else if (ft_lltoi(argv[i + 1]) >= 2147483648
|| ft_lltoi(argv[i + 1]) < -2147483648
|| ft_strcmp(argv[i + 1], "-") == 0)
{
	ft_putendl_fd("Error", 2);
	return (-1);
}*/

int ft_get_input(void)
{
	t_data *data;
	t_collect collect;
	char *line;
	int gather;

	gather = 0;
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (IS_IN_LINE("##"))
		{
			if (IS_LINE("##start"))
				collect->statut = START;
			else if (IS_LINE("##end"))
				collect->statut = END;
		}
		else if (IS_IN_LINE("#"))
		{
			ft_putendl("Ok - Comment");
			continue ;
		}
		else if (IS_IN_LINE(" "))
		{
			if (gather == 1)
				return (-1);
		}
		else if (IS_IN_LINE("-"))
		{
			gather = 1;
		}
		ft_putendl(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}
