/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:05:46 by po-conno          #+#    #+#             */
/*   Updated: 2013/11/27 21:11:49 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*s2;

	size = ft_strlen(s1);
	s2 = (char *) malloc(sizeof(*s2) * size + 1);
	if (s2)
	{
		i = 0;
		while (s1[i] != '\0')
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = s1[i];
		return (s2);
	}
	return (0);
}
