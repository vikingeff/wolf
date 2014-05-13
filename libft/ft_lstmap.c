/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 03:51:50 by po-conno          #+#    #+#             */
/*   Updated: 2013/11/30 21:09:41 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*stock;
	t_list	*start;
	t_list	*tmp;

	if (!f || !lst)
		return (NULL);
	stock = f(lst);
	tmp = ft_lstnew(stock->content, stock->content_size);
	if (!tmp)
		return (NULL);
	lst = lst->next;
	start = tmp;
	while (lst != NULL)
	{
		stock = f(lst);
		tmp->next = ft_lstnew(stock->content, stock->content_size);
		if (!tmp->next)
			return (NULL);
		lst = lst->next;
		tmp = tmp->next;
	}
	tmp = start;
	return (tmp);
}
