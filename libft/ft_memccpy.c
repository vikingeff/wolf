/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:27:10 by po-conno          #+#    #+#             */
/*   Updated: 2013/11/30 19:56:53 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int	i;
	char			*tmp1;
	const char		*tmp2;

	i = 0;
	tmp1 = s1;
	tmp2 = s2;
    while (i < n)
	{
		tmp1[i] = tmp2[i];
		if (tmp2[i] == (unsigned char)c)
			return (tmp1 + (i + 1));
		i++;
	}
	return (NULL);
}
