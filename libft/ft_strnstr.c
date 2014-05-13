/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:10:22 by po-conno          #+#    #+#             */
/*   Updated: 2013/12/08 20:01:52 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int	ft_compnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (ft_strlen(s2) > n)
		return (1);
	while (i < n && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s2[i] == '\0')
		return (0);
	return (s1[i] - s2[i]);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (ft_strlen(s2) > n)
		return (0);
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		if (ft_compnstr(s1 + i, s2, n - i) == 0)
			return ((char *)&s1[i]);
		i++;
	}
	return (0);
}
