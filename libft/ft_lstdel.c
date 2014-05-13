/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 20:00:52 by po-conno          #+#    #+#             */
/*   Updated: 2013/11/28 23:48:20 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{

	t_list		*tmp;

	if (!alst || !del)
		return ;
	while ((*alst) != NULL)
	{
		tmp = (*alst);
		ft_lstdelone(alst, del);
		(*alst) = (tmp)->next;
	}
}
