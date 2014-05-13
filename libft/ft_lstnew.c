/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:12:34 by po-conno          #+#    #+#             */
/*   Updated: 2013/11/30 21:10:01 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	if (tmp)
	{
		if (content == NULL)
		{
			tmp->content = NULL;
			tmp->content_size = 0;
			content_size = 0;
		}
		else
		{
			tmp->content = malloc(content_size);
			if (!tmp->content)
				return (NULL);
			tmp->content_size = content_size;
			ft_memcpy(tmp->content, content, content_size);
		}
		tmp->next = NULL;
	}
	return (tmp);
}
