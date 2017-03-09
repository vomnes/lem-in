/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:32:28 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/09 16:41:14 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

# define BASIC 0
# define END 1
# define START 2

# define ABS(x) (((x >> 31) ^ x) - (x >> 31))

typedef struct		s_data
{
	struct s_data	*next;
	char			*name;
	int				coord_x;
	int				coord_y;
	char 			statut;
}					t_data;

typedef struct 		s_collect
{
	int				coord_x;
	int				coord_y;
	char			*name;
	short 			statut;
}					t_collect;

/*typedef struct 		s_env
{

}					t_env;*/

int check_number(char *line);
int collect_number(char *line, int *i);
int	ft_isdigitstr(char *str);
int ft_is_signed_integer(char *str);
int count_space(char *line);
int	ft_is_space_digit_str(char *str);

int get_input(void);
int data_validation(void);

#endif
