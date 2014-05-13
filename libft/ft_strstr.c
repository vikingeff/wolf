/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:56:44 by po-conno          #+#    #+#             */
/*   Updated: 2013/12/08 20:03:34 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compstr(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s2[i] == '\0')
		return (0);
	return (s1[i] - s2[i]);
}

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_compstr(s1 + i, s2) == 0)
			return ((char *)s1 + i);
		i++;
	}
	return (0);
}
