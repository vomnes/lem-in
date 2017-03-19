/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:32:28 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/19 14:11:40 by vomnes           ###   ########.fr       */
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

typedef struct 		s_validation
{
	char 			*line;
	char 			nb_ant_ok;
	char 			start_ok;
	char 			start_flag;
	int 			end_ok;
	char 			end_flag;
	int 			space;
	char 			*stock_name;
	char 			*stock_coord;
	int 			count_room;
}					t_validation;

typedef struct 		s_collect
{
	int				coord_x;
	int				coord_y;
	char			*name;
	char 			statut;
	char 			*name_1;
	char 			*name_2;
}					t_collect;

typedef struct		s_link
{
	void			*link_room;
	char 			*name;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	struct	s_room	 *next;
	char		     *name;
	int			     x;
	int			     y;
	char		     state;
	char			 visited;
	t_link		     *link;
}					t_room;

/*typedef struct 		s_env
{

}					t_env;*/

int check_number(char *line);
int collect_number(char *line, int *i);
int	ft_isdigitstr(char *str);
int ft_is_signed_integer(char *str);
int count_space(char *line);
int	ft_is_space_digit_str(char *str);

/* Parsing - Data Validation */
char	*ft_strjoin_free(char *s1, char *s2);
int check_x_y_line(char *line, char **stock_name, char **stock_coord);
int check_link(char *line, char *stock_name);
int analyse_line(int *ret, t_validation *val);
int			data_validation(int *num_line, t_validation *val, char **line_input);
int implementation_data_val(char ***input_data);

/* Graph */
int graph_create(char **input_data, t_room **room);
void print_graph(t_room *lst);
void print_link(t_link *lst);
int	graph_add_room(t_room **lst_head, char *room, int x, int y, char state);
int graph_add_link(char *selected_room, char *room, t_room **list_room);

#endif
