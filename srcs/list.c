/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 21:11:37 by po-conno          #+#    #+#             */
/*   Updated: 2014/01/19 13:34:13 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "wolf3d.h"

int		free_split(char ***tmp)
{
	int		i;

	i = 0;
	if (!tmp || !*tmp)
		return (0);
	while ((*tmp)[i])
	{
		ft_strdel(&(*tmp)[i]);
		i++;
	}
	ft_memdel((void **)tmp);
	return (0);
}

t_lst	*add_to_list(t_lst **list, t_lst *new)
{
	t_lst	*tmp;

	if (!*list)
	{
		new->heigth = 1;
		(*list) = new;
	}
	else
	{
		tmp = (*list);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		(*list)->heigth++;
	}
	return (*list);
}

void	free_list(t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst;
	while (tmp->next != NULL )
	{
		if (tmp != lst)
			lst = tmp;
		ft_strdel(&(tmp->content));
		tmp->width = 0;
		tmp->heigth = 0;
		ft_memdel((void **)&lst);
		tmp = tmp->next;
	}
	ft_strdel(&(tmp->content));
	tmp->width = 0;
	tmp->heigth = 0;
	ft_memdel((void **)&lst);
}

t_lst	*make_list(char **line)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->content = ft_strdup(*line);
	new->width = ft_count_words(new->content, ' ');
	new->heigth = 0;
	new->next = NULL;
	return (new);
}
