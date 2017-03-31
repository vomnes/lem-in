/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:32:28 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/31 12:14:53 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

# define BASIC 0
# define END 1
# define START 2

# define ADD_SOLUTION 0
# define ADD_PATH 1

# define ABS(x) (((x >> 31) ^ x) - (x >> 31))

typedef struct				s_validation
{
	char					*line;
	char					nb_ant_ok;
	char					start_ok;
	char					start_flag;
	int						end_ok;
	char					end_flag;
	int						space;
	char					*stock_name;
	char					*stock_coord;
	int						count_room;
}							t_validation;

typedef struct				s_collect
{
	int						coord_x;
	int						coord_y;
	char					*name;
	char					statut;
	char					*name_1;
	char					*name_2;
}							t_collect;

typedef struct				s_link
{
	void					*link_room;
	char					*name;
	char					visited;
	struct s_link			*next;
}							t_link;

typedef struct				s_room
{
	struct s_room			*next;
	char					*name;
	int						x;
	int						y;
	char					state;
	char					visited;
	t_link					*link;
}							t_room;

typedef struct				s_path
{
	struct s_path			*next;
	struct s_path			*previous;
	char					*name;
	int						id_ant;
}							t_path;

typedef struct				s_list_path
{
	struct s_list_path		*next;
	char					*last_link_name;
	t_path					*path;
}							t_list_path;

typedef struct				s_ants
{
	struct s_ants			*next;
	char					*name;
	int						num_ant;
}							t_ants;

typedef struct				s_data
{
	t_list_path				*list_path;
	t_list_path				*solution_path;
	int						nb_ants;
	char					*start;
	char					*end;
}							t_data;

int							check_number(char *line);
int							collect_number(char *line, int *i);
int							ft_isdigitstr(char *str);
int							ft_is_signed_integer(char *str);
int							count_space(char *line);
int							ft_is_space_digit_str(char *str);
int							check_coord_number(char *line);
int							check_name(char **tmp_name, char **name, \
char **stock_name);
char						*ft_strjoin_free(char *s1, char *s2);
int							check_x_y_line(char *line, char **stock_name, \
char **stock_coord);
int							check_link(char *line, char *stock_name);
int							analyse_line(int *ret, t_validation *val);
int							data_validation(int *num_line, t_validation *val, \
char **line_input);
int							implementation_data_val(char ***input_data, \
char print_message);

int							graph_create(char **input_data, t_room **room, \
t_data *data, int i);
int							graph_add_room(t_room **lst_head, \
t_collect *collect);
int							graph_add_link(char *selected_room, char *room, \
t_room **list_room);
void						graph_clean(t_room *lst);
int							graph_get_x_y(char *line, t_collect *collect);

int							path_add(t_data *data, t_path *original, \
char *title, char on_off);
void						path_print(t_list_path *lst);
int							path_algorithm(t_room **rooms, t_data *data, \
char call);
void						path_delete_first_elem(t_list_path **list_path);
void						path_list_delete(t_list_path **lst);
void						path_delete(t_path **path);
void						path_delif_room(t_room **alst, char *data_ref);
void						path_delif_link(t_link **alst, char *data_ref);
float						path_len(t_path *list);

void						output_ants(t_path *path_1, t_path *path_2, \
t_data *data);
void						output_print(t_data *data, char **input_data, \
char print_path);

#endif
