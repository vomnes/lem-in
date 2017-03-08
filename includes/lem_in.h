/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:32:28 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/08 18:02:52 by vomnes           ###   ########.fr       */
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
	int				coord_x;
	int				coord_y;
	char			*name;
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

#endif
