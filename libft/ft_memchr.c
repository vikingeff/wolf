/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:24:51 by po-conno          #+#    #+#             */
/*   Updated: 2013/11/27 20:53:41 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	const char		*tmp;

	tmp = s;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == c)
			return ((char *)tmp + i);
		i++;
	}
	return (NULL);
}
