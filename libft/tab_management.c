/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 19:29:49 by po-conno          #+#    #+#             */
/*   Updated: 2014/01/04 18:04:32 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		free_tab(char ***tmp)
{
	int			i;

	i = 0;
	if (!tmp || !*tmp)
		return ;
	while ((*tmp)[i])
	{
		ft_strdel(&(*tmp)[i]);
		i++;
	}
	ft_memdel((void **)tmp);
}

char		**copy_tab(char **src, int over, int j)
{
	char		**tmp;
	int			i;

	i = 0;
	while (src[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + j + 1));
	while (j >= 0)
	{
		tmp[i + j] = NULL;
		j--;
	}
	i--;
	while (i >= 0)
	{
		tmp[i] = ft_strdup(src[i]);
		i--;
	}
	if (over)
		free_tab(&src);
	return (tmp);
}
