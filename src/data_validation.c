/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:28:32 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/09 19:07:43 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char *tmp;

	tmp = s1;
	s1 = ft_strjoin(tmp, s2);
	ft_strdel(&tmp);
	return (s1);
}

int ft_check_x_y_ligne(char *line, char **stock_name)
{
	char *remain;

	if (*line == 'L')
		return (-1);
	*stock_name = ft_strjoin_free(*stock_name, ft_strsub(line, 0,\
	ft_index(line, ' ')));
	*stock_name = ft_strjoin_free(*stock_name, " ");
	remain = ft_strchr(line, ' ');
	//ft_printf("name : %s <-> remain : %s\n", name, remain);
	if (ft_is_space_digit_str(remain) == -1)
		return (-1);
	ft_printf("remain : %s\n", remain);
	return (0);
}

int data_validation(void)
{
	char *line;
	char nb_ant_ok;
	char start_ok;
	int end_ok;
	int space;
	char *stock_name;
	// int count_start;
	// int count_end;

	line = NULL;
	space = 0;
	nb_ant_ok = 0;
	start_ok = 0;
	end_ok = 0;
	stock_name = ft_strdup(" ");
	while (get_next_line(0, &line) > 0)
	{
		space = count_space(line);
		// ft_printf("%s >> %d\n", line, space);
		/* Check Ant Number */
		if (ft_isdigitstr(line) == 1 && ft_is_signed_integer(line) == 0\
		&& nb_ant_ok == 0)
		{
			nb_ant_ok = 1;
			ft_printf(L_GREEN"Ants OK\n"RESET);
			ft_strdel(&line);
			//	continue ;
		}
		else if (nb_ant_ok == 1)
		{
			if (*line == '#')
			{
				if (ft_strcmp(line, "##start") == 0)
				{
					start_ok = 1;
					ft_printf(L_GREEN"start OK\n"RESET);
				//	if (get_next_line(0, &line) <= 0)
				//		return (-1);
				}
				if (ft_strcmp(line, "##end") == 0)
				{
					end_ok += 1;
					ft_printf(L_GREEN"end OK\n"RESET);
				//	if (get_next_line(0, &line) <= 0)
				//		return (-1);
				}
			//	ft_strdel(&line);
			//	line = NULL;
			//	continue ;
			}
			else if (space == 0)
			{
				if (ft_strchr(line, '-') != NULL)
				{
					ft_printf(Y_GREEN"Link OK\n"RESET);
				}
			}
			else if (space == 2)
			{
				if (ft_check_x_y_ligne(line, &stock_name) == -1)
					return (-1);
				ft_printf(GREEN"Name - Data OK\n"RESET);
			}
			else
			{
				ft_strdel(&line);
				return (-1);
			}
		}
		else
			return (-1);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	ft_putendl_fd(stock_name, 2);
	ft_strdel(&stock_name);
	return (0);
}
