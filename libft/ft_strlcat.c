/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:02:23 by po-conno          #+#    #+#             */
/*   Updated: 2013/11/27 21:08:28 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	y;

	i = 0;
	y = 0;
	while (i < size && dst[i] != '\0')
		i++;
	if (dst[i] == '\0' && i < (size - 1))
	{
		while (src[y] != '\0' && (i + y) < size - 1)
		{
			dst[i + y] = src[y];
			y++;
		}
		dst[i + y] = '\0';
		return (i + ft_strlen(src));
	}
	else
		return (i + ft_strlen(src));
}
