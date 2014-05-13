/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 02:27:04 by po-conno          #+#    #+#             */
/*   Updated: 2013/12/22 04:43:18 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old, size_t n)
{
	void	*new;

	if (!ptr)
		return (NULL);
	if (n == 0)
	{
		new = (void *)ft_memalloc(sizeof(char));
		ft_bzero(new, sizeof(char));
		ft_memcpy(new, ptr, sizeof(char));
	}
	else
		new = (void *)ft_memalloc(n);
	if (!new)
		return (ptr);
	if (old < n)
	{
		ft_bzero(new, n);
		ft_memcpy(new, ptr, old);
		ft_memdel((void **)&ptr);
	}
	else
	{
		ft_bzero(new, n);
		ft_memcpy(new, ptr, n);
		ft_memdel((void **)&ptr);
	}
	return (new);
}
