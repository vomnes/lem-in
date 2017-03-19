/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:48:52 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/19 10:59:04 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char *tmp;

	tmp = s1;
	if (!(s1 = ft_strjoin(tmp, s2)))
	{
		ft_strdel(&tmp);
		return (NULL);
	}
	ft_strdel(&tmp);
	return (s1);
}
